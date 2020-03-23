//CSCI 301
//Concordance_Recursive.cpp
//Concordance_Recursive Class: A Class to implement a Concordance, through a Linked List (with recursive functions)
//Hissamuddin Shaikh
#include "Concordance_Recursive.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
//Constructor
Concordance_Recursive::Concordance_Recursive()
{
    first = NULL;
}
//Destructor
Concordance_Recursive::~Concordance_Recursive()
{
    Give_Back(first);
}
//Recursive function for the Destructor.
void Concordance_Recursive::Give_Back(Node *p)
{
    if (p != NULL)
    {
        Give_Back(p -> next);
        delete p;
    }
}
//Private function
//Involved in the creation of the Concordance,
Concordance_Recursive::Node *Concordance_Recursive::Get_Node(Word s, int c, Node *nextPtr)
{
     Node *newNode = new Node;
     newNode->count = c;
     newNode->next = nextPtr;
     strcpy(newNode->wd,s);
     return newNode;
}
//Friend Function
//Function to allow the contents of the Concordance to be written out
ostream& operator << ( ostream& out_s, Concordance_Recursive& c )
  {
    Concordance_Recursive::Node *temp;

    out_s << endl;
    out_s << " Word" << "\t\t" << "Count" <<endl;
    out_s <<" --------------------"<<endl;
    temp = c.first;
    c.R_Write(out_s, temp);
    out_s <<" --------------------"<<endl;
    out_s << endl;

    return out_s;
  }
//Recursive function for displaying the contents of the Concordance.
void Concordance_Recursive::R_Write(ostream &out_s, Node *temp)
{
          if (temp != NULL)
          {
              if (strlen (temp -> wd) >= 7)
              {
                  out_s << " " << temp -> wd << "\t  " << temp -> count << endl;
              }
              else
              {
                  out_s << " " << temp -> wd << "\t\t  " << temp -> count << endl;
              }
              R_Write(out_s, temp -> next);
          }
}
//Function to return the length of the list(number of distinct words in the concordance)
int Concordance_Recursive::Length()
{
    return R_Length(first);
}
//Recursive Function for the Length() function.
int Concordance_Recursive::R_Length(Node *P)
{
    int l = 0;

    if (P == NULL)
        return 0;
    else
        l = (R_Length(P -> next) + 1);
    return l;
}
//Recursive function to insert a given word into the concordance, while maintaining alphabetical order.
//If the word to be inserted already exists in the concordance, then it will simply increment its count.
void Concordance_Recursive::Insert (Word w, Node * &p)
{
    if(p==NULL || strcmp(w, p->wd) == -1)
     {
          p = Get_Node(w,1,p);
     }
     else if (strcmp (w, p->wd)== 0)
     {
         (p->count)++;
         return;
     }
     else {
        Insert(w, p->next);
     }
}
//Function to Insert the elements of the Concordance, into the linked list.
void Concordance_Recursive::Insert(Word w)
{
    Insert (w, first);
}

