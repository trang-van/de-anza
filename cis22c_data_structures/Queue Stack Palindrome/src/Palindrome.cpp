/**

* Calista Tee and Trang van

* CIS 22C, Lab 3

* Palindrome.cpp

*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>		//To convert to lower
#include "Stack.h"
#include "Queue.h"
using namespace std;

// Function Prototypes
bool isPalindrome (Queue<char> &, Stack<char> &);
	// Compares the chars between the queue and stack
	// Returns true if all chars match, false otherwise


int main()
{
	const string filename = "palindrome.txt";
	ifstream fin;
	string expression;

	fin.open("palindrome.txt");

	if (fin.fail())
	{
		cout << "File not found!" <<endl;
		exit (-1);
	}


	while(getline(fin, expression))
	{
		Queue<char> Q;
		Stack<char> S;

		for(int i = 0; i < expression.length(); i++)
		{
			// Builds queue and stack with expression, by populating them with chars
			if (isalpha(expression[i]))
			{
				Q.enqueue(tolower(expression[i]));		// tolower will change all chars to lowercase
				S.push(tolower(expression[i]));
			}
		}


		// Tests if the expression is a Palindrome
		if (isPalindrome(Q,S))
		{
			cout << expression << " (Palindrome)"<< endl;
		} else
		{
			cout << expression << " (Not a Palindrome)"<< endl;
		}

	}

	fin.close();

	return 0;
}

// Tests if expression is a palindrome. Returns true if it is, false otherwise
bool isPalindrome (Queue<char> &Q, Stack<char> &S)
{
	for (int i = 0; i < Q.getSize(); i++) {
		if (Q.getFront() == S.peek()) {			// Compares the first value of the queue and stack
			S.pop();							// Removes the top
			Q.dequeue();						// Removes the front
		} else {
			return false;
		}
	}

	return true;
}

