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


void WordIn::Write(string nameBase)
{
    Menu menu;
    Interface Interface;
    int escKey = 1;
    if (escKey != KEYESCAPE)
    {
            string tmp;
            getline(cin, tmp);
            while(escKey != KEYESCAPE)
            {                
                system("cls");
                Interface.drawFrameAddWord();
                menu.gotoxy(2, 4);
                getline(cin, word);
                menu.gotoxy(2, 7);
                getline(cin, anotherWord);
                WordIn::AddIn(nameBase, word, anotherWord);            
                if (_getch() == 27)
                {
                    menu.gotoxy(4, 9);
                    escKey = 27;
                }

            }
        
    }
    
    
}

void WordIn::CreateFileBase(string nameBase)
{
    
    ofstream MyFile(path+nameBase.c_str()); // tworzy i otwiera plik tekstowy za pomoca klasy ofstream
    MyFile.close();
}
void WordIn::OpenFile(const string nameBase) const
{
    ifstream MyFile(path+nameBase.c_str());
    
}

void WordIn::CompareWord()
{
    //cout << word.size(); dlugosc slowa razem z bialymi znakami
    //string slowo = "jablko1 jest jablkiem1";
    ifstream ReadMyFile("collection.txt"); // otwiera plik

    while (getline(ReadMyFile, lineInFile)) //petla czyta cala linie w pliku
    {
        cout << lineInFile;
    }
    ReadMyFile.close();
    /*
    if (slowo.compare(word)==0)
    {
        cout << "slowo jest poprawne" << endl;
    }
    else
    {
        cout << "slowo jest niepoprawne" << endl;
    }
    */
    

}

void WordIn::AddIn(string nameBase,string firstWord,string secondWord)
{
    ofstream AddIn;
    AddIn.open(path+nameBase, ios_base::app);
    AddIn << firstWord << ";" << secondWord << "\n";
    AddIn.close();
  
}

void WordIn::wordsToArray(string nameBase)
{
    string line;
    ifstream file(path + nameBase);
    do
    {
        string word = " ", phrase = " ";
        vector<string> words;
        getline(file, line);
        for (int x = 0; x < line.length(); x++)
        {
            if (line[x] == ';')
            {
                int poz = x;
                for (int y = 0; y < x; y++)
                {
                   word = word + line[y];
                   
                }
                words.push_back(word);
                //cout << word;
                int length = line.length() - (line.length() - poz);
                for (int y = length + 1; y <= line.length(); y++)
                {
                    if (line[y] == ';')
                    {
                        line[y] = ' ';
                    }
                    else
                    {
                        phrase = phrase + line[y];                       
                    }
                }
                words.push_back(phrase);
                cout << "\n";
                arrayWords.push_back(words);

            }
        }
    } while (!file.eof());
    
 }

void WordIn::extractWord()
{    
    for (size_t i = 0; i < arrayWords.size(); i++)
    {
        for (size_t j = 0; j < arrayWords[i].size(); j++)
        {
            wordToPrint = arrayWords[i][0];
            wordToGuess = arrayWords[i][1];
        }
        cout << wordToPrint << endl;
        cout << wordToGuess << endl;
    }
}

void WordIn::PrintFile(string nameBase) const
{
    system("CLS");
    Interface Interface;
    Menu Menu;
    //Interface.drawFrame();
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
                int length = line.length() - (line.length() - poz);
                for (int y = length+1; y <= line.length(); y++)
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
}




int main()
{   
    string number;
    string firstWord, secondWord;
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


    while (Interface.wybor != '5')
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

