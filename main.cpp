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
    newTest.ifAssocArr();
    newTest.ifFile();
    Menu MyMenu;
    MyMenu.startMenu();
    cout << "Hello world!" << endl;

    return 0;
}
