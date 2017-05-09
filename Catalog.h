#ifndef CATALOG_H
#define CATALOG_H
#include "Furniture.h"
#include "AssocTab.h"
#include <iostream>
#include <fstream>



class Catalog
{
    public:
        int addFurn(int key, std::string name, int price, int mass);
        int delFurnK(int key);
        Catalog findFurnN(std::string name);//usuwa wszystkie o tej nazwie
        int editFurn(int key, std::string newName="", int newPrice=-1, int newMass=-1);
        int allFile(std::string fname);//wypisz wszystkie w pliku
        int getKey();

        node<int, Furniture>* findFurn(int key);
        Furniture findFurnK(int key);
        Catalog();
        ~Catalog();
        private:
        //void orderOutToFile(struct node* start, std::string fname);
        AssocTab<int, Furniture> MyMap;
};

#endif // CATALOG_H
