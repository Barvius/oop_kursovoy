#pragma once
#include <iostream>
#include <random>
#include "Platform.h"
#include "PlatformBasic.h"
#include "PlatformToss.h"
#include "PlatformOneOff.h"
#include "PlatformMoving.h"

class PlatformArrangement {
private:
	int N=4;
	float MV[4] = { 0.75f, 0.1f, 0.1f, 0.05f };
	float ORT[4];
	int Gen();
public:
	Platform* New(Coord,GLuint);
	int GetX();
	PlatformArrangement();
	~PlatformArrangement();
};

