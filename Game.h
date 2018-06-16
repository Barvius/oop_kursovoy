#pragma once
#include <iostream>
#include <random>

#include "Person.h"
#include "Platform.h"
#include "PlatformBasic.h"
#include "PlatformToss.h"
#include "PlatformOneOff.h"
#include "PlatformMoving.h"

#include "PlatformArrangement.h"

#include "Menu.h"

#define N_PLATFORM 12

class Game {
private:
	Platform *_Platform[N_PLATFORM];
	Person _Person;
	PlatformArrangement _PA;
	GLuint _Texture;
	bool _End = false;
	int _Score = 0;
public:
	int GetScore();
	void New();
	void MoveRight();
	void MoveLeft();
	void Render();
	bool Calculate();
	Game(GLuint);
	Game();
	~Game();
};

