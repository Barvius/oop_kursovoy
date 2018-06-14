#include "Handler.h"

bool Handler::Calculate() {
	if (_Game) {
		if (!G.Calculate()) {
			_Game = false;
			//_Menu_active = true;
		}
		return true;
	}
	return false;
}

void Handler::Render() {

	if (_Menu_active) {
		M.Draw();
		cout << G.GetScore() << endl;
	}
	if (_Game) {
		glEnable(GL_TEXTURE_2D);
		G.Render();
		glDisable(GL_TEXTURE_2D);
	}
	if (!_Menu_active && !_Game) {
		glClearColor(0.04, 0.5, 0.24, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		char score[20];
		glColor3f(0.93f, 0.89f, 0.05f);
		glRasterPos2f(180, 250);
		sprintf(score, "Score: %d", G.GetScore());
		for (int j = 0; j < strlen(score); j++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[j]);
		}
		
	}
	

}

void Handler::Key(int key) {
	if (_Menu_active) {
		switch (key) {
		case GLUT_KEY_UP:
			M.Up();
			break;
		case GLUT_KEY_DOWN:
			M.Down();
			break;
		case 13:
			cout << "Selected " << M.Enter() << endl;
			switch (M.Enter()) {
			case 1:
				_Menu_active = false;
				_Game = true;
				G.New();
				break;
			case 3:
				exit(0);
				break;
			default:
				break;
			}
			//game.MoveRight();
			break;
		}
		//glutPostRedisplay();
	}
	if (_Game) {
		switch (key) {
		case GLUT_KEY_LEFT:
			G.MoveLeft();
			break;
		case GLUT_KEY_RIGHT:
			G.MoveRight();
			break;
		}
	}
	if (!_Menu_active && !_Game) {
		switch (key) {
		case 13:
			_Menu_active = true;
			break;
		}

	}
}

void Handler::SetTexture(GLuint t) {
	Texture = t;
		G = Game(Texture);
		M = Menu(200,300);
		M.AddIthems("Start game");
		M.AddIthems("About");
		M.AddIthems("Exit");
}

Handler* Handler::p_instance = 0;

Handler* Handler::instance() {
	if (p_instance == 0)
		p_instance = new Handler;
	return p_instance;
}

Handler::Handler()
{
}

Handler::Handler(GLuint t)
{
	Texture = t;
	G = Game(Texture);
	M = Menu(200,300);
	M.AddIthems("Start game");
	M.AddIthems("About");
	M.AddIthems("Exit");
}

Handler::~Handler()
{
}
