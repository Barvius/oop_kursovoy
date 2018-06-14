#include "Menu.h"

void Menu::Up() {
	
	for (size_t i = 0; i < Ithems.size(); i++) {
		//std::cout << Ithems[i].GetStatus() << std::endl;
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
	//glDisable(GL_TEXTURE);
	glClearColor(0.04, 0.5, 0.24, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//std::cout << Ithems.size();
	/*glColor3f(0.0f, 0.8f, 0.5f);
	glBegin(GL_QUADS);
	glVertex2d(10, 10);
	glVertex2d(10, 520);
	glVertex2d(390, 520);
	glVertex2d(390, 10);
	glEnd();*/
	
	for (size_t i = 0; i < Ithems.size(); i++) {
		Ithems[i].Draw();
	}
	//glEnable(GL_TEXTURE);
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
	
	//std::cout << Ithems.size() << std::endl;
}

Menu::Menu(int _x, int _y) {
	x = _x;
	y = _y;
	//std::cout << "new C" << std::endl;
}

Menu::Menu() {
	//std::cout << "new" << std::endl;
}


Menu::~Menu() {
}
