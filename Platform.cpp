#include "Platform.h"

bool Platform::InPlatform(Person& p) {
	if ((p.GetPosition().x + p.GetSize() >= Position.x - SizeX &&
		p.GetPosition().x - p.GetSize() <= Position.x + SizeX) &&
		(p.GetPosition().y >= Position.y - SizeY &&
			p.GetPosition().y - p.GetSize() <= Position.y + SizeY)) {
		return true;
	}
	return false;
}

int Platform::GetBumpDistance(int val) {
	return BumpDistance;
}

Platform::Platform(){
	Position.x = 0;
	Position.y = 0;
}

Platform::Platform(Coord _Position, GLuint _Texture) {
	Position = _Position;
	Texture = _Texture;
}

Platform::~Platform()
{
}
