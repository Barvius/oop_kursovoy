#include <GL/glut.h> 
#include <GL/gl.h> 
#include <time.h> 
#include <random> 
#include <iostream>

#include"Handler.h"

using namespace std;

uint32_t last_idle_time; 

#define ANIM_INTERVAL 0.005

void animate() {
	double dt;
	uint32_t time_now = GetTickCount();
	dt = (double)(time_now - last_idle_time) / 1000.0;
	if (dt >= ANIM_INTERVAL) {
		if (Handler::instance()->Calculate()) {
			glutPostRedisplay();
		}
		last_idle_time = time_now;
	}
}

void reshape(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void toggleGlutWindowMaximizeBox(const char *szWindowTitle){
	long dwStyle;
	HWND hwndGlut;
	hwndGlut = FindWindow(NULL, szWindowTitle);
	dwStyle = GetWindowLong(hwndGlut, GWL_STYLE);
	dwStyle ^= WS_MAXIMIZEBOX;
	dwStyle ^= WS_MINIMIZEBOX;
	dwStyle ^= WS_SIZEBOX;
	SetWindowLong(hwndGlut, GWL_STYLE, dwStyle);
}

GLuint LoadTexture(const char * filename, int width, int height)
{
	GLuint texture;
	unsigned char * data;
	FILE * file;
	file = fopen(filename, "rb");
	if (file == NULL) return 0;
	data = (unsigned char *)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);
	unsigned char blue;
	for (int i = 0; i < width * height * 3; i += 3){
		blue = data[i];
		data[i] = data[i + 2];
		data[i + 2] = blue;
	}
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);
	return texture;
}

int main(int argc, char **argv) {
	const char* WindowsTitle = { "Platform Jumper" };
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 600);
	glutCreateWindow(WindowsTitle);
	toggleGlutWindowMaximizeBox(WindowsTitle);
	glutReshapeFunc(reshape);
	glutDisplayFunc([]() mutable {
		Handler::instance()->Render();
		glutSwapBuffers();
	});
	glutKeyboardFunc([](unsigned char key, int a, int b) mutable {
		Handler::instance()->Key(key);
		glutPostRedisplay();
	});
	glutSpecialFunc([](int key, int a, int b) mutable {
		Handler::instance()->Key(key);
		glutPostRedisplay();
	});
	glutIdleFunc(animate);
	Handler::instance()->SetTexture(LoadTexture("texture.GLtex", 256, 256));
	glutMainLoop();
	return 0;
}

