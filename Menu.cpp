#include "Menu.h"

void Menu::Up() {
	for (size_t i = 0; i < Ithems.size(); i++) {
		if (Ithems[i].GetStatus()) {
			Ithems[i].NotActive();
			if (i > 0) {
				Ithems[i - 1].Active();
			}
			else {
				Ithems[Ithems.size() - 1].Active();
			}
			break;
		}
	}
}

void Menu::Down() {
	for (size_t i = 0; i < Ithems.size(); i++) {
		if (Ithems[i].GetStatus()) {
			Ithems[i].NotActive();
			if (i < Ithems.size()-1) {
				Ithems[i + 1].Active();
			}
			else {
				Ithems[0].Active();
			}
			break;
		}
	}
}

int Menu::Enter() {
	for (size_t i = 0; i < Ithems.size(); i++) {
		if (Ithems[i].GetStatus()) {
			return i + 1;
		}
	}
	return 1;
}

void Menu::Draw() {
	glClearColor(0.04, 0.5, 0.24, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (size_t i = 0; i < Ithems.size(); i++) {
		Ithems[i].Draw();
	}
}

void Menu::AddIthems(char* text) {
	Ithems.push_back(MenuIthems(x,y,text));
	h = Ithems.size() * (Ithems[0].GetH() + 10);
	Ithems[0].Active();
	int _h = y + h / 2;
	for (size_t i = 0; i < Ithems.size(); i++) {
		Ithems[i].SetY(_h);
		_h -= Ithems[i].GetH() + 10;
	}
}

Menu::Menu(int _x, int _y) {
	x = _x;
	y = _y;
}

Menu::Menu() {
}

Menu::~Menu() {
}
