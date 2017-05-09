#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{

}
void Menu::writeFurn(int key)
{
    Furniture Furn;
    Furn=MyCatalog.findFurnK(key);
    std::cout<<"Furniture key: "<<key<<std::endl<<"Name: "<<Furn.getName()<<"   Price: ";
    std::cout<<Furn.getPrice()<<"   Mass: "<<Furn.getMass()<<std::endl;
    return;
}
/* Wypisz wszystkie meble
void Menu::writeFurnAll(Fleet* fleet)
{
    Unit* tmp;
    tmp=fleet->firstUnit;
    while(tmp)
    {
        writeUnit(tmp);
        tmp=tmp->next;
    }
    delete tmp;
    return;
}*/

void Menu::options()
{
    std::cout<<"[c] create furniture"<<std::endl;
    std::cout<<"[d] delete furniture"<<std::endl;
    std::cout<<"[e] edit furniture"<<std::endl;
    //std::cout<<"[p] best ones"<<std::endl; najdrozszy
    //std::cout<<"[m] best ones"<<std::endl; najciezszy
    //std::cout<<"[t] write down all Furnitures"<<std::endl;
    //std::cout<<"[f] write down all Furnitures to file"<<std::endll;
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
                break;/*
            case 'p':
                this->bestPrice();
                break;
            case 'm':
                this->bestMass();
                break;
            case 't':
                this->writeFurnAll();
                break;
            case 'f':
                this->writeAllFurnFile();
                break;*/
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
    if(MyCatalog.addFurn(key,name, price, mass)==1)return this->Success();
    else return this->Fail();
}
int Menu::delFurn()
{/*
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"type exactly the name of formation that should be deleted:";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    if(myFleet->deleteFormation(myFleet->fleet, myFleet->giveForm(name))==1) return this->Success();
    else return this->Fail();*/
}
int Menu::editFurn(){}/*
int MENU::addUnit(FleetManager* myFleet)
{
    char c;
    std::string name="";
    int spe=0, def=0, pow=0, capa=0;
    std::cout<<"Type name of unit: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isUnitName(name)==0) return this->Fail();
    std::cout<<"Type speed of unit: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>spe;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type defense of unit: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>def;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type power of unit: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>pow;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    std::cout<<"Type capacity of unit: ";
    std::cin>>c;
    if(!std::isdigit(c)) return this->Fail();
    std::cin.unget();
    std::cin>>capa;
    if(!isIntOK()) return this->Fail();
    std::cin.ignore(1000,'\n');
    if(myFleet->createUnit(myFleet->fleet,name,spe, pow, def,capa )==1)return this->Success();
    else return this->Fail();
}
int MENU::delUnit(FleetManager* myFleet)
{
    std::string name;
    this->writeUnitAll(myFleet->fleet);
    std::cout<<"Type name of unit that should be deleted: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isUnitName(name)==1) return this->Fail();
    if(myFleet->deleteUnit(myFleet->fleet, myFleet->giveUnit(name))==1) return this->Success();
    else return this->Fail();
}
int MENU::push(FleetManager* myFleet)
{
    std::string name, tmp;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    writeUnitAll(myFleet->fleet);
    std::cout<<"Type name of unit: ";
    std::cin>>tmp;
    std::cin.ignore(1000,'\n');
    if(myFleet->isUnitName(tmp)==1) return this->Fail();
    if(myFleet->pushUnitToForm(myFleet->giveForm(name), myFleet->giveUnit(tmp))==1) return this->Success();
    else return this->Fail();
}
int MENU::pull(FleetManager* myFleet)
{
    std::string name, tmp;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    this->writeAllUnitInForm(myFleet->giveForm(name));
    std::cout<<"Type name of unit: ";
    std::cin>>tmp;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(tmp)==1) return this->Fail();
    if(myFleet->pullUnitFromForm(myFleet->giveForm(name), myFleet->giveUnit(tmp))==1) return this->Success();
    else return this->Fail();
}
int MENU::unitInForm(FleetManager* myFleet)
{
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)) return this->Fail();
    this->writeAllUnitInForm(myFleet->giveForm(name));
    return this->Success();
}
//------------------------------------
int MENU::BEST(FleetManager* myFleet)
{
    char best;
    while(1)
    {
        this->BestOptions();
        std::cin>>best;
        std::cin.ignore(1000,'\n');
        system("clear");
        switch (best)
        {
            case 'q':
                this->unFlPow(myFleet);
                break;
            case 'w':
                this->unFlSpe(myFleet);
                break;
            case 'e':
                this->unFlCapa(myFleet);
                break;
            case 'r':
                this->unFlDef(myFleet);
                break;
            case 'a':
                this->unForPow(myFleet);
                break;
            case 's':
                this->unForSpe(myFleet);
                break;
            case 'd':
                this->unForCapa(myFleet);
                break;
            case 'f':
                this->unForDef(myFleet);
                break;
            case 'z':
                this->forPow(myFleet);
                break;
            case 'x':
                this->forSpe(myFleet);
                break;
            case 'c':
                this->forCapa(myFleet);
                break;
            case 'v':
                this->forDef(myFleet);
                break;
            case 'l':
                return 0;
            default:
                std::cout<<"Bad Input!"<<std::endl;
                break;
        }
    }
    return 1;
}
//---------------
int MENU::unFlCapa(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetSize()==0) return this->Fail();
    Unit best(*myFleet->bCapaU(myFleet->fleet));
    std::cout<<"The best capacity unit in fleet is: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unFlPow(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetSize()==0) return this->Fail();
    Unit best(*myFleet->bPowU(myFleet->fleet));
    std::cout<<"The most powerful unit in fleet is: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unFlSpe(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetSize()==0) return this->Fail();
    Unit best(*myFleet->bSpeU(myFleet->fleet));
    std::cout<<"The fastest unit in fleet is: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unFlDef(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetSize()==0) return this->Fail();
    Unit best(*myFleet->bDefU(myFleet->fleet));
    std::cout<<"The best capacity unit in fleet is: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
//-------------------
int MENU::unForPow(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    Unit best(*myFleet->bPowU(myFleet->giveForm(name)));
    std::cout<<"The most powerful unit in formation: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unForSpe(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    Unit best(*myFleet->bSpeU(myFleet->giveForm(name)));
    std::cout<<"The fastest unit in formation: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unForDef(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    Unit best(*myFleet->bDefU(myFleet->giveForm(name)));
    std::cout<<"The best defensive unit in formation: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
int MENU::unForCapa(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    std::string name;
    writeFormAll(myFleet->fleet);
    std::cout<<"Type name of formation: ";
    std::cin>>name;
    std::cin.ignore(1000,'\n');
    if(myFleet->isFormName(name)==1) return this->Fail();
    Unit best(*myFleet->bCapaU(myFleet->giveForm(name)));
    std::cout<<"The best capacity unit in formation: "<<std::endl;
    this->writeUnit(&best);
    return this->Success();
}
//------------------------
int MENU::forPow(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    Formation best(*myFleet->bPowF(myFleet->fleet));
    std::cout<<"The most powerful formation in fleet: "<<std::endl;
    this->writeForm(&best);
    return this->Success();
}
int MENU::forSpe(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    Formation best(*myFleet->bSpeF(myFleet->fleet));
    std::cout<<"The fastest formation in fleet: "<<std::endl;
    this->writeForm(&best);
    return this->Success();
}
int MENU::forDef(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    Formation best(*myFleet->bDefF(myFleet->fleet));
    std::cout<<"The best defensive formation in fleet: "<<std::endl;
    this->writeForm(&best);
    return this->Success();
}
int MENU::forCapa(FleetManager* myFleet)
{
    if(myFleet->fleet->getFleetFormNumb()==0) return this->Fail();
    Formation best(*myFleet->bCapaF(myFleet->fleet));
    std::cout<<"The best capacity formation in fleet: "<<std::endl;
    this->writeForm(&best);
    return this->Success();
}*/
//----------------
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

