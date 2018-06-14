#pragma once
#include <GL/glut.h> 
#include<vector>
#include"MenuIthems.h"

class Menu {
private:
	std::vector<MenuIthems> Ithems;
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
public:
	void Up();
	void Down();
	int Enter();
	void Draw();
	void AddIthems(char*);
	Menu();
	Menu(int, int);
	~Menu();
};

