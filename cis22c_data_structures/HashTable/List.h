/**

* Calista Tee & Trang Van

* CIS 22C, Lab 4

*/


#ifndef LIST_H_
#define LIST_H_

#include <assert.h>
#include "List.h"
#include <iostream>
#include <fstream>
#include <cstddef> //for NULL
using namespace std;

template <class listdata> //list stores generic listdata, not any specific C++ type
class List{

private:
    struct Node {
        listdata data;
        Node* next;
        Node* previous;

        Node(listdata newData){
            data = newData;
            next = NULL;
            previous = NULL;
        }
    };

    Node* start;
    Node* stop;
    Node* iterator;
    int length;

	//*Helper* function for the public displayReverse wrapper function.
	//Recursively prints the data in a List in reverse.
	//WHY DO WE NEED THIS?: Our nodes are private, we have no access if the function
	//is called inside of main
	void displayReverse(Node* node, ostream& out) const {
		if (node == NULL) {
			return;
		} else {
			displayReverse(node->next, out);

			out << node->data << " ";
		}
		//	cout <<endl;
	}

	//Helper function for the public isSorted() function.
	//Recursively determines whether a list is sorted in ascending order.
	bool isSorted(Node* node) const {

		if (node == NULL || node->next == NULL) {
			return true;
		} else {
			return (node->data < node->next->data && isSorted(node->next));
		}
	}

	//Recursively search the list by dividing the search space in half
	//Returns the index of the element, if it is found in the List
	//Returns -1 if the element is not in the List
	//Post: The iterator location has not been changed
	int binarySearch(int low, int high, listdata data) const {

		if (high < low) {
			return -1;
		}

		int mid = low + (high-low)/2;		// midpoint formula

		Node* temp = start;
		for (int i = 1; i < mid; i++)
		{
			temp = temp->next;
		}

		if (temp->data == data){
			return mid;
		}

		else if (data < temp->data)	// search left half
		{
			return binarySearch(low, mid-1, data);
		}else 							// search right half
		{
			return binarySearch(mid+1, high, data);
		}
	}

public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes an empty list
    //Postcondition: Empty list is initialized

    List(const List &list);
    //Copy constructor
    //Makes a copy of the list object
    //Postcondition: List object will be copied successfully

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: Memory in the list is freed

    /**Accessors*/

    listdata getStart() const;
    //Returns the data at the start of the list
    //Precondition: The list is not empty, first node is not null

    listdata getStop() const;
    //Returns the data at the end of the list
    //Precondition: The last value contains null pointer

    bool isEmpty(); //const;
    //Determines whether a list is empty.

    int getLength() const;
    //Returns the size of the list

    listdata getIterator() const;
    //Returns the element currently pointed at by the iterator
    //Precondition: length != 0, iterator != NULL, iterator must not be offEnd

    bool offEnd() const;
    //Returns whether the iterator is off the end of the list (ex: if it's NULL)

    bool operator==(const List &list);
    //Tests two lists to determine whether their contents are equal
    //Postcondition: returns true if lists are equal and false otherwise

    bool isSorted() const;
    //Wrapper function that calls the isSorted helper function to determine whether
    //a list is sorted in ascending order.
    //We will consider that a list is trivially sorted if it is empty.
    //Therefore, no precondition is needed for this function

    int getIndex() const;
    //Indicates the index of the Node where the iterator is currently pointing
    //Nodes are numbered starting at 1 through the size of the list
    //Pre: !offEnd()

    int linearSearch(listdata data) const;
    //Iteratively searchs the list, element by element, from the start of the List to the end of the List
    //Returns the index of the element, if it is found in the List
    //Does not call the indexing functions in the implementation
    //Returns -1 if the element is not in the List
    //Pre: length != 0
    //Post: The iterator location has not been changed

    int binarySearch(listdata data) const;
    //Returns the index where data is located in the List
    //Calls the private helper function binarySearch to perform the search
    //Pre: length != 0
    //Pre: List is sorted (must test on a sorted list)
    //Post: The iterator location has not been changed

    /**Manipulation Procedures*/

    void removeStart();
    //Removes the value stored in first node in the list
    //Precondition: The list is not empty
    //Postcondition: First node is removed

    void removeStop();
    //Removes the value stored in the last node in the list
    //Precondition: The list is not empty
    //Postcondition: Value in last node is removed

    void insertStart (listdata data);
    //Inserts a new data at the beginning of the list
    //If the list is empty, the new data becomes both start and stop
    //Postcondition: Data contains new start value

    void insertStop(listdata data);
    //Inserts a new data at  the end of the list
    //If the list is empty, the new data becomes both start and stop
    //Postcondition: Data contains new value at the end of the list

    void startIterator();
    //Moves the iterator to the start of the list

    void removeIterator();
    //Removes the element currently pointed to by the iterator
    //Iterator then points to NULL

    void insertIterator(listdata data);
    //Inserts an element after the node currently pointed to by the iterator
    //Postcondition: new node is inserted in the list

