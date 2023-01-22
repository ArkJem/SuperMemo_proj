#include "WordIn.h"

int main()
{   
    char choosen = '1';
    WordIn WordIn;
    Interface Interface(choosen);
    Menu menu;
    Folder folder;
    string path = ".\\Bases";
    string nameBase,nameBaseCp;
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
 

    while (choosen != '6')
    {
        system("CLS");
        Interface.drawFrame();
        menu.drawMenu(choosen);
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
                choosen = Interface.enterHit();
                break;
            default:
                continue;
            }
        }
        switch (choosen)
        {
        case '1':
            system("CLS");
            cout << "podaj nazwe bazy: \n";
            cin >> nameBase;
            nameBaseCp = nameBase + "Copy";
            nameBase += ".txt";
            nameBaseCp += ".txt";
            WordIn.CreateFileBase(nameBase);
            WordIn.CreateFileBase(nameBaseCp);
            WordIn.AddIn(nameBaseCp, "5:", " ");
            system("PAUSE");
            system("CLS");            
            break;
        case '2':
            system("CLS");
            cout << "podaj nazwe bazy: \n";
            cin >> nameBase;
            nameBase += ".txt";
            system("cls");
            WordIn.Write(nameBase);
            break;
        case '3':
            system("CLS");
            cout << "podaj nazwe bazy: \n";
            cin >> nameBase;
            nameBase += ".txt";
            WordIn.PrintFile(nameBase);
            system("PAUSE");
            system("CLS");
            break;
        case '4':
            system("CLS");
            cout << "podaj nazwe bazy: \n";
            cin >> nameBase;
            nameBaseCp = nameBase + "Copy";
            nameBase += ".txt";
            nameBaseCp += ".txt";
            WordIn.CheckFile(nameBaseCp, nameBase);
            system("PAUSE");
            system("CLS");
            break;
        case '5':
            system("CLS");
            cout << "podaj nazwe bazy: \n";
            cin >> nameBase;
            nameBaseCp = nameBase + "Copy";
            nameBaseCp += ".txt";
            WordIn.RepeatIt(nameBaseCp);
            system("PAUSE");
            break;
        }
        system("CLS");
       
    }
    return 0;


    
}

