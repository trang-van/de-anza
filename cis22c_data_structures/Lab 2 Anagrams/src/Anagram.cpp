/**

* Trang Van

* CIS 22C, Lab 2

*/

#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

/*
 *Function Prototypes
 */

void readInFile(ifstream &);
// Reads into the file to get each word
// Passes the word into the arranger() function

void arranger(string);
// Builds list and runs the anagram functions
// Runs a while loops to let users constantly rearrange words
// Prints final rearrangement to output file

int main() {

	string filename;

	// Get file from user
	cout << "Welcome to the Anagram Arranger!\n"<< endl;
	cout << "Please enter the name of your input file: ";
	cin  >> filename;

	ifstream fin(filename);

	while (fin.fail())
	{
		cout << "\nSorry. I cannot find a file by that name!"<< endl;
		cout << "Please enter the name of a valid input file: ";
		cin  >> filename;
		fin.open(filename);
	}

	readInFile(fin);

	cout << "\nBye!"<<endl;

	fin.close();

	return 0;
}

// Reads into the given file and passes each word into the arranger(0) function
void readInFile(ifstream &fin)
{
	string word;			// Stores word read in from file
	int numOfWord =0;		// Counts the word to tell user Word #1, 2, etc.
	if(fin)
	{
		while(fin>>word)
		{
			numOfWord++;
			cout << "\nWord #" << numOfWord << " is " << word << endl;
			arranger(word);
		}
	}
}

void arranger(string word)
{
	List<char> w;								// Puts word from file to a List object
	ofstream fout("output.txt", ios_base::app);	// Creates output file for final rearrangement of word
	int pos1, pos2;								// For user to input position of which letters they want to swap
	char userResponse;							// (y/n) for user to continue arranging
	bool isValid = true;						// To test pos1 and pos2 input

	// Builds List with word from file
	for (unsigned int i = 0; i < word.length(); i++)
	{
		w.insertStop(word[i]);
	}

	// Displays the word
	// Prompts user to input positions they want to swap
	do
	{
		w.displayNumberedList(cout);
		cout << "Enter the position numbers of the two letters you wish to swap: ";
		cin >> pos1 >> pos2;

		//Test cases for valid inputs
		if (pos1 > w.getLength() || pos2 > w.getLength())
		{
			cout << "Invalid entry!\n"<<endl;
			isValid = false;
			continue;
		} else if (pos1 > pos2)
		{
			cout << "Invalid entry!\n"<<endl;
			isValid = false;
			continue;
		} else if (pos1 == pos2)
		{
			cout << "Invalid entry!\n"<<endl;
			isValid = false;
			continue;
		} else
		{
			isValid = true;
		}

		// Shows user the positions they've chosen to switch
		cout <<"\n";
		w.displayList(cout);

		for (int i = 1; i <= w.getLength(); i++)
		{
			if (i == pos1 || i == pos2)
			{
				cout << "^ ";
			} else
			{
				cout << "  ";
			}
		}

		cout << endl;

		// Confirms if the letters are in the right position
		cout << "Are these the letters you wish to swap? (y/n): ";
		cin  >> userResponse;
		cout << "\n";

		if (userResponse == 'Y' || userResponse == 'y')
		{
			//Swapping values
			w.startIterator();

			for (int i = 1; i < pos1; i++)
			{
				w.moveIterNext();			//Get iterator to pos1 from start
			}

			char value1 = w.getIterator();		// Store value at pos1

			for (int i = pos1; i < pos2; i++)
			{
				w.moveIterNext();			//Get iterator to pos2 from pos1
			}

			char value2 = w.getIterator();		// Store value at pos2

			w.insertIterator(value1);
			w.removeIterator();

			w.startIterator();

			for (int i = 1; i < pos1; i++)
			{
				w.moveIterNext();
			}

			w.insertIterator(value2);
			w.removeIterator();

			cout << "The new word is: ";
			w.displayList(cout);
			cout << endl;

		} else if(userResponse == 'N' || userResponse == 'n')
		{
			isValid = false;
			continue;
		}

		cout << "Want to keep rearranging? (y/n): ";
		cin  >> userResponse;

		if (userResponse == 'Y' || userResponse == 'y')
		{
			isValid = false;
			continue;
		} else if (userResponse == 'N' || userResponse == 'n')
		{
			break;
		}

	} while (isValid != true);

	w.displayList(fout);
}
