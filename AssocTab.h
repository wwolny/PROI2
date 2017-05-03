#ifndef ASSOCTAB_H
#define ASSOCTAB_H
#include <iostream>
#include <stdlib.h>

template <class Key, class Value> struct node
 {
    Key value;
    Value sup;
    struct node *parent;
    struct node *l_son;
    struct node *r_son;
 };

template <class Key , class Value> class AssocTab
{
    node<Key, Value>* root=NULL;
    node<Key, Value>* most_left(node<Key, Value> *start)
     {
      if(start->l_son != NULL)
        return most_left(start->l_son);
       else
        return start;
     }
    node<Key, Value>* lookForVal(node<Key, Value>* start, Key value)
     {
       //jezeli wezel ma szukana wartosc to odnalezlismy go
       if (start->value == value) return start;
       //jezeli szukana wartosc jest mniejsza to szukamy w lewym poddrzewie o ile istnieje
       else if (value < start->value&& start->l_son != NULL) return lookForVal(start->l_son, value);
       //jezeli szukana wartosc jest wieksza to szukamy w prawym poddrzewie o ile istnieje
       else if (value > start->value && start->r_son != NULL) return lookForVal(start->r_son, value);
       return NULL;
     }

    Key addNode(Key n, node<Key, Value>* start)
     {
      //jezeli drzewo jest puste to dodaj korzen
      if (root == NULL)
       {
        root = (node<Key, Value>*)malloc(sizeof *root);
        root->value = n;
        root->l_son = NULL;
        root->r_son = NULL;
        root->parent = NULL;
       }
      //jezeli zadana wartosc jest mniejsza od korzenia idz do lewego poddrzewa
      else if(n < start->value)
       {
        //jezeli lewe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie
        if(start->l_son != NULL)
         {
          addNode(n,start->l_son);
         }
        //jezeli lewe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
         else
         {
          node<Key, Value>* newNode = (node<Key, Value>*)malloc(sizeof *root);
          newNode->value = n;
          newNode->l_son = NULL;
          newNode->r_son = NULL;
          newNode->parent = start;
          start->l_son=newNode;
         }
        }
       //jezeli zadana wartosc jest wieksza lub rowna korzeniowi idz do prawego poddrzewa
       else
        {
         //jezeli prawe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie
         if(start->r_son!=NULL)
          {
           addNode(n,start->r_son);
          }
         //jezeli prawe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
         else
          {
           node<Key, Value>* newNode = (node<Key, Value>*)malloc(sizeof *root);
           newNode->value = n;
           newNode->l_son = NULL;
           newNode->r_son = NULL;
           newNode->parent = start;
           start->r_son=newNode;
          }
        }
      return 0;
     }

    void delNode(node<Key, Value>* start)
    {
      //jezeli wezel nie ma dzieci
      if(start->l_son==NULL && start->r_son==NULL)
      {
       //jezeli wezel jest korzeniem
       if(start->parent==NULL)
       {
        root=NULL;
       }
       //jezeli wezel jest po lewej stronie rodzica,
       else if(start->parent->l_son==start)
       {
        //usun wezel z lewej strony wezla rodzica
        start->parent->l_son=NULL;
       }
       else
       {
        //usun wezel z prawej strony wezla rodzica
        start->parent->r_son=NULL;
       }
       delete start;
      }
      //jezeli wezel ma tylko jedno dziecko
      else if(start->l_son==NULL || start->r_son==NULL)
      {
       //jezeli po lewej stronie nie ma dziecka
       if(start->l_son==NULL)
       {
        //jezeli wezel jest korzeniem
        if(start->parent==NULL)
        {
         root=start->r_son;
        }
        //jezeli wezel jest po lewej stronie rodzica
        else if(start->parent->l_son==start)
        {
         //przyczep z lewej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
         start->parent->l_son=start->r_son;
        }
        else
        {
         //przyczep z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
         start->parent->r_son=start->r_son;
        }
       }
       else
       {
        //jezeli wezel jest korzeniem
        if(start->parent==NULL)
        {
         root=start->l_son;
        }
        //jezeli wezel jest po lewej stronie rodzica
        else if(start->parent->l_son==start)
        {
         //przyczep z lewej strony rodzica wezel bedacy po lewej stronie usuwanego wezla
         start->parent->l_son=start->l_son;
        }
        else
        {
         //przyczep z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
         start->parent->r_son=start->l_son;
        }
       }
       delete start;
      }
      else
      {
       //wstaw w miejsce usuwanego elementu - najmniejsza wartosc z prawego poddrzewa
       node<Key, Value>* temp;
       temp=most_left(start->r_son);
       start->value = temp->value;
       delNode(temp);
      }
     }

    void in_order_tree_walk(node<Key, Value>* start)
    {
      if(start->l_son != NULL) //jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
       in_order_tree_walk(start->l_son);

      if(start->r_son != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
       in_order_tree_walk(start->r_son);
     }

    public:
        //AssocTab();
        //~AssocTab();
        //AssocTab(const AssocTab &tmp);
    protected:
    private:
};

#endif // ASSOCTAB_H
