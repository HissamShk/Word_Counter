//CSCI 301
//Concordance.cpp
//Concordance Class: A Class to implement a Concordance, through a Linked List
//Hissamuddin Shaikh
#include "Concordance.h"
#include <iostream>
#include <cstring>
using namespace std;
//Constructor
Concordance::Concordance()
{
    first = NULL;
}
//Destructor
Concordance::~Concordance()
{
    Node *temp;
    while (first != NULL)
    {
        temp = first;
        first = first -> next;
        delete temp;
    }
}
//Private function
//Involved in the creation of the Concordance,
Concordance::Node *Concordance::Get_Node(Word s, int c, Node *nextPtr)
{
     Node *newNode = new Node;
     newNode->count = c;
     newNode->next = nextPtr;
     strcpy(newNode->wd,s);
     return newNode;
}
//Friend Function
//Function to allow the contents of the Concordance to be written out
ostream& operator << ( ostream& out_s, const Concordance& c )
  {
    Concordance::Node *temp;

    out_s << endl;
    out_s << " Word" << "\t\t" << "Count" <<endl;
    out_s <<" --------------------"<<endl;
    temp = c.first;
          while(temp!=NULL)
          {
              if (strlen(temp->wd) >= 7)
                {out_s<<' '<<temp->wd <<"\t  "<<temp->count <<endl;
                 temp=temp->next;}
              else
                {out_s<<' '<<temp->wd <<"\t\t  "<<temp->count <<endl;
                 temp=temp->next;}

          }
     out_s <<" --------------------"<<endl;
     out_s << endl;

    return out_s;
  }
//Function to return the number of occurrences for a particular word in the list
int Concordance::getCount(Word str)
{
     Node *temp;
     if(first ==NULL)
              return 0;
     else
     {
          temp=first;
          while(temp!=NULL)
          {
              if(strcmp(temp->wd,str)==0)
                   return temp->count;
              temp=temp->next;
          }
     }
     return 0;
}
//Function to return the length of the list(number of distinct words in the concordance)
int Concordance::Length()
{
     int l=0;
     Node *temp;

     if(first == NULL)
              return 0;
     else
     {
          temp=first;
          while(temp!=NULL)
          {
              temp=temp->next;
              l++;
          }
          return l;
     }
}
//Function to insert a given word into the concordance, while maintaining alphabetical order.
//If the word to be inserted already exists in the concordance, then it will simply increment its count.
/*bool Concordance::StringCompare(Word A, Word B)
{
    if (strcmp(A, B) < 0)
        return true;
    return false;
}*/
/*void Concordance::Insert (Word w, Node * &p) //Checks Out
{
    //cout<< strcmp(w, p->wd) << endl;
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
void Concordance::Insert(Word w)
{
    Insert (w, first);
}*/
void Concordance::Insert(Word w)
{
     Node *newNode,*temp,*prev;

     if(first==NULL)
     {
          first = Get_Node(w,1,NULL);
     }

     else
     {
          prev = temp = first;

          while(strcmp(temp->wd,w)<=0 && temp->next!=NULL)
          {
              prev = temp;
              if(strcmp(temp->wd,w)==0)
              {
                   temp->count=temp->count+1;
                   return;
              }
              temp=temp->next;
          }

          if( temp==first && strcmp(temp->wd,w)>0 )
          {
              newNode = Get_Node(w,1,first);
              first = newNode;
          }
          else if( temp==first && strcmp(temp->wd,w)<0 )
          {newNode = Get_Node(w,1,NULL);
           first -> next=newNode;}
          else
          {
              if(temp -> next == NULL)
              {
                   if(strcmp(temp->wd,w)<0 )
                   {
                        newNode = Get_Node(w,1,NULL);
                        temp->next = newNode;
                   }
                   else
                   {newNode = Get_Node(w,1,temp);
                    prev->next = newNode;}
              }
              else
              {newNode = Get_Node(w,1,temp);
               prev->next = newNode;}
          }
     }
}

