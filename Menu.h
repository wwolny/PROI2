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

        /*void writeForm(Formation* form);
        void writeUnitAll(Fleet* fleet);
        void writeFormAll(Fleet* fleet);
        void writeAllUnitInForm(Formation* form);
        void BestOptions();
        int creForm(FleetManager* myFleet);
        int delFor(FleetManager* myFleet);
        int addUnit(FleetManager* myFleet);
        int delUnit(FleetManager* myFleet);
        int push(FleetManager* myFleet);
        int pull(FleetManager* myFleet);
        int unitInForm(FleetManager* myFleet);
        int BEST(FleetManager* myFleet);
        int unFlCapa(FleetManager* myFleet);
        int unFlPow(FleetManager* myFleet);
        int unFlDef(FleetManager* myFleet);
        int unFlSpe(FleetManager* myFleet);
        int unForPow(FleetManager* myFleet);
        int unForDef(FleetManager* myFleet);
        int unForCapa(FleetManager* myFleet);
        int unForSpe(FleetManager* myFleet);
        int forPow(FleetManager* myFleet);
        int forDef(FleetManager* myFleet);
        int forSpe(FleetManager* myFleet);
        int forCapa(FleetManager* myFleet);
        */
    private:
        int writeFurnAll();
        void options();
        void writeFurn(int key);
        int creFurn();
        int editFurn();
        int delFurn();
        void getchar();
        int Success();
        int Fail();
        int isIntOK();
        Catalog MyCatalog;


};


#endif // MENU_H
