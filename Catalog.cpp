#include "Catalog.h"

Catalog::Catalog()
{
}

Catalog::~Catalog()
{
}
Catalog Catalog::findFurnN(std::string name)
{
}
int Catalog::addFurn(int key, std::string name, int price, int mass)
{
    if(isKey(key, MyCatalog.getRoot())==true) return 0;
    Furniture furn;
    if(name!="")
        furn.setName(name);
    if(price>0) furn.setPrice(price);
    if(mass>0) furn.setMass(mass);
    MyCatalog.addNode(key, furn, MyCatalog.getRoot());
    return 1;
}
int Catalog::delFurnK(int key)
{
    if(isKey(key, MyCatalog.getRoot())==false) return 0;
    MyCatalog.delNode(findFurn(key));
    return 1;
}
int Catalog::editFurn(int key, std::string newName, int newPrice, int newMass)
{
    if(findFurn(key)==NULL)return 0;
    if(newName!="") findFurn(key)->val.setName(newName);
    if(newPrice>0) findFurn(key)->val.setPrice(newPrice);
    if(newMass>0) findFurn(key)->val.setMass(newMass);
    return 1;
}
int Catalog::allFile(std::string fname)//wypisz wszystkie w pliku
{
    std::ofstream file;//("plik.txt");
    std::ofstream* pfile;
    file.open( fname.c_str(), std::ios::out);
    if(file.good()==false) return 0;
    pfile=&file;
    file<<"Welcome!"<<std::endl<<"This is furniture catalog."<<std::endl;
    file<<"Furnitures that are in the catalog:"<<std::endl;
    //orderOutToFile(MyCatalog.getRoot(), fname);
    return 1;
}
/*void Catalog::orderOutToFile(node* start, std::string fname)
{
    std::ofstream file;//("plik.txt");
    file.open( fname.c_str(), std::ios::out);
    if(start->l_son == NULL) //jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
    {
        orderOutToFile(start->l_son, fname);
    }
    file<<"Key: "<<start->key<<"    Name: ";
    file.write(&start->val.getName()[0], start->val.getName().length());
    file<<"     Price: "<<start->val.getPrice()<<"      Mass: "<<start->val.getMass()<<std::endl;
    if(start->r_son != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
    orderOutToFile(start->r_son, fname);
}*/
node<int, Furniture>* Catalog::findFurn(int key)
{
    return MyCatalog.lookForKey(MyCatalog.getRoot(), key);
}

Furniture Catalog::findFurnK(int key)//zwraca pusty mebel jesli nie ma
{
    Furniture tmp;
    if(findFurn(key)==NULL)return tmp;
    return MyCatalog.lookForKey(MyCatalog.getRoot(), key)->val;
}
