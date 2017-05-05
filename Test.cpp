#include "Test.h"

Test::Test()
{
    //ctor
}

Test::~Test()
{
    //dtor
}

bool Test::ifAssocArr()
{
    AssocTab<int, Furniture> MyMap;
    Furniture chair("chair", 100, 5);
    MyMap.addNode(5, chair, MyMap.getRoot());
    Furniture table("table", 400, 25);
    MyMap.addNode(6, table, MyMap.getRoot());
    Furniture desk("desk", 14, 35);
    MyMap.addNode(7, desk, MyMap.getRoot());
    Furniture sofa("sofa", 11, 53);
    MyMap.addNode(8, sofa, MyMap.getRoot());
    Furniture bed("bed", 14, 53);
    MyMap.addNode(1, bed, MyMap.getRoot());
    MyMap.delNode(MyMap.lookForKey(MyMap.getRoot(), 7));
    MyMap.delNode(MyMap.lookForKey(MyMap.getRoot(), 65));
    MyMap.delNode(MyMap.lookForKey(MyMap.getRoot(), 3));
    MyMap.delNode(MyMap.lookForKey(MyMap.getRoot(), 3));
    MyMap.delNode(MyMap.lookForKey(MyMap.getRoot(), 1));
    return 1;
}
bool Test::ifFile()
{
    Catalog testCat;
    testCat.allFile("./plik.txt");
    return 1;
}
