#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Catalog.h"
#include "Furniture.h"

class Menu
{
    public:
        Menu();
        ~Menu();
        void startMenu();
    private:
        int writeFurnAll();
        void options();
        void writeFurn(int key);
        int writeAllFurnFile();
        int creFurn();
        int editFurn();
        int delFurn();
        void getchar();
        int Success();
        int Fail();
        int isIntOK();
        Catalog *MyCatalog;


};


#endif // MENU_H
