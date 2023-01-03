#pragma once
#include "Interface.h"


class Menu
{
public:
	COORD getpos();
	void drawMenu(char ch);
	void gotoxy(int x, int y);
	void changeColor(int color);
	void printSuperMemoCopy();
	const unsigned char menuIndicator = 62; // ustawia znak wskaznika menu
	
};

