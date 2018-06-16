#include "MenuIthems.h"

void MenuIthems::SetY(int _y) {
	y = _y;
}

int MenuIthems::GetH() {
	return h;
}

void MenuIthems::Draw() {
	if (active) {
		glColor3fv(text_color_active);
	}
	else {
		glColor3fv(text_color);
	}
	glRasterPos2i(x-strlen(text)*9/2, y-h/2-9/2);
	for (int j = 0; j < strlen(text); j++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[j]);	
	}
}

bool MenuIthems::GetStatus() {
	return active;
}

void MenuIthems::Active() {
	active = true;
}

void MenuIthems::NotActive() {
	active = false;
}

MenuIthems::MenuIthems() {
}

MenuIthems::MenuIthems(int _x, int _y, char* _text){
	x = _x;
	y = _y;
	if (text != nullptr) {
		delete[] text;
	}
	text = new char[strlen(_text) + 1];
	memcpy(text, _text, strlen(_text)+1);
}

MenuIthems::MenuIthems(const MenuIthems& obj) {
	x = obj.x;
	y = obj.y;
	text = new char[strlen(obj.text) + 1];
	memcpy(text, obj.text, strlen(obj.text) + 1);
	active = obj.active;
	
}

MenuIthems::~MenuIthems(){
	if (text != nullptr) {
		delete[] text;
	}
}
