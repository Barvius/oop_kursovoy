#include "PlatformMoving.h"


void PlatformMoving::Draw() {
	if (Direction == 1) {
		Position.x++;
	}
	if (Direction == -1) {
		Position.x--;
	}
	if (Position.x < SizeX*2) {
		Direction = 1;
	}
	if (Position.x > 400 - SizeX * 2) {
		Direction = -1;
	}
	glBindTexture(GL_TEXTURE_2D, Texture);

	//glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	glTexCoord2d(0.1, 0.517); glVertex2d(Position.x - SizeX, Position.y - SizeY);
	glTexCoord2d(0.1, 0.6); glVertex2d(Position.x - SizeX, Position.y + SizeY);
	glTexCoord2d(0.51, 0.6); glVertex2d(Position.x + SizeX, Position.y + SizeY);
	glTexCoord2d(0.51, 0.517); glVertex2d(Position.x + SizeX, Position.y - SizeY);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//glDisable(GL_TEXTURE_2D);


}


PlatformMoving::PlatformMoving()
{
}

PlatformMoving::PlatformMoving(Coord _Position, GLuint _Texture){
	Position = _Position;
	Texture = _Texture;
	BumpDistance = 8;
}

PlatformMoving::~PlatformMoving()
{
}
