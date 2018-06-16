#pragma once
#include <GL/glut.h>
#include<cmath>
#include "Coord.h"

class Person{
private:
	Coord Position;
	int Size = 30;
	GLuint Texture;
	bool lookLeft = false;
	bool lookRight = true;
public:
	int GetSize();
	void LookLeft();
	void LookRight();
	void MovePositionX(int);
	void SetPositionX(int);
	void SetPositionY(int);
	Coord GetPosition();
	void Draw();
	Person();
	Person(Coord,GLuint);
	~Person();
};

