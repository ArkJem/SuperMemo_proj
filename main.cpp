// supermemo.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include "WordIn.h"
#include <iostream>
#include <fstream>
#include "Interface.h"
#include "Menu.h"
#include <windows.h>
#include <conio.h>
#include "Folder.h"
#include <shlwapi.h>
#include <limits>
#include <istream>
#include <algorithm>



string WordIn::removeExtraWhiteSpaces(string s)
{
    string result;
    bool last_was_whitespace = false;
    for (char c : s) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (!last_was_whitespace) {
                result += c;
            }
            last_was_whitespace = true;
        }
        else {
            result += c;
            last_was_whitespace = false;
        }
    }
    return result;
}

void WordIn::Write(string nameBase)
{
    ifstream file(path + nameBase);
    if (file.good())
    {
        Menu menu;
        Interface Interface;
        int escKey = 1;
        if (escKey != KEYESCAPE)
        {
            string tmp;
            getline(cin, tmp);
            while (escKey != KEYESCAPE)
            {
                system("cls");
                Interface.drawFrameAddWord();
                menu.gotoxy(2, 4);
                getline(cin, word);
                word = removeExtraWhiteSpaces(word);
                menu.gotoxy(2, 7);
                getline(cin, anotherWord);
                anotherWord = removeExtraWhiteSpaces(anotherWord);
                AddIn(nameBase, word, anotherWord);
                menu.gotoxy(2, 8);
                cout << "wcisnij enter aby dodac kolejne slowo lub klawisz ESC zeby wyjsc";
                if (_getch() == 27)
                {
                    menu.gotoxy(4, 9);
                    escKey = 27;
                }

            }

        }
    }
    else
    {
        cout << "baza nie istnieje, uzyj opcji dodawania nowej bazy..." << endl;
        system("PAUSE");
    }
    
    
}

void WordIn::CreateFileBase(string nameBase)
{
    nameBase = path + nameBase;
    ofstream MyFile(nameBase.c_str());
    MyFile.close();
}
void WordIn::OpenFile(const string nameBase) const
{
    ifstream MyFile(path+nameBase.c_str());
    
}


void WordIn::AddIn(string nameBase,string firstWord,string secondWord)
{
    ofstream AddIn;
    //Write(nameBase);
    AddIn.open(path + nameBase, ios_base::app);
    AddIn << firstWord << ";" << secondWord << "\n";
    AddIn.close();
    
  
}
void WordIn::toFile(string nameBaseCp)
{
    auto cmp = [](const std::string& a, const std::string& b) {
        return a[0] < b[0];
    };
    sort(ratings.begin(), ratings.end(), cmp);
    ofstream file(path + nameBaseCp);
    if (file.is_open())
    {
        
        for (int x = 0; x < ratings.size(); x++)
        {
            file << ratings[x] << "\n";
        }
        file.close();

    }     
}
void WordIn::CheckFile(string nameBaseCp, string nameBase)
{
    string line;
    Interface Interface;
    ifstream file(path + nameBaseCp);
    if (getline(file,line))
    {
        cout << "Nie skonczyles powtorki!" << endl;
        Interface.wybor = '1';
    }
    else
    {
        readLinesFromFile(nameBase, lines);
        toFile(nameBaseCp);
        lines.clear();
            
    }
    file.close();
}

