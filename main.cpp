#include <iostream>
#include "Furniture.h"
#include "AssocTab.h"
#include "Test.h"
#include "Catalog.h"
#include "Menu.h"
using namespace std;

int main()
{
    Test newTest;
    //if(newTest.ifFile()==1) std::cout<<"file: ok"<<std::endl;
    //if(newTest.editCat()==1) std::cout<<"adding and deleting: ok"<<std::endl;
    Menu MyMenu;
    MyMenu.startMenu();
    cout << "Hello world!" << endl;

    return 0;
}
