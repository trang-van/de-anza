// Assignment #2
// Trang Van
// Code::Blocks on Windows 10

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

//Function Prototypes
void sortDictionary (string[], int);
int  searchForKeywords (string, string[], int);

int main()
{
    const int DICTION_SIZE = 16000;
    const int KEY_SIZE = 84;

    string dictionFile = "unsorted_dictionary.txt";
    string keyFile = "keywords.txt";
    ifstream inDiction (dictionFile);
    ifstream inKey (keyFile);
    ofstream outFile ("keywordsNotFound.txt");

    string dictionary[DICTION_SIZE], keywords[KEY_SIZE];    //String arrays to hold file contents

    int numberNotFound = 0;                                 //Accumulates number of keywords not found


    // Checking both files for successful opening
    if(inDiction.fail() && inKey.fail())
    {
        outFile << "Error! Cannot open:" << dictionFile << " and " << keyFile << endl;
        exit (1);
    } else if (inKey.fail())
    {
        outFile << "Error! Cannot open: " << keyFile << endl;
        exit (1);
    } else if (inDiction.fail())
    {
        outFile << "Error! Cannot open: " << dictionFile << endl;
        exit (1);
    }

    // Read into file and store in array
    for (int i=0; i < DICTION_SIZE; i++)
    {
        if (!inDiction.eof())
        {
            inDiction >> dictionary[i];
        }

    }

    // Sorts Dictionary Array
    for (int i=0; i < DICTION_SIZE; i++)
    {
        sortDictionary(dictionary, DICTION_SIZE);

    }

    // Processes keywords file and searching for each keyword in dictionary array
    for (int i=0; i < KEY_SIZE; i++)
    {
        if (!inKey.eof())
        {
            inKey >> keywords[i];

        int returnValue = searchForKeywords(keywords[i],dictionary, DICTION_SIZE);

        if   (returnValue == -1)
        {
            outFile << "keyword not found: " << keywords[i] << endl;
            numberNotFound++;

        }
        }
    }

    cout << "Number of keywords not found = " << numberNotFound << endl;

    inDiction.close();
    inKey.close();
    outFile.close();
    return 0;
}

// Uses Selection Sort to sort dictionary
void sortDictionary(string dictionary[], int size)
{
    int minIndex;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i+1; j < size; j++)
        {
            if (dictionary[j] < dictionary[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)               //Swaps dictionary[] at index i and minIndex
        {
            string temp;
            temp = dictionary[i];
            dictionary [i] = dictionary[minIndex];
            dictionary[minIndex] = temp;
        }
    }
}

// Uses Binary Search to find each keyword from file
int searchForKeywords (string searchValue, string dictionary[], int array_size)
{
    int low =0,
        high = (array_size - 1),
        middle;

    while (low <= high)
    {
        middle = (low + high)/2;

        if (searchValue < dictionary[middle])
        {
                high = middle - 1;
        } else if (searchValue > dictionary[middle])
        {
                low = middle + 1;
        } else if (searchValue == dictionary[middle])
        {
                return middle;
        }
    }

    return -1;      //Means search value not found
}
