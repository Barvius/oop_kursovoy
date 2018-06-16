#include "Person.h"

void Person::LookLeft() {
	lookLeft = true;
	lookRight = false;
}

void Person::LookRight() {
	lookRight = true;
	lookLeft = false;
}

void Person::MovePositionX(int tmp) { 
	Position.x += tmp; 
}

void Person::SetPositionX(int tmp) { 
	Position.x = tmp; 
}

void Person::SetPositionY(int tmp) { 
	Position.y = tmp; 
}

Coord Person::GetPosition() { 
	return Position; 
}

int Person::GetSize() {
	return Size;
}

void Person::Draw() {
	glBindTexture(GL_TEXTURE_2D, Texture);
	glBegin(GL_POLYGON);
	float angle;
	for (int i = 0; i < 360; i++) {
		angle = 2.0 * 3.1415926 * float(i) / float(360);
		if (lookLeft) {
			glTexCoord2d(0.815 - 0.2425 * cosf(angle), 0.74 - 0.2425 * sinf(angle));
			glVertex2f(Position.x + Size * cosf(angle), Position.y - Size * sinf(angle));
		}
		if (lookRight) {
			glTexCoord2d(0.815 + 0.2425 * cosf(angle), 0.74 + 0.2425 * sinf(angle));
			glVertex2f(Position.x + Size * cosf(angle), Position.y + Size * sinf(angle));
		}
	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

Person::Person(){
}

Person::Person(Coord _Position, GLuint _Texture){
	Position = _Position;
	Texture = _Texture;
}

Person::~Person(){
}
