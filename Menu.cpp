#include "Menu.h"

Menu::Menu()
{
    MyCatalog=new Catalog;
}

Menu::~Menu()
{
    delete MyCatalog;
}
void Menu::writeFurn(int key)
{
    Furniture* Furn;
    Furn=MyCatalog->findFurnK(key);
    std::cout<<"Furniture key: "<<key<<std::endl<<"Name: "<<Furn->getName()<<"   Price: ";
    std::cout<<Furn->getPrice()<<"   Mass: "<<Furn->getMass()<<std::endl;
    return;
}
void Menu::options()
{
    std::cout<<"[c] create furniture"<<std::endl;
    std::cout<<"[d] delete furniture"<<std::endl;
    std::cout<<"[e] edit furniture"<<std::endl;
    std::cout<<"[t] write down all Furnitures"<<std::endl;
    std::cout<<"[f] write down all Furnitures to file"<<std::endl;
    std::cout<<"[l] leave menu"<<std::endl;
}
void Menu::startMenu()
{
    char Next;
    while(1)
    {
        this->options();
        std::cin>>Next;
        std::cin.ignore(1000,'\n');
        system("clear");
        switch (Next)
        {
            case 'c':
                this->creFurn();
                break;
            case 'd':
                this->delFurn();
                break;
            case 'e':
                this->editFurn();
                break;
            case 't':
                this->writeFurnAll();
                break;
            case 'f':
                this->writeAllFurnFile();
                break;
            case 'l':
                return;
            default:
                std::cout<<"Bad Input!"<<std::endl;
                break;
        }
    }
}
//--------------------------------------------------
int Menu::creFurn()
{
    char c;
    std::string name="";
    int price=0, mass=0, key=0;
    std::cout<<"Type name of Furniture: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    std::cout<<"Type key of furniture: ";
    std::cin>>c;
    if(!std::isdigit(c))    return this->Fail();
    std::cin.unget();
    std::cin>>key;
    if(!isIntOK())      return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type price of furniture: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>price;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type mass of furniture: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>mass;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    if(MyCatalog->addFurn(key,name, price, mass)==1)return this->Success();
    else return this->Fail();
}
int Menu::delFurn()
{
    char c;
    int key=-1;
    writeFurnAll();
    std::cout<<"type exactly the KEY of furniture that should be deleted:";
    std::cin>>c;
    if(!std::isdigit(c))    return this->Fail();
    std::cin.unget();
    std::cin>>key;
    if(!isIntOK())      return this->Fail();
    std::cin.ignore(1000,'\n');
    if(MyCatalog->delFurnK(key)==1) return this->Success();
    else return this->Fail();
}
int Menu::editFurn()
{
    writeFurnAll();
    char c;
    std::string name="";
    int price=0, mass=0, key=0;
    std::cout<<"Type exactly the key of furniture that should be edited: ";
    std::cin>>c;
    if(!std::isdigit(c))    return this->Fail();
    std::cin.unget();
    std::cin>>key;
    if(!isIntOK())      return this->Fail();
    std::cin.ignore(1000,'\n');
    if(MyCatalog->isKeyMap(key)==0)return this->Fail();
    std::cout<<"Type new name of the furniture: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    std::cout<<"Type new price of the furniture: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>price;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type new mass of furniture: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>mass;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    if(MyCatalog->editFurn(key,name, price, mass)==1)return this->Success();
    else return this->Fail();
}
int Menu::writeFurnAll()
{
    MyCatalog->allWrite();
    return 1;
}
int Menu::writeAllFurnFile()
{
    std::string fname="";
    std::cout<<"Type name of file: ";
    std::cin>>fname;
    std::cin.ignore(1000,'\n');
    if(MyCatalog->allFile(fname)==1)return Success();
    else return Fail();
}
//-----------------------
void Menu::getchar()
{
    std::cin.get();
}
int Menu::Success()
{
    std::cout<<"Success!"<<std::endl;
    getchar();
    return 1;
}
int Menu::Fail()
{
    std::cout<<"Fail!"<<std::endl;
    getchar();
    return 0;
}
int Menu::isIntOK()//if fail return 0
{
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return this->Fail();
    }
    else return 1;
}

