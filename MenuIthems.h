#pragma once
#include <GL/glut.h> 

class MenuIthems {
private:
	int x = 0;
	int y = 0;
	int w = 90;
	int h = 30;
	char* text = nullptr;
	bool active = false;
	GLfloat text_color[3] = {0.89f, 0.85f, 0.78f};
	GLfloat text_color_active[3] = { 0.93f, 0.89f, 0.05f };
public:
	void SetY(int);
	int GetH();
	void Draw();
	bool GetStatus();
	void Active();
	void NotActive();
	MenuIthems();
	MenuIthems(int x, int y, char*);
	MenuIthems(const MenuIthems&);
	~MenuIthems();
};

