#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Folder.h"
#include "Menu.h"



#define KEYLEFT 75
#define KEYRIGHT 77
#define KEYUP 72
#define KEYDOWN 80
#define KEYENTER '\r'
#define KEYESCAPE 27

using namespace std;


class Interface
{
public:
	char wybor = '1';
	void printF();
	void drawFrame();
	void drawFrameAddWord();
	void up();
	void down();
	char enterHit();
	const unsigned char menuIndicator = 62; // ustawia znak wskaznika menu
};