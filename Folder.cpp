#include "Folder.h"

using namespace std;



void Folder::CreateFolder()
{
    string path = ".\\Bases";
    if (!CreateDirectory(path.c_str(), NULL)) {

        DWORD errorCode = GetLastError();

        switch (errorCode) {
        case ERROR_PATH_NOT_FOUND:
            system("CLS");
            cerr << "Nie ma takiej sciezki\n";
            break;
        case ERROR_ALREADY_EXISTS:
            system("CLS");
            cerr << "Folder juz istnieje \n";
            break;
        case ERROR_ACCESS_DENIED:
            system("CLS");
            cerr << "Brak uprawnien do zapisu w tym folderze \n";
            break;
        default:
            system("CLS");
            cerr << "Brak mozliwosci utworzenie folderu z powodu bledu, Kod bledu: " << errorCode << ") \n";
            break;
        }
        exit(1);
    }
 
}
