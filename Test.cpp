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
   /* MyMap.addNode(7, desk, MyMap.getRoot());
    Furniture sofa("sofa", 11, 53);
    MyMap.addNode(8, sofa, MyMap.getRoot());
    Furniture bed("bed", 14, 53);
    MyMap.addNode(1, bed, MyMap.getRoot());
    *///std::cout<<MyMap.lookForKey(MyMap.getRoot(), 7)->val.getMass()<<std::endl;
    MyMap.in_order_tree_walk(MyMap.getRoot());

    return 1;
}
