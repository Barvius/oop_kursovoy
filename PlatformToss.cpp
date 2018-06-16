#include "PlatformToss.h"

void PlatformToss::Draw() {
	glBindTexture(GL_TEXTURE_2D, Texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0.1, 0.64); glVertex2d(Position.x - SizeX, Position.y - SizeY);
	glTexCoord2d(0.1, 0.725); glVertex2d(Position.x - SizeX, Position.y + SizeY);
	glTexCoord2d(0.51, 0.725); glVertex2d(Position.x + SizeX, Position.y + SizeY);
	glTexCoord2d(0.51, 0.64); glVertex2d(Position.x + SizeX, Position.y - SizeY);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

PlatformToss::PlatformToss() {
}

PlatformToss::PlatformToss(Coord _Position, GLuint _Texture) {
	Position = _Position;
	Texture = _Texture;
	BumpDistance = 15;
}

PlatformToss::~PlatformToss() {
}
