#pragma once
#include "Interface.h"
#include "WordIn.h"



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
    switch (wybor) // ustawia nastepny na podstawie poprzedniego
    {
    case '1':
        Menu.gotoxy(13, 15);
        putchar(menuIndicator);
        break;
    case '2':
        Menu.gotoxy(13, 16);
        putchar(menuIndicator);
        break;
    case '3':
        Menu.gotoxy(13, 17);
        putchar(menuIndicator);
        break;
    case '4':
        Menu.gotoxy(13, 18);
        putchar(menuIndicator);
        break;
    case '5':
        Menu.gotoxy(13, 19);
        putchar(menuIndicator);
        break;
    case '6':
        Menu.gotoxy(13, 20);
        break;
    }
    wybor--;
    if (wybor < '1') // zamienia zmienna wyboru
        wybor = '6';
}

void Interface::down()
{
    Menu Menu;
    putchar(8);
    putchar(32);
    switch (wybor)
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
    wybor++;
    if (wybor > '6')
    {
        wybor = '1';
    }
}

char Interface::enterHit()
{
    printF();
    return wybor;
}

void Interface::drawFrameAddWord()
{
    Menu Menu;
    drawFrame();
    Menu.gotoxy(2, 3);
    cout << "slowo: \n";
    Menu.gotoxy(2, 6);
    cout << "wpisz slowo \n";
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

void Interface::printF()
{
    string nameBase,nameBaseCp;
    WordIn WordIn;
    Menu menu;
    COORD c;
    c = menu.getpos();
    switch(c.Y)
    {
    case 14:
        system("CLS");
        cout << "podaj nazwe bazy: \n";
        cin >> nameBase;
        nameBaseCp = nameBase + "Copy";
        nameBase += ".txt";
        nameBaseCp += ".txt";
        WordIn.CreateFileBase(nameBase);
        WordIn.CreateFileBase(nameBaseCp);
        system("CLS");
        system("PAUSE");
        break;
    case 15:
        system("CLS");
        cout << "podaj nazwe bazy: \n";
        cin >> nameBase;
        nameBase += ".txt";
        system("cls");
        WordIn.Write(nameBase);        
        break;
    case 16:
        system("CLS");
        cout << "podaj nazwe bazy: \n";
        cin >> nameBase;
        nameBase += ".txt";
        WordIn.PrintFile(nameBase);
        system("PAUSE");
        system("CLS");
        break;
    case 17:
        system("CLS");
        cout << "podaj nazwe bazy: \n";
        cin >> nameBase;
        nameBaseCp = nameBase + "Copy";
        nameBase += ".txt";
        nameBaseCp += ".txt";
        WordIn.CheckFile(nameBaseCp,nameBase);
        system("PAUSE");
        system("CLS");
        break;
    case 18:
        system("CLS");
        cout << "podaj nazwę bazy: \n";
        cin >> nameBase;
        nameBaseCp = nameBase + "Copy";
        nameBaseCp += ".txt";
        WordIn.RepeatIt(nameBaseCp);
        system("PAUSE");
        break;
    case 19:
        wybor = '6';
        break;
    }
}