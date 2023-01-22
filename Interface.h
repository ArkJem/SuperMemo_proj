#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Folder.h"
#include "Menu.h"
#include <vector>

#define KEYUP 72
#define KEYDOWN 80
#define KEYENTER '\r'
#define KEYESCAPE 27

using namespace std;


class Interface
{
private:
	char choiceCp;
public:
	Interface(char& wzor);
	void drawFrame();
	void drawFrameAddWord();
	void up();
	void down();
	char enterHit();
	void drawFrameLearn();
	const unsigned char menuIndicator = 62; // ustawia znak wskaznika menu
	vector<string> lines;
};