#pragma once
#include "Game.h"
#include"Menu.h"

class Handler{
private:
	enum State { MAIN_MENU, MENU_AUTHOR, GAME, GAME_END };
	State _State = MAIN_MENU;
	Game _G;
	Menu _M;
	GLuint _Texture;
	static Handler* _p_instance;
	Handler();
	Handler(const Handler&);
	~Handler();
public:
	bool Calculate();
	void Render();
	void Key(int);
	void SetTexture(GLuint);
	static Handler* instance();
};

