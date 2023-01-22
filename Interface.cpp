#pragma once
#include "Interface.h"
#include "WordIn.h"

Interface::Interface(char& wzor)
{
    choiceCp = wzor;
}

void Interface::drawFrame()
{
    Menu Menu;
    Menu.changeColor(7);
    int i;
    Menu.gotoxy(0, 0);
    cout << char(201);
    for (i = 0; i < 78; i++)
    {
        cout << char(205);
    }
    cout << char(187);
    for (i = 2; i < 26; i++)
    {
        Menu.gotoxy(1, i);
        if (i == 25) cout << char(200);
        else cout << char(186);
    }


    for (i = 0; i < 78; i++)
    {
        cout << char(205);
    }
    cout << char(188);
    for (i = 2; i < 25; i++)
    {
        Menu.gotoxy(80, i);
        cout << char(186);
    }


}

void Interface::up()
{
    Menu Menu;
    putchar(8);
    putchar(32); // kasuje poprzedni znacznik wyboru
    switch (choiceCp) // ustawia nastepny na podstawie poprzedniego
    {
    case '1':
        Menu.gotoxy(13, 20);
        putchar(menuIndicator);
        break;
    case '2':
        Menu.gotoxy(13, 15);
        putchar(menuIndicator);
        break;
    case '3':
        Menu.gotoxy(13, 16);
        putchar(menuIndicator);
        break;
    case '4':
        Menu.gotoxy(13, 17);
        putchar(menuIndicator);
        break;
    case '5':
        Menu.gotoxy(13, 18);
        putchar(menuIndicator);
        break;
    case '6':
        Menu.gotoxy(13, 19);
        putchar(menuIndicator);
        break;
    }
    choiceCp--;
    if (choiceCp < '1')
    {
        choiceCp = '6';
    }
}

void Interface::down()
{
    Menu Menu;
    putchar(8);
    putchar(32);
    switch (choiceCp)
    {
    case '1':
        Menu.gotoxy(13, 16);
        putchar(menuIndicator);
        break;
    case '2':
        Menu.gotoxy(13, 17);
        putchar(menuIndicator);
        break;
    case '3':
        Menu.gotoxy(13, 18);
        putchar(menuIndicator);
        break;
    case '4':
        Menu.gotoxy(13, 19);
        putchar(menuIndicator);
        break;
    case '5':
        Menu.gotoxy(13, 20);
        putchar(menuIndicator);
        break;
    case '6':
        Menu.gotoxy(13, 15);
        putchar(menuIndicator);
        break;
    }
    choiceCp++;
    if (choiceCp > '6')
    {
        choiceCp = '1';
    }
}

char Interface::enterHit()
{
    return choiceCp;
}

void Interface::drawFrameAddWord()
{
    Menu Menu;
    drawFrame();
    Menu.gotoxy(2, 3);
    cout << "fraza: \n";
    Menu.gotoxy(2, 6);
    cout << "wpisz fraze \n";
 }

void Interface::drawFrameLearn()
{
    Menu Menu;
    drawFrame();
    Menu.gotoxy(2, 3);
    cout << "fraza: \n";  
    Menu.gotoxy(2, 9);
    cout << "wpisz przetlumaczona fraze: \n";
}
