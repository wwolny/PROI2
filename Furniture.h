#ifndef FURNITURE_H
#define FURNITURE_H
#include <iostream>
#include <string>

class Furniture
{
    public:
        std::string getName();
        int setName(std::string name);
        int getPrice();
        int setPrice(int price);
        int getMass();
        int setMass(int mass);
        Furniture(std::string name="NO NAME", int price=0, int mass=0): Name(name), Price(price), Mass(mass){}
        ~Furniture();
        Furniture(const Furniture &tmp);
        Furniture &operator=(const Furniture &tmp);
        int operator<(const Furniture &tmp) const;
    protected:
    std::string Name;
    int Price;
    int Mass;
};

#endif // FURNITURE_H
