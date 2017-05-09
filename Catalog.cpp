#include "Catalog.h"

Catalog::Catalog()
{
}

Catalog::~Catalog()
{
}
int Catalog::addFurn(int key, std::string name, int price, int mass)
{
    if(isKeyMap(key)==true) return 0;
    Furniture furn;
    if(name!="")
        furn.setName(name);
    if(price>0) furn.setPrice(price);
    if(mass>0) furn.setMass(mass);
    MyMap.addNode(key, furn, MyMap.getRoot());
    return 1;
}
int Catalog::delFurnK(int key)
{
    if(isKeyMap(key)==false) return 0;
    MyMap.delNode(findFurn(key));
    return 1;
}
int Catalog::editFurn(int key, std::string newName, int newPrice, int newMass)//cannt change key
{
    if(isKeyMap(key)==false) return 0;
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
    orderOutToFile(MyMap.getRoot(), pfile);
    return 1;
}
void Catalog::orderOutToFile(node<int, Furniture>* start, std::ofstream* pfile)
{
    if(start==NULL) return;
    if(start->l_son != NULL) //jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
    {
        orderOutToFile(start->l_son, pfile);
    }
    *pfile<<"Key: "<<start->key<<"    Name: ";
    pfile->write(&start->val.getName()[0], start->val.getName().length());
    *pfile<<"     Price: "<<start->val.getPrice()<<"      Mass: "<<start->val.getMass()<<std::endl;
    if(start->r_son != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
        orderOutToFile(start->r_son, pfile);
}
//-------------------------------------------------
int Catalog::allWrite()//wypisz wszystkie w pliku
{
    std::cout<<"Furnitures that are in the catalog:"<<std::endl;
    orderWrite(MyMap.getRoot());
    return 1;
}
void Catalog::orderWrite(node<int, Furniture>* start)
{
    if(start==NULL) return;
    if(start->l_son != NULL) //jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
    {
        orderWrite(start->l_son);
    }
    std::cout<<"Key: "<<start->key<<"    Name: ";
    std::cout<<start->val.getName();
    std::cout<<"     Price: "<<start->val.getPrice()<<"      Mass: "<<start->val.getMass()<<std::endl;
    if(start->r_son != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
        orderWrite(start->r_son);
}
//-------------------------------------------------
node<int, Furniture>* Catalog::findFurn(int key)
{
    return MyMap.lookForKey(MyMap.getRoot(), key);
}

Furniture Catalog::findFurnK(int key)//zwraca pusty mebel jesli nie ma
{
    Furniture tmp;
    if(findFurn(key)==NULL)return tmp;
    return MyMap.lookForKey(MyMap.getRoot(), key)->val;
}

int Catalog::isKeyMap(int key)
{
    if(isKey(key, MyMap.getRoot())==true) return 1;//There is Key
    else return 0;//There is no key
}
