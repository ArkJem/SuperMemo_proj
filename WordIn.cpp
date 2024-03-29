#include "WordIn.h"

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
        Interface Interface(choosen);
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
        cout << "Baza nie istnieje, uzyj opcji dodawania nowej bazy..." << endl;
        system("PAUSE");
    }


}

void WordIn::CreateFileBase(string nameBase)
{
    ifstream file(path + nameBase);
    if (file.good())
    {
        cout << "Baza juz istnieje" << endl;        
    }
    else
    {
        nameBase = path + nameBase;
        ofstream MyFile(nameBase.c_str());
        MyFile.close();
    }
    file.close();
}

void WordIn::AddIn(string nameBase, string firstWord, string secondWord)
{
    ofstream AddIn;
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
    Menu menu;
    string line,lineBase;
    Interface Interface(choosen);
    ifstream baseFile(path + nameBase);
    ifstream file(path + nameBaseCp);
    if (baseFile.peek() == EOF)
    {
        menu.gotoxy(1, 3);
        cout << "baza glowna jest pusta, koniecznie dodaj slowa za pomoco opcji 'dodaj slowa do bazy'!" << endl;

    }
    else
    {
        if (getline(file, line))
        {
            if (line[0] == '5')
            {
                readLinesFromFile(nameBase, lines);
                toFile(nameBaseCp);
                lines.clear();
            }
            else
            {
                cout << "Nie skonczyles powtorki!" << endl;
                choosen = '1';
            }

        }
        file.close();
    }
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
    Interface Interface(choosen);
    for (int x = 0; x < liness.length(); x++)
    {
        string phrase, word;
        if (liness[x] == ';')
        {
            int poz = x;
            for (int y = 0; y < x; y++)
            {
                word = word + liness[y];
            }
            size_t length = liness.length() - (liness.length() - poz);
            for (size_t y = length + 1; y <= liness.length(); y++)
            {

                phrase = phrase + liness[y];
            }
            system("CLS");
            Interface.drawFrameLearn();
            printGetWordsLearn(word, phrase);

        }
    }

}



void WordIn::PrintFile(string nameBase) const
{
    system("CLS");
    Menu Menu;
    string line;
    ifstream file(path + nameBase);
    if (file.good())
    {
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
                    for (size_t y = length + 1; y <= line.length(); y++)
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
        } while (!file.eof());
        file.close();
    }
    else
    {
        cout << "Baza nie istnieje, uzyj opcji dodawania nowej bazy..." << endl;
    }
}

void WordIn::printGetWordsLearn(string firstWord, string secondWord)
{
    string lineLearn;
    string tmp;
    Menu menu;

    menu.gotoxy(2, 4);
    cout << firstWord << endl;
    menu.gotoxy(2, 7);
    cout << "!!Jesli kursor miga ponizej to wcisnij enter!!" << endl;
    getline(cin, tmp);
    menu.gotoxy(2, 10);
    getline(cin, lineLearn);
    menu.gotoxy(2, 13);
    checkWord(lineLearn, secondWord, firstWord);


}

void WordIn::checkWord(string gotWord, string compareWord, string copyWord)
{
    Menu menu;
    compareWord.erase(compareWord.length() - 1, 1);
    if (gotWord == compareWord)
    {
        menu.gotoxy(2, 12);
        system("COLOR 2");
        cout << "Bardzo ladnie!" << endl;
        system("COLOR 0");
        if (gotWord.length() > compareWord.length())
        {
            correctChar = countSamePositionChars(gotWord, compareWord);
            wsk = correctChar / gotWord.length();
            rateC = selectRate(wsk);
            sClass = SaveRate(rateC, compareWord, copyWord);
            _getch();
        }
        else
        {
            correctChar = countSamePositionChars(gotWord, compareWord);
            wsk = correctChar / compareWord.length();
            rateC = selectRate(wsk);
            sClass = SaveRate(rateC, compareWord, copyWord);
            _getch();
        }
    }
    else
    {
        menu.gotoxy(2, 11);
        system("COLOR 4");
        cout << "Nie tym razem!" << endl;
        system("COLOR 0");
        if (gotWord.length() > compareWord.length())
        {
            correctChar = countSamePositionChars(gotWord, compareWord);
            wsk = correctChar / gotWord.length();
            rateC = selectRate(wsk);
            sClass = SaveRate(rateC, compareWord, copyWord);
            _getch();
        }
        else
        {
            correctChar = countSamePositionChars(gotWord, compareWord);
            wsk = correctChar / compareWord.length();
            rateC = selectRate(wsk);
            sClass = SaveRate(rateC, compareWord, copyWord);
            _getch();
        }
        

    }
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

void WordIn::replaceLine(vector<string>& ratings, string oldLine, string newLine) {
    for (int i = 0; i < ratings.size(); i++) {
        std::string line = ratings[i];
        line = line.substr(line.find(";") + 1);
        if (line == oldLine) {
            ratings[i] = newLine;
            return;
        }
    }
    ratings.push_back(newLine);
}



int WordIn::SaveRate(int rateClass, string wordToSave, string copyWordT)
{
    Menu menu;
    switch (rateClass)
    {
    case 0:
        menu.gotoxy(2, 13);
        cout << "Duzo ci jeszcze brakuje" << endl;
        replaceLine(ratings,wordToSave, "0:" + copyWordT + ";" + wordToSave);
        return 0;
        break;
    case 1:
        menu.gotoxy(2, 13);
        cout << "Polowa sukcesu" << endl;
        replaceLine(ratings, wordToSave, "1:" + copyWordT + ";" + wordToSave);
        return 1;
        break;
    case 2:
        menu.gotoxy(2, 13);
        cout << "Jest dobrze,ale moglo byc lepiej" << endl;
        replaceLine(ratings, wordToSave, "2:" + copyWordT + ";" + wordToSave);
        return 2;
        break;
    case 3:
        menu.gotoxy(2, 13);
        cout << "Juz blizej konca niz poczatku" << endl;
        replaceLine(ratings, wordToSave, "3:" + copyWordT + ";" + wordToSave);
        return 3;
        break;
    case 4:
        menu.gotoxy(2, 13);
        cout << "Tak blisko prefekcji" << endl;
        replaceLine(ratings, wordToSave, "4:" + copyWordT + ";" + wordToSave);
        return 4;
        break;
    case 5:
        menu.gotoxy(2, 13);
        replaceLine(ratings, wordToSave,"5:" + copyWordT + ";" + wordToSave);
        cout << "Brawo, tak trzymaj i nie puszczaj :)" << endl;
        return 5;
        break;
    default:
        menu.gotoxy(2, 13);
        cout << "Cos nie tak" << endl;
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
    Menu menu;
    ifstream file(path + nameBaseCp);
    if (file.good())
    {
        string line;
        while (getline(file, line))
        {
            if (line[0] == '5')
            {
                system("CLS");
                menu.gotoxy(1, 3);
                cout << "baza slow jest pusta lub nie rozpoczales trybu oceny albo poprawnie przeszedles tryb powtorki, wcisnij ENTER aby kontynuowac" << endl;
                break;
            }
            else
            {
                if (line[0] == '5')
                {
                    ratings.pop_back();
                }
                else
                {
                    extractWord(line.substr(2, line.length()));

                }
                toFile(nameBaseCp);
            }
            
        }
        
        file.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << nameBaseCp << endl;
    }
}