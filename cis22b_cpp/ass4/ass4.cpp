// Assignment #4
// Trang Van
// Code::Blocks on Windows 10

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

const string filename = "unsorted_keywordsPROG.txt";
const string programname = "oldass3.cpp";

//Function Prototypes
void sort(string[], int);
int searchForKeywords (char*, string*);

int main()
{
    ifstream inFile(filename);
    ifstream inProgram (programname);

   //Check for successful file opening
   if(inFile.fail() && inProgram.fail())
    {
        cout << "Error! Cannot open:" << filename << " and " << programname << endl;
        exit (1);
    } else if (inFile.fail())
    {
        cout << "Error! Cannot open: " << filename << endl;
        exit (1);
    } else if (inProgram.fail())
    {
        cout << "Error! Cannot open: " << programname << endl;
        exit (1);
    }

   // Reads into file to get amount of words
   string buffer;                    // Stores the row read from getline
   int count = 0;                    // Number of keywords for memory size
   int numberOfKeywords=0;           // Counts keywords found in program file

   while (!inFile.eof())
   {
       getline (inFile, buffer);
       if(buffer.size() > 0)
       {
           count++;
       }
   }

    inFile.close();

    // Allocate memory for number of words
    string* data= new string[count];

    inFile.open(filename);

    for (int i = 0; i < count; i++)
    {
        getline(inFile, data[i]);
        if(inFile.eof()) break;             //Checks for end of file
    }

    inFile.close();

    //Read and parse program file
    char* program = new char[100];
    char buf2[100];

    int lineCount = 0;                           //Keeps track of number of lines

    while (!inProgram.eof())
    {
        inProgram.getline(buf2, sizeof(buf2));
        if (inProgram.eof()) break;
        lineCount++;

        program = strtok(buf2, " #&:;*,""//(){}[]\n\r<>+!=-");

      while (program != NULL)
      {
            cout << "Line " << lineCount << ": "<< program << endl;
            program = strtok(NULL, " #&:;*,""//(){}[]\n\r<>+!=-");
            if (strstr(buf2, "//") > 0)     //SKIPS OVER LINE (HOW??)
            {
                inProgram.ignore();
            }
      }
    }

    sort(data, count);

    //Searching for keywords
    for (int i = 0; i < count; i++)
    {

       // int returnValue = searchForKeywords(program, data[i]);
       /* if (returnValue > 0)
        {
            cout << data[i] << "(" << returnValue <<  ")" << endl;
            numberOfKeywords++;
        } */
    }

    cout << "\n" << "Number of keywords found = " << numberOfKeywords << endl;

    delete [] data;

    inProgram.close();

    return 0;
}

// Uses Selection Sort to sort keywords
void sort(string a[], int size)
{
    int minIndex;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i+1; j < size; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)               //Swaps a[] at index i and minIndex
        {
            string temp;
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

//Search .cpp file for keywords
int searchForKeywords (char* program, string* keyword)
{
    char* pos = strstr(program, keyword);
    if (pos)
    {
        return //??;
    }
}
