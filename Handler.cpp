#include "Handler.h"

bool Handler::Calculate() {
	if (_State == GAME) {
		if (!_G.Calculate()) {
			_State = GAME_END;
		}
		return true;
	}
	return false;
}

void Handler::Render() {
	glClearColor(0.04, 0.5, 0.24, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static auto PrintChar = [](const char* t) mutable {
		for (int i = 0; i < strlen(t); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
		}
	};
	switch (_State){
	case Handler::MAIN_MENU:
		_M.Draw();
		break;
	case Handler::MENU_AUTHOR:
		glRasterPos2f(200 - 22 * 9 / 2, 320);
		PrintChar("sozdal student gruppy");
		glRasterPos2f(200 - 6 * 9 / 2, 300);
		PrintChar("IS-16");
		glRasterPos2f(200 - 19 * 9 / 2, 280);
		PrintChar("Barabanshikov Oleg");
		break;
	case Handler::GAME:
		glEnable(GL_TEXTURE_2D);
		_G.Render();
		glDisable(GL_TEXTURE_2D);
		break;
	case Handler::GAME_END:
		char score[25];
		glColor3f(0.93f, 0.89f, 0.05f);
		sprintf(score, "Score: %d", _G.GetScore());
		glRasterPos2f(200 - strlen(score) * 9 / 2, 300);
		PrintChar(score);
		break;
	default:
		break;
	}
}

void Handler::Key(int key) {
	switch (_State) {
	case Handler::MAIN_MENU:
		switch (key) {
		case GLUT_KEY_UP:
			_M.Up();
			break;
		case GLUT_KEY_DOWN:
			_M.Down();
			break;
		case 13:
			switch (_M.Enter()) {
			case 1:
				_State = GAME;
				_G.New();
				break;
			case 2:
				_State = MENU_AUTHOR;
				break;
			case 3:
				exit(0);
				break;

			default:
				break;
			}
			break;
		}
		break;
	case Handler::MENU_AUTHOR:
		switch (key) {
		case 13:
			_State = MAIN_MENU;
			break;
		}
		break;
	case Handler::GAME:
		switch (key) {
		case GLUT_KEY_LEFT:
			_G.MoveLeft();
			break;
		case GLUT_KEY_RIGHT:
			_G.MoveRight();
			break;
		}
		break;
	case Handler::GAME_END:
		switch (key) {
		case 13:
			_State = MAIN_MENU;
			break;
		}
		break;
	default:
		break;
	}
}

void Handler::SetTexture(GLuint t) {
	_Texture = t;
	_G = Game(_Texture);
	_M = Menu(200,300);
	_M.AddIthems("Start game");
	_M.AddIthems("About");
	_M.AddIthems("Exit");
}

Handler* Handler::_p_instance = 0;

Handler* Handler::instance() {
	if (_p_instance == 0)
		_p_instance = new Handler;
	return _p_instance;
}

Handler::Handler() {
}

Handler::Handler(const Handler&) {
}

Handler::~Handler() {
}