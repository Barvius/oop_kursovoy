#pragma once
#include "Game.h"
#include"Menu.h"

class Handler{
private:
	static Handler* p_instance;
	Handler();
	Handler(GLuint);
	~Handler();

	bool _Menu_active = true;
	bool _Game = false;
	Game G;
	Menu M;
	GLuint Texture;
public:
	bool Calculate();
	void Render();
	void Key(int);
	void SetTexture(GLuint);
	static Handler* instance();
	

};

