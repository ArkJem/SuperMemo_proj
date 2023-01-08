#include "WordIn.h"

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

