#include "Test.h"

Test::Test()
{
   MyMap=new Catalog;
}

Test::~Test()
{
   delete MyMap;
}

bool Test::ifFile()
{
    if(MyMap->addFurn(59, "chair", 100, 5)==0) {return 0;}
    if(MyMap->addFurn(22, "desk", 400, 25)==0) {return 0;}
    if(MyMap->addFurn(38, "table", 14, 35)==0) {return 0;}
    if(MyMap->addFurn(65, "bed", 14, 53)==0) {return 0;}
    if(MyMap->addFurn(51, "regel", 100, 5)==0) {return 0;}
    if(MyMap->addFurn(23, "wardrobe", 400, 25)==0) {return 0;}
    if(MyMap->addFurn(36, "lamp", 14, 35)==0) {return 0;}
    if(MyMap->addFurn(61, "bed", 14, 53)==0) {return 0;}
    if(MyMap->addFurn(52, "sofa", 100, 5)==0) {return 0;}
    if(MyMap->addFurn(23, "door", 400, 25)==1) {return 0;}
    if(MyMap->addFurn(33, "radio", 14, 35)==0) {return 0;}
    if(MyMap->addFurn(34, "window", 14, 53)==0) {return 0;}
    MyMap->allFile("./plik.txt");
    if(MyMap->delFurnK(59)==0) {return 0;}
    if(MyMap->delFurnK(22)==0) {return 0;}
    if(MyMap->delFurnK(38)==0) {return 0;}
    if(MyMap->delFurnK(65)==0) {return 0;}
    if(MyMap->delFurnK(51)==0) {return 0;}
    if(MyMap->delFurnK(23)==0) {return 0;}
    if(MyMap->delFurnK(36)==0) {return 0;}
    if(MyMap->delFurnK(61)==0) {return 0;}
    if(MyMap->delFurnK(52)==0) {return 0;}
    if(MyMap->delFurnK(23)==1) {return 0;}
    if(MyMap->delFurnK(33)==0) {return 0;}
    if(MyMap->delFurnK(34)==0) {return 0;}
    return 1;
}
bool Test::editCat()
{
    if(MyMap->addFurn(59, "chair", 100, 5)==0) {return 0;}
    if(MyMap->addFurn(22, "desk", 400, 25)==0) {return 0;}
    if(MyMap->addFurn(38, "table", 14, 35)==0) {return 0;}
    if(MyMap->addFurn(65, "bed", 14, 53)==0) {return 0;}
    if(MyMap->addFurn(51, "regel", 100, 5)==0) {return 0;}
    if(MyMap->addFurn(23, "wardrobe", 400, 25)==0) {return 0;}
    if(MyMap->addFurn(36, "lamp", 14, 35)==0) {return 0;}
    if(MyMap->addFurn(61, "bed", 14, 53)==0) {return 0;}
    if(MyMap->addFurn(52, "sofa", 100, 5)==0) {return 0;}
    if(MyMap->addFurn(23, "door", 400, 25)==1) {return 0;}
    if(MyMap->addFurn(33, "radio", 14, 35)==0) {return 0;}
    if(MyMap->addFurn(34, "window", 14, 53)==0) {return 0;}

    if(MyMap->editFurn(59, "chair", 100, 5)==0) {return 0;}
    if(MyMap->editFurn(22, "desk", 400, 25)==0) {return 0;}
    if(MyMap->editFurn(38, "table", 14, 35)==0) {return 0;}
    if(MyMap->editFurn(65, "bed", 14, 53)==0) {return 0;}
    if(MyMap->editFurn(51, "regel", 100, 5)==0) {return 0;}
    if(MyMap->editFurn(23, "wardrobe", 400, 25)==0) {return 0;}
    if(MyMap->editFurn(36, "lamp", 14, 35)==0) {return 0;}
    if(MyMap->editFurn(61, "bed", 14, 53)==0) {return 0;}
    if(MyMap->editFurn(52, "sofa", 100, 5)==0) {return 0;}
    if(MyMap->editFurn(23, "door", 400, 25)==0) {return 0;}
    if(MyMap->editFurn(33, "radio", 14, 35)==0) {return 0;}
    if(MyMap->editFurn(34, "window", 14, 53)==0) {return 0;}
    return 1;
}
