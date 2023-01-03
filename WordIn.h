#pragma once
#include <string>
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <vector>


using namespace std;

#define KEYESCAPE 27

class WordIn
{
private:
	string word;
	string anotherWord;
	string lineInFile;
	string path = ".\\Bases\\";
	string wordToPrint, wordToGuess;

public:
	void Write(string nameBase);
	void CompareWord();
	void AddIn(string nameBase,string firstWord, string secondWord);
	void CreateFileBase(string nameBase);
	void OpenFile(const string nameBase)const;
	void CloseFile()const;
	void PrintFile(const string nameBase)const;
	void wordsToArray(string nameBase);
	vector<vector<string>> arrayWords;
	void extractWord();
	void printGetWordsLearn(string firstWord);
	void checkWord(string gotWord, string compareWord);

};

