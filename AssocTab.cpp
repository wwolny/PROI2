#include "AssocTab.h"
/*
AssocTab::AssocTab()
{

}

AssocTab::~AssocTab()
{

}

AssocTab::AssocTab(const AssocTab &tmp)
{
    this->KeyCode=tmp.KeyCode;
    this->Map=tmp.Map;
}
*/

//funkcja zwraca wskaznik elementu o najmniejszej wartosci (najbardziej na lewo)
struct  node* most_left(struct node *start)
 {
  if(start->l_son != NULL)
    return most_left(start->l_son);
   else
    return start;
 }

//funkcja zwraca wezel o podanej wartosci, badz NULL, gdy taki wezel nie istnieje
struct node* lookForVal(struct node *start, int value)
 {
   //jezeli wezel ma szukana wartosc to odnalezlismy go
   if (start->value == value) return start;
   //jezeli szukana wartosc jest mniejsza to szukamy w lewym poddrzewie o ile istnieje
   else if (value < start->value&& start->l_son != NULL) return lookForVal(start->l_son, value);
   //jezeli szukana wartosc jest wieksza to szukamy w prawym poddrzewie o ile istnieje
   else if (value > start->value && start->r_son != NULL) return lookForVal(start->r_son, value);
   return NULL;
 }

//dodaje wezel o podanej wartosci n, do drzewa o korzeniu start
int addNode(int n, struct node *start)
 {
  //jezeli drzewo jest puste to dodaj korzen
  if (root == NULL)
   {
	root = (node*)malloc(sizeof *root);
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
	  node *newNode = (node*)malloc(sizeof *root);
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
	   node *newNode = (node*)malloc(sizeof *root);
       newNode->value = n;
       newNode->l_son = NULL;
       newNode->r_son = NULL;
       newNode->parent = start;
       start->r_son=newNode;
      }
    }
  return 0;
 }

//usun wezel start
void delNode(struct node *start)
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
   struct node *temp;
   temp=most_left(start->r_son);
   start->value = temp->value;
   delNode(temp);
  }
 }

//przejdz drzewo w kolejnosci zaczynajac od wezla start
void in_order_tree_walk(struct node *start)
 {
  if(start->l_son != NULL) //jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
   in_order_tree_walk(start->l_son);

  if(start->r_son != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
   in_order_tree_walk(start->r_son);
 }

