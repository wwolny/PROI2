#ifndef CATALOG_H
#define CATALOG_H
#include "Furniture.h"
#include "AssocTab.h"



class Catalog
{
    public:
        Catalog();
        ~Catalog();
    protected:
    private:
    AssocTab<int, Furniture> MyCatalog;
};

#endif // CATALOG_H
