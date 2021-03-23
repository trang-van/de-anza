/*
 * Calista Tee & Trang Van
 *
 * LAB 6: BST
 *
 */

#include <iostream>
#include "BST.h"

using namespace std;

int main() {

	BST<int> B;

	cout << "Is it empty? (Should be true): " << boolalpha << B.isEmpty() <<endl;

	// TESTING INSERT FUNCTION
	cout << "\n*** TESTING INSERT FUNCTION ***"<< endl;

	B.insert(5);
	B.insert(3);
	B.insert(6);
	B.insert(9);
	B.insert(0);
	B.insert(2);
	B.insert(7);
	B.insert(12);
	B.insert(4);


	cout << "\nIs it empty? (Should be false): " << boolalpha << B.isEmpty() <<endl;

	// TESTING GETSIZE() AND GETHEIGHT()
	cout << "\n***Get size and height of tree...***" << endl;
	cout << "\nTree size (Should be 9): " << B.getSize() << endl;
	cout << "\nTree height (Should be 3): " <<B.getHeight() << endl;

	//TESTING TREE TRAVERSALS
	cout << "\n*** TESTING TREE TRAVERSALS ***"<< endl;

	cout << "\nPre Order: ";
	B.preOrderPrint(cout);
	cout << "Post Order: ";
	B.postOrderPrint(cout);
	cout << "In Order: ";
	B.inOrderPrint(cout);

	// TESTING GETROOT()
	cout << "\nGet root...(should be 5):" << B.getRoot() << endl;

	//TESTING MIN AND MAX
	cout << "Root minimum is 0: " <<B.minimum() <<endl;
	cout << "Root maximum is 12: " <<B.maximum() <<endl;

	//TESTING SEARCH()
	cout <<"\nSearch for 5 (True=found): " << boolalpha << B.search(5) << endl;
	cout <<"Search for 0 (True=found): "<< boolalpha << B.search(0) << endl;
	cout << "Search for 4 (True=found): "<<boolalpha << B.search(4) << endl;
	cout <<"Search for 11 (Should be false): " << boolalpha << B.search(11)<< endl;

	cout << "\nTree size (Should be 8): " << B.getSize() << endl;
	cout << "Tree height (Should be 3): " <<B.getHeight() << endl;

	// Copy Constructor
	BST<int> B2(B);

	cout << "***TESTING COPY CONSTRUCTOR***" << endl;
	cout << "\nORIGINAL TREE: " << endl;
	B.preOrderPrint(cout);

	cout << "COPY TREE: " << endl;
	B2.preOrderPrint(cout);

	//TESTING REMOVE()
	cout << "\n*** TESTING REMOVE FUNCTION ***"<< endl;
	B.remove(6);
	cout << "\nRemove 6 (root->right):" << endl;
	B.preOrderPrint(cout);
	cout << endl;

	B.remove(5);
	cout << "Remove 5 (the root)- Expecting 9 for the root:" << endl;
	B.preOrderPrint(cout);
	cout << endl;

	cout << "\nTree size (Should be 7): " << B.getSize() << endl;
	cout << "Tree height (Should be 3): " << B.getHeight() << endl;

	cout << "\n*** Add node to tree to change height ***" << endl;
	B.insert (1); // To change height
	cout << "Tree height (Should be 4): " << B.getHeight() << endl;
	B.preOrderPrint(cout);
	cout << endl;


	// TEST 2
	BST<int> B3;

	B3.insert(15);
	B3.insert(10);
	B3.insert(9);
	B3.insert(7);
	B3.insert(5);
	B3.insert(6);
	B3.insert(20);
	B3.insert(17);

	cout << "***TEST 2***" <<endl;
	B3.preOrderPrint(cout);
	cout << endl;
	cout << "Tree size (Should be 8): " << B3.getSize() << endl;
	cout << "Tree height (Should be 5): " <<B3.getHeight() << endl;

	cout << "\n***TEST 2- COPY CONSTRUCTOR***" << endl;

	BST<int> B4(B3);
	cout << "\nORIGINAL TREE: " << endl;
	B3.preOrderPrint(cout);

	cout << "COPY TREE: " << endl;
	B4.preOrderPrint(cout);

	// TESTING GETROOT()
	cout << "\nGet root...(should be 15):" << B3.getRoot() << endl;

	//TESTING MIN AND MAX
	cout << "Root minimum is 5: " <<B3.minimum() <<endl;
	cout << "Root maximum is 20: " <<B3.maximum() <<endl;

	//SEARCH()

	cout << "\nSearch for 6 (True): " <<B3.search(6) << endl;
	cout << "Search for 25 (False): " <<B3.search(25) << endl;

}

/*
 *
 * RESULTS

	Is it empty? (Should be true): true

	*** TESTING INSERT FUNCTION ***

	Is it empty? (Should be false): false

	***Get size and height of tree...***

	Tree size (Should be 9): 9

	Tree height (Should be 3): 3

	*** TESTING TREE TRAVERSALS ***

	Pre Order: 5 3 0 2 4 6 9 7 12
	Post Order: 2 0 4 3 7 12 9 6 5
	In Order: 0 2 3 4 5 6 7 9 12

	Get root...(should be 5):5
	Root minimum is 0: 0
	Root maximum is 12: 12

	Search for 5 (True=found): true
	Search for 0 (True=found): true
	Search for 4 (True=found): true
	Search for 11 (Should be false): false

	Tree size (Should be 8): 9
	Tree height (Should be 3): 3
	***TESTING COPY CONSTRUCTOR***

	ORIGINAL TREE:
	5 3 0 2 4 6 9 7 12
	COPY TREE:
	5 3 0 2 4 6 9 7 12

	*** TESTING REMOVE FUNCTION ***

	Remove 6 (root->right):
	5 3 0 2 4 9 7 12

	Remove 5 (the root)- Expecting 9 for the root:
	7 3 0 2 4 9 12


	Tree size (Should be 7): 7
	Tree height (Should be 3): 3

	*** Add node to tree to change height ***
	Tree height (Should be 4): 4
	7 3 0 2 1 4 9 12

	***TEST 2***
	15 10 9 7 5 6 20 17

	Tree size (Should be 8): 8
	Tree height (Should be 5): 5

	***TEST 2- COPY CONSTRUCTOR***

	ORIGINAL TREE:
	15 10 9 7 5 6 20 17
	COPY TREE:
	15 10 9 7 5 6 20 17

	Get root...(should be 15):15
	Root minimum is 5: 5
	Root maximum is 20: 20

	Search for 6 (True): true
	Search for 25 (False): false
 *
 */