    void moveIterNext();
    //Moves the iterator up by one node towards stop
    //Precondition: !offEnd(), iterator != NULL

    void moveIterPrevious();
    //Moves the iterator down by one node towards start
    //Precondition: iterator != NULL

    void moveToIndex(int index);
    //Moves the iterator to the node whose index number is specified in the parameter
    //Nodes are numbered starting at 1 through the size of the List
    //Pre: size != 0
    //Pre: index <= size

    /**Additional List Operations*/

     void displayList() const;
   // void displayList() const;
    //Prints to the console the value of each data in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty..

     void displayNumberedList(ostream& out);
    //Prints the contents of the LL to the screen or a file
    //in the format #: <element> followed by a newline

     void displayReverse(ostream& out) const;
     //Wrapper function that calls the private displayReverse helper function to print a list in reverse
     //prints nothing if the List is empty

};

// Constructor
//Constructs new LL object
template<class listdata>
List<listdata>::List() {
	length = 0;
	start = NULL;
	stop = NULL;
	iterator = NULL;
}

// Copy Constructor
// Makes a copy of the list object
template<class listdata>
List<listdata>::List(const List &list) {
	if (list.start == NULL) //If the original list is empty, make an empty list for this list
	{
		start = stop = iterator = NULL;
	} else {
		start = new Node(list.start->data); //calling Node constructor
		Node* temp = list.start; //set a temporary node pointer to point at the start of the original list
		iterator = start; //set iterator to point to the start node of the new list

		while (temp->next != NULL) {
			temp = temp->next; //advance up to the next node in the original list
			iterator->next = new Node(temp->data); //using node constructor to create new node w/ copy of data
			iterator->next->previous = iterator;	// set prev pointer to new node
			iterator = iterator->next; //advance to next node
		}
		stop = iterator; // assign stop to end of dupe node
		iterator = NULL;
	}
	length = list.length;
}


// Destructor
//Frees the memory associated with the LL
template<class listdata>
List<listdata>::~List()
{
    Node* b = start;
    Node* a = NULL; //a stands for "after" (i.e. after b)
    while (b != NULL) {
	        a = b->next; //move a to node after b
	        delete b; //remove b (you know it is not NULL from if)
	        b = a; //b "catches up" with a (both point to same place in list)
	  }
}

// accessors

//Returns the data at the start of the list
template<class listdata>
listdata List<listdata>::getStart() const
{
	assert(length != 0);

	return start -> data;

}

//Returns the data at the end of the list
template<class listdata>
listdata List<listdata>::getStop() const
{
	assert(length != 0);
    return stop -> data;
}

//Determines whether a list is empty
template<class listdata>
bool List<listdata>::isEmpty() //const
{
    return (length == 0);
}

//Returns the size of the list
template<class listdata>
int List<listdata>::getLength() const
{
	return length;
}

//Returns the element currently pointed at by the iterator
template<class listdata>
listdata List<listdata>::getIterator() const
{
	assert(iterator != NULL);

	return iterator->data;
}

//Returns whether the iterator is off the end of the list (ex: if it's NULL)
template<class listdata>
bool List<listdata>::offEnd() const
{
	if (iterator == NULL) {
		return true;
	} else {
		return false;
	}
}

