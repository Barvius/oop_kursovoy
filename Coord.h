#pragma once
struct Coord{
	Coord() {
	}
	Coord(int _x, int _y) {
		x = _x;
		y = _y;
	}
	/*Coord operator = (Coord &obj) {
		return Coord(obj.x, obj.y);
	}*/
	int x;
	int y;
};