void WordIn::readLinesFromFile(string nameBase, vector<string>& lines)
{
    int i = 0;
    ifstream file(path + nameBase);      
    if (file.good())
    {
        string line;
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    else
    {
        cout << "nie mozna otworzyc pliku " << nameBase << endl;
    }
    
    for (i = 0; i < lines.size(); i++)
    {
        extractWord(lines[i]);      
    }
}



void WordIn::extractWord(string liness)
{
    Interface Interface;
    for (int x = 0; x < liness.length(); x++)
    {
        string phrase,word;
        if (liness[x] == ';')
        {
            int poz = x;
            for (int y = 0; y < x; y++)
            {
                word  = word + liness[y];
            }
            size_t length = liness.length() - (liness.length() - poz);
            for (size_t y = length+1; y <= liness.length(); y++)
            {
                                   
                phrase = phrase + liness[y];                       
            }
            system("CLS");
            Interface.drawFrameLearn();
            printGetWordsLearn(word,phrase);
            
        }
    }
    
}

void WordIn::PrintFile(string nameBase) const
{
    system("CLS");
    Interface Interface;
    Menu Menu;
    string line;
    ifstream file(path+nameBase);
    Menu.gotoxy(1, 2);
    cout << "LISTA POJEC \n\n";
    do
    {
        getline(file, line);
        for (int x = 0; x < line.length(); x++)
        {
            if (line[x] == ';')
            {
                int poz = x;
                for (int y = 0; y < x; y++)
                {
                    cout << line[y];
                }
                cout << " | ";
                size_t length = line.length() - (line.length() - poz);
                for (size_t y = length+1; y <= line.length(); y++)
                {
                    if (line[y] == ';')
                    {
                        line[y] = ' ';
                    }
                    else
                    {
                        cout << line[y];
                    }
                    
                }
                cout << "\n";
                
            }
        }
    }
    while (!file.eof());
    file.close();
}

void WordIn::printGetWordsLearn(string firstWord,string secondWord)
{
    string lineLearn;
    string tmp;
    Menu menu;
    
    menu.gotoxy(2,4);
    cout << firstWord << endl;
    menu.gotoxy(2, 7);
    cout << "jesli kursor miga ponizej to wcisnij enter" << endl;
    getline(cin, tmp);
    menu.gotoxy(2, 10);
    getline(cin, lineLearn);
    menu.gotoxy(2, 13);
    checkWord(lineLearn, secondWord,firstWord);
    

}

void WordIn::checkWord(string gotWord, string compareWord,string copyWord)
{
    Menu menu;
    compareWord.erase(compareWord.length() - 1, 1);
    if (gotWord == compareWord)
    {
        menu.gotoxy(2, 12);
        system("COLOR 2");
        cout << "Bardzo ladnie!" << endl;
        system("COLOR 0");
        correctChar = countSamePositionChars(gotWord, compareWord);
        wsk = correctChar / gotWord.length();
        rateC = selectRate(wsk);
        sClass = SaveRate(rateC, compareWord,copyWord);
    }
    else
    {
        menu.gotoxy(2, 11);
        system("COLOR 4");
        cout << "Nie tym razem!" << endl;
        system("COLOR 0");      
        correctChar = countSamePositionChars(gotWord,compareWord);
        wsk = correctChar / gotWord.length();
        rateC = selectRate(wsk);
        sClass = SaveRate(rateC, compareWord,copyWord);
    }
    _getch();

}

int WordIn::selectRate(float rate)
{
    if (rate == 0.0 && rate <= 0.41)
    {
        return 0;
    }
    else if (rate > 0.41 && rate <= 0.56)
    {
        return 1;
    }
    else if (rate > 0.56 && rate <= 0.71)
    {
        return 2;
    }
    else if (rate > 0.71 && rate <= 0.86)
    {
        return 3;
    }
    else if (rate > 0.86 && rate <= 0.96)
    {
        return 4;
    }
    else if (rate > 0.96 && rate <= 1)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}
int WordIn::SaveRate(int rateClass,string wordToSave,string copyWordT)
{
    Menu menu;
    switch (rateClass)
    {
    case 0:
        menu.gotoxy(2, 13);
        cout << "Duzo ci jeszcze brakuje" << endl;
        ratings.push_back("0:" + copyWordT + ";" + wordToSave);
        return 0;
        break;
    case 1:
        menu.gotoxy(2, 13);
        cout << "Polowa sukcesu" << endl;
        ratings.push_back("1:" + copyWordT + ";" + wordToSave);
        return 1;
        break;
    case 2:
        menu.gotoxy(2, 13);
        cout << "Jest dobrze,ale moglo byc lepiej" << endl;
        ratings.push_back("2:"+copyWordT + ";" + wordToSave);
        return 2;
        break;
    case 3:
        menu.gotoxy(2, 13);
        cout << "Juz blizej konca niz poczatku" << endl;
        ratings.push_back("3:"+copyWordT + ";" + wordToSave);
        return 3;
        break;
    case 4:
        menu.gotoxy(2, 13);
        cout << "Tak blisko prefekcji" << endl;
        ratings.push_back("4:" + copyWordT + ";" + wordToSave);
        return 4;
        break;
    case 5:
        menu.gotoxy(2, 13);
        cout << "Brawo, tak trzymaj i nie puszczaj :)" << endl;
        return 5;
        break;
    default:
        menu.gotoxy(2, 13);
        cout << "cos nie tak" << endl;
        return -1;
        break;
    }
    
}

    
int WordIn::countSamePositionChars(string str3, string str4)
{
    int count = 0;
    int minLength = min(str3.length(), str4.length());

    for (int i = 0; i < minLength; i++)
    {
        if (str3[i] == str4[i])
        {
            count++;
        }
    }
    return count;
}


void WordIn::RepeatIt(string nameBaseCp)
{
    ifstream file(path + nameBaseCp);
    if (file.good())
    {
        string line;
        while (getline(file, line))
        {
            if (line[0] == '5')
            {
                continue;
            }
            else
            {
                extractWord(line.substr(2,line.length()));
                toFile(nameBaseCp);
            }
            
        }
        file.close();
    }
    else
    {
        cout << "nie mozna otworzyc pliku " << nameBaseCp << endl;
    }
}

int main()
{   
    
    WordIn WordIn;
    Interface Interface;
    Menu menu;
    Folder folder;
    string path = ".\\Bases";
    DWORD attributes = GetFileAttributes(path.c_str());      
  
    menu.printSuperMemoCopy();
     
    //if sprawdzajacy czy istnieje folder za pomoca GetFileAttributes
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        cout << "folder nie istnieje, dlatego zostal stworzony" << endl;
        folder.CreateFolder();
    }
    else {
        cout << "folder juz istnieje" << endl;
    }
 

    while (Interface.wybor != '6')
    {
        system("CLS");
        Interface.drawFrame();
        menu.drawMenu(Interface.wybor);
        char navigate = 0;
        while (navigate != KEYENTER)
        {
            switch ((navigate = _getch()))
            {
            case KEYUP:
                Interface.up();
                break;
            case KEYDOWN:
                Interface.down();
                break;
            case KEYENTER:
                Interface.wybor = Interface.enterHit();
                break;
            default:
                continue;
            }
        }
        system("CLS");
       
    }
    return 0;


    
}

