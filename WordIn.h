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
	string line;
	double wsk = 0.0;
	double correctChar = 0;
	int rateC = 0;
	int sClass = 0;
	int timeToSave =0;
		
public:
	void Write(string nameBase);
	void AddIn(string nameBase,string firstWord, string secondWord);
	void CreateFileBase(string nameBase);
	void OpenFile(const string nameBase)const;
	void CloseFile()const;
	void PrintFile(const string nameBase)const;
	void wordsToArray(string nameBase);
	vector<string> lines;
	vector<string> ratings;
	void extractWord(string liness);
	void printGetWordsLearn(string firstWord,string secondWord);
	void checkWord(string gotWord, string compareWord,string copyWord);
	string removeExtraWhiteSpaces(string s);
	void readLinesFromFile(string nameBase, vector<string>& lines);
	int selectRate(float rate);
	int SaveRate(int rateClass, string wordToSave,string copyWordT);
	void toFile(string nameBase);
	int countSamePositionChars(string str1, string str2);
	void RepeatIt(string nameBaseCp);
	void CheckFile(string nameBaseCp,string namebase);
};

