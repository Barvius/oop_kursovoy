#include "PlatformArrangement.h"


Platform* PlatformArrangement::New(Coord coord,GLuint texture) {
	switch (this->Gen()) {
	case 1:
		return new PlatformBasic(coord, texture);
		break;
	case 2:
		return new PlatformToss(coord, texture);
		break;
	case 3:
		return new PlatformOneOff(coord, texture);
		break;
	case 4:
		return new PlatformMoving(coord, texture);
		break;
	default:
		break;
	}
}

int PlatformArrangement::GetX() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(35, 330);
	return dis(gen);
}

int PlatformArrangement::GetY() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 530);
	return dis(gen);
}

int PlatformArrangement::Gen() {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0, 1);
	float val = dis(gen);
	int ReturnValue = 1;
	//cout << val << endl;
	for (int i = 0; i < N; i++) {
		if (ORT[i] >= val) {
			return i + 1;
		}
	}
	//cout << ReturnValue << endl;
	return 1;
}

PlatformArrangement::PlatformArrangement(){
	float val = 0;
	for (int i = 0; i < N; i++) {
		val += MV[i];
		ORT[i] = val;
	}
}

PlatformArrangement::~PlatformArrangement()
{
}
