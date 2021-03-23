/*
 * HashTable.cpp
 *
 *  Created on: 22 May 2018
 *      Author: Calista
 */

// Function Definitions for HashTable.h

#include "HashTable.h"
#include <string>
#include <assert.h>

int HashTable::hash(string key) const
{
	int sum = 0;

	for (int i= 0; i < key.length(); i++)
	{
		sum += (int)key[i];
	}

	return sum % SIZE;
}

int HashTable::countBucket(int index) const
{
	assert(index >= 0 and index < SIZE);

	return Table[index].getLength();

}

int HashTable::search(Book b) const
{
	int index = hash(b.get_title()+b.get_author());
	int pos;

	if (countBucket(index) ==0)
	{
		return -1;
	} else {
		pos = Table[index].linearSearch(b);
		if (pos != -1)
		{
			return index;
		} else {
			return pos;
		}
	}
}

void HashTable::insert(Book b)
{
	int id = hash(b.get_title() + b.get_author());

	Table[id].insertStop(b);

	//Table[id]->b = insertStop(b);
}

void HashTable::remove(Book b)
{
	int id = hash(b.get_title() + b.get_author());		// determine book index

	int pos = Table[id].linearSearch(b);					// search book position within index

	Table[id].moveToIndex(pos);

	Table[id].removeIterator();

}

void HashTable::printBucket(ostream& out, int index) const
{

	assert(index >= 0 and index < SIZE);

	Table[index].displayList();

}

void HashTable::printTable(ostream& out) const {

	Book b;
	out <<"Books in the Catalogue: \n" <<endl;

	for (int i = 0; i < SIZE; i++) {
		if (countBucket(i) >= 1) {
			out <<"Group " << i+1 <<endl;

			//Table[i].displayList();		// Print out the all books from the same index

			while (b != NULL) {
				out <<b->title <<" ";
				b = b->next;
			}
			cout << "+" << countBucket(i) - 1 << " more book(s)\n\n\n"  << endl;
		} else {
			out << "";
		}
	}




}
