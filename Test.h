#ifndef TEST_H
#define TEST_H
#include <iostream>
#include "Furniture.h"
#include "AssocTab.h"
#include "Catalog.h"

class Test
{
    public:
        Test();
        ~Test();
        bool ifAssocArr();
        bool ifFile();
        bool editCat();
    private:
        Catalog* MyMap;
};

#endif // TEST_H
