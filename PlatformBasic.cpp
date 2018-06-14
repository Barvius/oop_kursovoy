#include "PlatformBasic.h"


void PlatformBasic::Draw(){
	
	
	glBindTexture(GL_TEXTURE_2D, Texture);

	//glEnable(GL_TEXTURE_2D);
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(0.1, 0.883); glVertex2d(Position.x - SizeX, Position.y - SizeY);
	glTexCoord2d(0.1, 0.97); glVertex2d(Position.x - SizeX, Position.y + SizeY);
	glTexCoord2d(0.51, 0.97); glVertex2d(Position.x + SizeX, Position.y + SizeY);
	glTexCoord2d(0.51, 0.883); glVertex2d(Position.x + SizeX, Position.y - SizeY);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//glDisable(GL_TEXTURE_2D);

}

PlatformBasic::PlatformBasic(){
}

PlatformBasic::PlatformBasic(Coord _Position, GLuint _Texture){
	Position = _Position;
	Texture = _Texture;
	BumpDistance = 8;
}


PlatformBasic::~PlatformBasic(){
}
