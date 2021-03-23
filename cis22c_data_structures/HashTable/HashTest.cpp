/*
 * HashTest.cpp
 *
 *  Created on: 23 May 2018
 *      Author: Calista
 */

// TEST FILE

#include "HashTable.h"

int main() {
	 HashTable ht;

	 Book pp("Pride and Prejudice", "Jane Austen", 4.95, 1234567);
	 Book c("Contact", "Carl Sagan", 9.95, 99993339);
	 Book hg("The Hunger Games", "Suzanne Collins", 13.55, 12388888);
	 Book hp("Harry Potter", "J.K. Rowlings", 12.99, 55555678);
	 Book mhc("The Man in the High Castle", "Philip K Dick", 15.95, 95959595);
	 Book bh("Bleak House", "Charles Dickens", 8.00, 473890238);

	 ht.insert(pp);
	 ht.insert(c);
	 ht.insert(hg);
	 ht.insert(mhc);
	 ht.insert(bh);

	 ht.printBucket(cout,9);	// should print "the hunger games" & "the main in the high castle"

	 int bucket = ht.search(pp);

	 cout << bucket <<"\n" <<endl;

	 //ht.remove(hg);

	 ht.printBucket(cout, 9);	// should only see man in the castle

	 ht.printTable(cout);
}
