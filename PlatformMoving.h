#pragma once
#include "Platform.h"
class PlatformMoving : public Platform {
private:
	int Direction = 1;
public:
	void Draw(); 
	PlatformMoving();
	PlatformMoving(Coord, GLuint);
	virtual ~PlatformMoving();
};

