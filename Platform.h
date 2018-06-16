#pragma once
#include "Coord.h"
#include "Person.h"

class Platform{
protected:
	Coord Position;
	int SizeX = 34;
	int SizeY = 7;
	int BumpDistance = 8;
	GLuint Texture;
public:
	bool InPlatform(Person&);
	virtual int GetBumpDistance(int);
	void MovePositionY(int);
	Coord GetPosition();
	virtual void Draw() = 0;
	Platform();
	Platform(Coord, GLuint);
	virtual ~Platform();
};

