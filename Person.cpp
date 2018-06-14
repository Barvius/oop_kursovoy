#include "Person.h"
#include<cmath>

int Person::GetSize() {
	return Size;
}


void Person::Draw() {
	
	glBindTexture(GL_TEXTURE_2D, Texture);
	//glEnable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	float r2 = 0.2425;
	float angle;
		
	for (int i = 0; i < 360; i++) {
		angle = 2.0 * 3.1415926 * float(i) / float(360);

		if (lookLeft) {
			glTexCoord2d(0.815 - r2 * cosf(angle), 0.74 - r2 * sinf(angle));
			glVertex2f(Position.x + Size * cosf(angle), Position.y - Size * sinf(angle));
		}
		if (lookRight) {
			glTexCoord2d(0.815 + r2 * cosf(angle), 0.74 + r2 * sinf(angle));
			glVertex2f(Position.x + Size * cosf(angle), Position.y + Size * sinf(angle));
		}

	}

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//glDisable(GL_TEXTURE_2D);
}

Person::Person(){
}

Person::Person(Coord _Position, GLuint _Texture){
	Position = _Position;
	Texture = _Texture;
}


Person::~Person()
{
}
