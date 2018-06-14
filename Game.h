#pragma once
#include "Person.h"
#include "Platform.h"
#include "PlatformBasic.h"
#include "PlatformToss.h"
#include "PlatformOneOff.h"
#include "PlatformMoving.h"

#include "PlatformArrangement.h"

#include "Menu.h"

#include <iostream>
#include <random>

using namespace std;

#define N 12

class Game {
private:
	Platform *_Platform[N];
	Person _Person;
	PlatformArrangement _PA;
	GLuint _Texture;
	bool _End = false;
	int _Score = 0;
	//Coord LastPlatform;
	//void PlatformSet(Platform);
public:
	int GetScore();
	void New();
	void End();
	void MoveRight();
	void MoveLeft();
	void Render();
	bool Calculate();
	//void MoveY(int);
	Game(GLuint);
	Game();
	~Game();
};

