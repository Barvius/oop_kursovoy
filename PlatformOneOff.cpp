#include "PlatformOneOff.h"

int PlatformOneOff::GetBumpDistance(int val) {
	if (Used) {
		return -val;
	}
	Used = true;
	return BumpDistance;
}

void PlatformOneOff::Draw() {
	if (!Used) {
		glBindTexture(GL_TEXTURE_2D, Texture);
		glBegin(GL_QUADS);
		glTexCoord2d(0.1, 0.765); glVertex2d(Position.x - SizeX, Position.y - SizeY);
		glTexCoord2d(0.1, 0.848); glVertex2d(Position.x - SizeX, Position.y + SizeY);
		glTexCoord2d(0.51, 0.848); glVertex2d(Position.x + SizeX, Position.y + SizeY);
		glTexCoord2d(0.51, 0.765); glVertex2d(Position.x + SizeX, Position.y - SizeY);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

PlatformOneOff::PlatformOneOff() {
}

PlatformOneOff::PlatformOneOff(Coord _Position, GLuint _Texture) {
	Position = _Position;
	Texture = _Texture;
}

PlatformOneOff::~PlatformOneOff(){
}
