#include "Furniture.h"

Furniture::~Furniture()
{
}
Furniture::Furniture(const Furniture &tmp)
{
    this->Name=tmp.Name;
    this->Price=tmp.Price;
    this->Mass=tmp.Mass;
}

Furniture& Furniture::operator=(const Furniture &tmp)
{
   this->Name=tmp.Name;
   this->Price=tmp.Price;
   this->Mass=tmp.Mass;
   return *this;
}

int Furniture::operator<(const Furniture &tmp) const
{
    if(this->Price < tmp.Price) return 1;
    if(this->Mass < tmp.Mass) return 1;
    return 0;
}


std::string Furniture::getName()
{
    return this->Name;
}
int Furniture::setName(std::string name)
{
    if(name.length()>0)
    {
        this->Name=name;
        return 1;
    }
    return 0;
}
int Furniture::getPrice()
{
    return this->Price;
}
int Furniture::setPrice(int price)
{
    if(price>=0)
    {
        this->Price=price;
        return 1;
    }
    return 0;
}
int Furniture::getMass()
{
    return this->Mass;
}
int Furniture::setMass(int mass)
{
    if(mass>=0)
    {
        this->Mass=mass;
        return 1;
    }
    return 0;
}
