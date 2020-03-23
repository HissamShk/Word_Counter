//CSCI 301
//PROJECT 4
//Word Counter
//Hissamuddin Shaikh
//This program utilizes the class, Concordance, to create a Concordance through a linked list,
//through a file inserted by the user. It exercises all the function of the Concordance class,
//and has error control present to allow the program to run smoothly.
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "concordance.h"
using namespace std;
void readWord();
//Post-Condition: Function to read in words from the file appropriately,
//                and pass them onto the Insert() function of the Concordance class, in the right format.
void openFile(ifstream &File, string FileName);
//Pre-Condition: Takes in the object, through which the data in the file will be accessed.
//               Takes in the name of the file to be opened.
//Post-Condition: Opens the file.
//Declaration of variables that will be used in Main and other functions in the Program
ifstream File;
Concordance C;
//Main Function
int main()
{   //Data Variables
    string FileName;
    //Displaying Prompt for File Name
    cout << endl;
    cout << " |Word Counter|" << endl;
    do{
            cout << endl;
            cout << " Enter the Name of an Existing Input File: ";
            //Opening the File
            getline (cin, FileName);
            openFile(File, FileName);} while(File.fail());
    //Inserting the words from the file, into a Concordance (linked list)
    readWord();
    //Displaying the Concordance
    cout << C;
    cout<<" The file contains "<<C.Length()<<" distinct words."<<endl;
    cout<<" Count of SMALL : "<<C.getCount("SMALL")<<endl;
    return 0;
}
void openFile(ifstream &File, string FileName)
{
    File.open(FileName.c_str());
}
void readWord()
{
     char Ch;
     char W[9];
     int I=0;
     while(File.get(Ch))
     {
          Ch = toupper(Ch);
          //Insert, only if the Characters are Alphabets
          if(Ch >= 65 && Ch <= 90)
          {
              //Save only up to 8 characters
              if(I<8)
                   W[I]=Ch;
              I++;
          }
          else
          {
              if(I>=8)
                   W[8]='\0';
              else
                   W[I]='\0';
              //Insert the Word
              if(I!=0)
              C.Insert(W);
              //Clear the Temporary Variable W
              for (int X = 0; X<9; ++X)
                W[X] = ' ';
              //w[0]=w[1]=w[2]=w[3]=w[4]=w[5]=w[6]=w[7]=w[8]=' ';
              I=0;
          }
     }
}
