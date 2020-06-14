/***********************************************************************
* Program:
*    Project 10, Madlib Fist Draft  
*    Brother Christensen, CS124
* Author:
*    Filipe Ferreira
* Summary: 
*    This first draft read the file and ask the user to imput
*    the words.
*    Estimated:  3.0 hrs   
*    Actual:     7.0 hrs
*      The most difficult difficult was to use poiner and compare the
*      caracters with the words. and codtions and everything
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void getFile(char* pfile);
int readFile(char file[256], char story[][32]);
void askQuestions(char story[]);
void display(int numWords, char story[][32]);

/******************************************************
* This is our driven fuction that will called the onther
* fuctions
*******************************************************/
int main()
{
   char answer = 'n';
   
   do
   {
   //Get the file name thourgh a string and pointer
      char file[256];
      getFile(file);
   
      cin.ignore();
   
   //drive our read file by passing our file
      char story[256][32];
      int numWords = readFile(file, story);
   
   //Will send the data to the display
      display(numWords, story);

   //Prompt to use the question to check for the while loop
      cout << endl << "Do you want to play again (y/n)? ";
      cin  >> answer;
   }
   while (answer == 'y');

   // in case the answer is no "n" finish the program
   cout << "Thank you for playing." << endl;
   
   return 0;
}

/******************************************************
* Prompt the user for the name of the file
******************************************************/
void getFile(char file[])
{
   //Prompt the user for the file name
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> file;
}

/*******************************************************
* This fuction will be responsable for read our file
* and ask the right question whenever needed
*******************************************************/
int readFile(char file[256], char story[][32])
{
   //Open our file
   ifstream readFile(file);
   if (readFile.fail())
   {
      cout << "Unable to open file " << file << endl;
   }

   //This code will read the file and track the number of words
   int numWords = 0;
   while (numWords < 256 && readFile >> story[numWords])
   {
    
      askQuestions(story[numWords]);
            
      numWords++;
   }
   
   
   return numWords;
   
}

/**********************************************************
* This fuction is responsible for asking questions according
* with what was found on the text
***********************************************************/
void askQuestions(char story[])
{

   //Check the madlib text and check for the key points to change
   if (story[0] == ':' and isalpha(story[1]))
   {
      // display the header
      cout << "\t" << (char)toupper(story[1]);

      // display the rest of the phrase
      for (int n = 2; story[n]; n++)
      {
         if (story[n] == '_')
         
            cout << " ";
         
         else
         
            cout << (char)tolower(story[n]);
      }

      // Give the option to the user to enter the variable prompted
      cout << ": ";
      cin.getline(story, 256);
   }

}
                 
/*************************************************************
* Our disply fuction will be display word by word through a
* a loop and check the condition
*************************************************************/
void display(int numWords, char story[][32])
{
   cout << endl;

   // Set the codition for my display message
   for (int i = 0; i < numWords; i++)
   {
      //check the coditions for my characters
      if (isalpha(story[i][0]) && isalpha(story[i + 1][0]))
      {
         cout << story[i] << " ";
      }
      else if (story[i][0] == ':' && story[i][1] == '!')
      {
         cout << "\n";
      }
      else if (story[i][0] == ':' && story[i][1] == '.'
               && isalpha(story[i + 1][0]))
      {
         cout << ". ";
      }
      else if (story[i][0] == ':' && story[i][1] == '.')
      {
         cout << ".";
      }
      else if (story[i][0] == ':' && story[i][1] == ','
               && isalpha(story[i + 1][0]))
      {
         cout << ", ";
      }
      else if (story[i][0] == ':' && story[i][1] == ',')
      {
         cout << ",";
      }

      // This part manage the quotes situation
      else if (isalpha(story[i - 1][0]) && story[i][0] == ':'
               && story[i][1] == '<')
      {
         cout << " \"";
      }
      else if (isalpha(story[i + 1][0]) && story[i][0] == ':'
               && story[i][1] == '>')
      {
         cout << "\" ";
      }
      else if (story[i][0] == ':' && story[i][1] == '>'
               && story[i + 1][0] == ':' && story[i + 1][1] == '<')
      {
         cout << "\" ";
      }
      
      else if (story[i][0] == ':' && story[i][1] == '<')
      {
         cout << "\"";
      }
      else if (story[i][0] == ':' && story[i][1] == '>')
      {
         cout << "\"";
      }
      else if (isalpha(story[i][1]) && story[i + 1][0] == '\"')
      {
         cout << story[i] << " ";
      }
      else if (isalpha(story[i + 1][0]) && story[i][0] == '\"')
      {
         cout << story[i] << " ";
      }
                  
      else
      {
         cout << story[i];
      }
      
   }

}
      


