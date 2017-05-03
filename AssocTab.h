#ifndef ASSOCTAB_H
#define ASSOCTAB_H
#include <iostream>
#include <stdlib.h>
struct node
 {
  int value;
  struct node *parent;
  struct node *l_son;
  struct node *r_son;
 };
struct node *root;

//funkcja zwraca wskaznik elementu o najmniejszej wartosci (najbardziej na lewo)
struct node* most_left(struct node *start);
//funkcja zwraca wezel o podanej wartosci, badz NULL, gdy taki wezel nie istnieje
struct node* lookForVal(struct node *start, int value);
//dodaje wezel o podanej wartosci n, do drzewa o korzeniu start
int addNode(int n, struct node *start);
//usun wezel start
void delNode(struct node *start);
//przejdz drzewo w kolejnosci zaczynajac od wezla start
void in_order_tree_walk(struct node *start);

template <class Key , class Value> class AssocTab
{
    public:
        //AssocTab();
        //~AssocTab();
        //AssocTab(const AssocTab &tmp);
    protected:
    private:
};

#endif // ASSOCTAB_H
