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
    MyMap.addNode(5, MyMap.root);
    MyMap.addNode(6, MyMap.root);
    MyMap.addNode(7, MyMap.root);
    MyMap.addNode(8, MyMap.root);
    MyMap.addNode(1, MyMap.root);
    MyMap.in_order_tree_walk(MyMap.root);
    return 1;
}