//To override the == operator to compare two lists
template<class listdata>
bool List<listdata>::operator==(const List &list)
{
	if(length != list.length) {
		return false;
	}

	Node* temp1 = start;
	Node* temp2 = list.start;

	while(temp1 != NULL) {
		if (temp1->data != temp2->data) {
			return false;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
}

//Indicates the index of the Node where the iterator is currently pointing
//Nodes are numbered starting at 1 through the size of the list
template <class listdata>
int List<listdata>::getIndex() const {
	assert(!offEnd());

	Node *temp = start;
	int count = 1; // index starts with 1 instead of 0 according to lists

	while(temp != iterator) {
		count++;
		temp = temp->next;
	}
	return count;

}

//Iteratively searchs the list, element by element, from the start of the List to the end of the List
//Returns the index of the element, if it is found in the List
//Does not call the indexing functions in the implementation
//Returns -1 if the element is not in the List
template <class listdata>
int List<listdata>::linearSearch(listdata data) const {
	assert(length != 0);

	Node* temp = start;
	int index = 1;

	while(temp != NULL) {
		if (temp->data == data) {
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}

//Returns the index where data is located in the List
//Calls the private helper function binarySearch to perform the search
template <class listdata>
int List<listdata>::binarySearch(listdata data) const {

	assert(length != 0);
	assert(isSorted());

	return binarySearch(1, getLength(), data);


}

// manipulation procedures

//Removes the value stored in first node in the list
template<class listdata>
void List<listdata>::removeStart()
{
	assert(length != 0);

   if(length == 1)
    {
        delete start;
        iterator = start = stop = NULL;
        length = 0;
    }
    else
    {
        Node* temp = start;
        start = start->next;
        start->previous = NULL;
        delete temp;
        length--;
    }
}

//Removes the value stored in the last node in the list
template<class listdata>
void List<listdata>::removeStop()

{
    assert(length != 0);

	if (length == 1) {

        delete stop;
        iterator = start = stop = NULL;
        length = 0;

    } else {
    	assert (stop != NULL);	//make sure last node is not on NULL

        Node* temp = stop;
        stop = stop->previous;	//assign second last node as stop
        delete temp;
        stop->next = NULL;		//new stop pointing to NULL

        length--;
    }

}

//Inserts a new data at the beginning of the list
//If the list is empty, the new data becomes both start and stop
template<class listdata>
void List<listdata>::insertStart(listdata data)
{
    Node* N = new Node(data);	//create new node

    if (length == 0)
    {
        start = N;
        stop = N;
    }
    else
    {
        N->next = start;	//next pointer of new node pointed to the former start
        start->previous = N;	//point it back w doubly linked list
        start = N;		//new node becomes the starting point
    }
    length++;
}

//Inserts a new data at the end of the list
//If the list is empty, the new data becomes both start and stop
template<class listdata>
void List<listdata>::insertStop(listdata data) {

	Node* N = new Node(data);	//create new node

	if (length == 0)	//if list is empty, new node = start = stop
	{
		start = N;
		stop = N;
	}
	else				//if list is not empty
	{
		Node* temp = stop;		//temp pointer pointing the last node
		temp->next = N;			//create new node next to last node
		stop = N;				//new node is last node
		N->previous = temp;		//new node previous is pointing to former last node
		N->next = NULL;			//new last node pointing to NULL

		//temp->next = stop;		//make new node the last node
	}

	length++;
}

//Moves the iterator to the start of the list
template<class listdata>
void List<listdata>::startIterator()
{
	iterator = start;	//iterator point to the first node of the list/return iterator to beginning of list
}

//Removes the element currently pointed to by the iterator
//Iterator then points to NULL
template<class listdata>
void List<listdata>::removeIterator()
{
	assert(iterator != NULL);

	if (iterator==start) {
		removeStart();
	} else if (iterator==stop) {
		removeStop();
	} else {
		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->previous;
		delete iterator;
		iterator = NULL;
		length--;
	}
}

//Inserts an element after the node currently pointed to by the iterator
template<class listdata>
void List<listdata>::insertIterator(listdata data)
{
	assert(iterator != NULL);

	if (iterator == stop) {
		insertStop(data);
	} else {
		Node* N = new Node(data);
		N->previous = iterator;
		N->next = iterator->next;
		iterator->next->previous = N;
		iterator->next = N;

		length++;
}
}

//Moves the iterator up by one node towards stop
template<class listdata>
void List<listdata>::moveIterNext()
{
	assert(iterator != NULL);

	iterator = iterator->next;	//new value
}

//Moves the iterator down by one node towards start
template<class listdata>
void List<listdata>::moveIterPrevious()
{
	assert(iterator != NULL);

	iterator = iterator->previous;
}

//Wrapper function that calls the isSorted helper function to determine whether
//a list is sorted in ascending order.
//We will consider that a list is trivially sorted if it is empty.
//Therefore, no precondition is needed for this function
template<class listdata>
bool List<listdata>::isSorted() const {

	return isSorted(start);

}

//Moves the iterator to the node whose index number is specified in the parameter
//Nodes are numbered starting at 1 through the size of the List
template <class listdata>
void List<listdata>::moveToIndex(int index) {

	assert (length != 0); 	//or length?
	assert(index <= length);

	iterator = start;

	for (int i = 1; i < index; i++) {
		moveIterNext();
	}
}

// additional list operations

//Prints to the console the value of each data in the list sequentially
//and separated by a blank space
//Prints nothing if the list is empty
//Prints a empty newline character if it's empty
template<class listdata>
void List<listdata>::displayList() const
{
    Node* temp = start; //create a temporary iterator

    while (temp != NULL) {

    	cout <<temp->data <<"\n";	//single line data w/ whitespace
    	temp = temp->next;

    }
    cout << endl; //flush out all contents to console/file

}

//Prints the contents of the LL to a screen/file in the format #:<element> followed by newline
template<class listdata>
void List<listdata>::displayNumberedList(ostream& out)
{
	int current = 1;
	Node* temp = start; //create a temporary iterator

	while (temp != NULL) {
			out <<current <<": " <<temp->data  <<endl;	//format: #: <element>
	    	temp = temp->next;

	    	current++;
			}

	out << endl; //flush out all contents to console/file
}

//Wrapper function that calls the private displayReverse helper function to print a list in reverse
//prints nothing if the List is empty
template<class listdata>
void List<listdata>::displayReverse(ostream& out) const {

	if (getLength() == 0) {
			out <<"";
	} else {
		displayReverse(start, out);
		out <<endl;
	}
}





#endif /* LIST_H_ */
