#ifndef CATALOG_H
#define CATALOG_H
#include "Furniture.h"
#include "AssocTab.h"
#include <iostream>
#include <fstream>
#include <string>



class Catalog
{
    public:
        int addFurn(int key, std::string name, int price, int mass);
        int delFurnK(int key);
        int editFurn(int key, std::string newName="", int newPrice=-1, int newMass=-1);
        int allFile(std::string fname);
        int isKeyMap(int key);
        Furniture* findFurnK(int key);
        int allWrite();
        Catalog();
        ~Catalog();
        private:
        node<int, Furniture>* findFurn(int key);
        void orderWrite(node<int, Furniture>* start);
        void orderOutToFile(node<int, Furniture>* start, std::ofstream* pfile);
        AssocTab<int, Furniture>* MyMap;
};

#endif // CATALOG_H
