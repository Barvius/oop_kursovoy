#pragma once
#include "Platform.h"
class PlatformOneOff : public Platform {
private:
	bool Used = false;
public:
	int GetBumpDistance(int);
	void Draw();
	PlatformOneOff();
	PlatformOneOff(Coord, GLuint);
	virtual ~PlatformOneOff();
};

