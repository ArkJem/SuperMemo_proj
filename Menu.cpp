#include "Menu.h"
using namespace std;

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void Menu::gotoxy(int x, int y)
{
    
    pos.X = x - 1;
    pos.Y = y - 1;
    SetConsoleCursorPosition(hConsole, pos); // kontrola kursora
}

void Menu::changeColor(int color)
{
    SetConsoleTextAttribute(hConsole, color);
}

void Menu::printSuperMemoCopy()
{
    changeColor(1);
    unsigned char C = 111;
    gotoxy(18, 5);
    cout << " " << C << C << " " << C << " " << C << " " << C << C << " " << " " << C << C << C << " " << C << C << " " << " " << C << " " << " " << " " << C << " " << C << C << C << " " << C << " " << " " << " " << C << " " << " " << C << C << " ";
    gotoxy(18, 6);
    cout << C << " " << " " << " " << C << " " << C << " " << C << " " << C << " " << C << " " << " " << " " << C << " " << C << " " << C << C << " " << C << C << " " << C << " " << " " << " " << C << C << " " << C << C << " " << C << " " << " " << C;
    gotoxy(18, 7);
    cout << C << C << " " << " " << C << " " << C << " " << C << " " << C << " " << C << " " << " " << " " << C << " " << C << " " << C << " " << C << " " << C << " " << C << " " << " " << " " << C << " " << C << " " << C << " " << C << " " << " " << C;
    gotoxy(18, 8);
    cout << " " << C << C << " " << C << " " << C << " " << C << C << " " << " " << C << C << C << " " << C << C << " " << " " << C << " " << " " << " " << C << " " << C << C << C << " " << C << " " << " " << " " << C << " " << C << " " << " " << C;
    gotoxy(18, 9);
    cout << " " << " " << C << " " << C << " " << C << " " << C << " " << " " << " " << C << " " << " " << " " << C << " " << C << " " << C << " " << " " << " " << C << " " << C << " " << " " << " " << C << " " << " " << " " << C << " " << C << " " << " " << C;
    gotoxy(18, 10);
    cout << C << C << " " << " " << " " << C << " " << " " << C << " " << " " << " " << C << C << C << " " << C << " " << C << " " << C << " " << " " << " " << C << " " << C << C << C << " " << C << " " << " " << " " << C << " " << " " << C << C << " ";
    changeColor(1);
}



void Menu::drawMenu(char ch)
{   
    changeColor(6);
    printSuperMemoCopy();
    gotoxy(15, 15);
    cout << "Stworz nowa baze slow";
    gotoxy(15, 16);
    cout << "Dodaj slowa do bazy";
    gotoxy(15, 17);
    cout << "Wyswietl wybrana baze";
    gotoxy(15, 18);
    cout << "Tryb oceny";
    gotoxy(15, 19);
    cout << "Tryb powtorki";
    gotoxy(15, 20);
    cout << "Wyjscie";
switch (ch)
{
case '1':
    gotoxy(13, 15);
    putchar(menuIndicator);
    break;
case '2':
    gotoxy(13, 16);
    putchar(menuIndicator);
    break;
case '3':
    gotoxy(13, 17);
    putchar(menuIndicator);
    break;
case '4':
    gotoxy(13, 18);
    putchar(menuIndicator);
    break;
case '5':
    gotoxy(13, 19);
    putchar(menuIndicator);
    break;
case '6':
    gotoxy(13, 20);
    putchar(menuIndicator);
    break;
}
}

