#include <iostream>
#include "Furniture.h"
#include "AssocTab.h"
#include "Test.h"
#include "Catalog.h"
using namespace std;

int main()
{
    Test newTest;
    newTest.ifAssocArr();
    newTest.ifFile();
    cout << "Hello world!" << endl;

    return 0;
}
