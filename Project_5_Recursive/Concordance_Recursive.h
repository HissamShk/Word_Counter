//CSCI 301
//Concordance_Recursive.h
//Concordance_Recursive Class: A Class to implement a Concordance, through a Linked List (through recursive functions)
//Hissamuddin Shaikh
//This class contains a variety of functions, that allows for the creation of a Concordance. This is done through
//dynamically allocating memory space, and linking it through the use of pointers.
//Moreover, it also makes use of recursive functions.
#ifndef CONCORDANCE_RECURSIVE_H
#define CONCORDANCE_RECURSIVE_H
#include <string>
using namespace std;
//Declaration of a Constant, that limits the length of the string that is inserted.
const int MAX = 8;
//Concordance List, which contains all the functions.
class Concordance_Recursive
{
    public:
        //An Alias for the type assignment, to make it easier to change the type of Concordance, if necessary.
        typedef char Word[MAX+1];
        //Constructor
        Concordance_Recursive();
        //Destructor
        ~Concordance_Recursive();
        /*Modification and Query Functions*/
        void Insert(Word);
        //Pre-Condition: Takes in the Word, which is to be inserted into the Concordance.
        //Post-Condition: Places the Word into the Concordance, in the appropriate position
        //                (maintains alphabetical order, so as to main the Concordance's ordered nature.
        //                If the value already exists in the list, then it doesn't insert it, but simply increment's
        //                it's count
        int Length();
        //Post-Condition: Returns the number of distinct words present within the Concordance.
        friend ostream& operator << (ostream& out_s, Concordance_Recursive& c);
        //Post-Condition: Allows for the contents of the respective Concordance to be written out,
        //                through the output stream out_s.
    private:
        //Data Members for the Class
        struct Node
        {
        Word wd;
        int count;
        Node *next;
        };
        Node *first;
        //Private Function
        Node *Get_Node(Word s, int c ,struct Node* nextPtr);
        //Post-Condition: Involved in the creation of the list,
        //                as it creates new Nodes and links them to the List.
        //                This is a pointer to the struct Node.,
        int R_Length (Node *P);
        //Recursive Function for the Length function, that delivers the Post-Condition
        void Give_Back(Node *p);
        //Recursive Function for the Destructor
        void R_Write(ostream & out_s, Node *temp);
        //Recursive Functions to output the contents of the concordance,
        //and is used in the output operator.
        void Insert(Word w, Node * &p);
        //Recursive Function for the Insert function, that delivers the Post-Condition
};
#endif //CONCORDANCE_RECURSIVE_H
