//CSCI 301
//Concordance.h
//Concordance Class: A Class to implement a Concordance, through a Linked List
//Hissamuddin Shaikh
//This class contains a variety of functions, that allows for the creation of a Concordance. This is done through
//dynamically allocating memory space, and linking it through the use of pointers.
#ifndef CONCORDANCE_H
#define CONCORDANCE_H
#include <string>
using namespace std;
//Declaration of a Constant, that limits the length of the string that is inserted.
const int MAX = 8;
//Concordance List, which contains all the functions.
class Concordance
{
    public:
        //An Alias for the type assignment, to make it easier to change the type of Concordance, if necessary.
        typedef char Word[MAX+1];
        //Constructor
        Concordance();
        //Destructor
        ~Concordance();
        /*Modification and Query Functions*/
        void Insert(Word);
        //Pre-Condition: Takes in the Word, which is to be inserted into the Concordance.
        //Post-Condition: Places the Word into the Concordance, in the appropriate position
        //                (maintains alphabetical order, so as to main the Concordance's ordered nature.
        //                If the value already exists in the list, then it doesn't insert it, but simply increment's
        //                it's count
        int Length();
        //Post-Condition: Returns the number of distinct words present within the Concordance.
        int getCount(Word);
        //Pre-Condition: Takes in the Word, for which the number of occurrences is to be returned.
        //Post-Condition: Returns 0, if word is not present at all. Otherwise, returns the number of times
        //                it occurs in the concordance (one or more).
        friend ostream& operator << (ostream& out_s, const Concordance& c);
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
        bool StringCompare(Word A, Word B);
        void Insert(Word w, Node * &p);
};
#endif //CONCORDANCE_H


