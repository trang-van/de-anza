/**

* Trang Van

* CIS 22C, Lab 2

*/

#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL
#include <assert.h>

using namespace std;

template <class listdata> //list stores generic listdata, not any specific C++ type
class List {

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

public:

/**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: Instantiates a List object with a default node

    List(const List&);
    //Copy constructor; Makes a deep copy from a list object to a new one
    //Postcondition: The contents of a list object will be copied to a new list with
    //				newly allocated memory for the copies

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: All Nodes of the corresponding List object will be deleted
    //				and freed from memory when the list goes out of scope

/**Accessors*/

    listdata getStart() const;
    //Returns the data at the start of the list
    //Precondition: length > 0
    //				There needs to be at least one node because
    //				you can't dereference a pointer to NULL

    listdata getStop() const;
    //Returns the data at the end of the list
    //Precondition: length > 0 or Needs to be at least one node in the list

    listdata getIterator() const;
    // Returns the element currently pointed at by the iterator
    // Precondition: iterator != NULL

    bool isEmpty() const;
    //Determines whether a list is empty.

    bool offEnd() const;
    // Returns whether the iterator is off the end of the list (ie. is NULL)

    int getLength() const;
    //Returns the size of the list

    bool operator==(const List&);
    //Tests two lists to determine whether their contents are equal
    //Postcondition: returns true if lists are equal and false otherwise

/**Manipulation Procedures*/

    void removeStart();
    //Removes the value stored in first node in the list
    //Precondition: length > 0
    //Postcondition: The first node along with its data and pointer to the next node
    //				will be removed.

    void removeStop();
    //Removes the value stored in the last node in the list
    //Precondition: length > 0
    //Postcondition: The last node along with its data and pointer to the next node
    //				will be removed.

    void insertStart (listdata data);
    //Inserts a new data at the beginning of the list
    //If the list is empty, the new data becomes both start and stop
    //Postcondition: There will be a new starting node with new data at the beginning of
    //				the list. If length > 0, all other nodes are pushed back.

    void insertStop(listdata data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both start and stop
    //Postcondition:There will be a new stop node with new data at the end of
    //				the list. Previous stop points to new node and new
    //				node will now point to NULL.

    void startIterator();
    //Moves the iterator to the start of the list
    //Precondition: NONE
    //Postcondition: The iterator will now point to the first element in the list.

    void removeIterator();
    //Removes the element currently pointed to by the iterator
    //Iterator then points to NULL
    //Precondition:	iterator != NULL
    //Postcondition: The element the iterator was pointing to is removed from the list.

    void insertIterator(listdata data);
    // Inserts an element after the node currently pointed to by the iterator
    // Precondition: !offEnd()
    // Postcondition: There will be a new node between the current iterator's node
    //				and the one next to it.

    void moveIterNext();
    // Moves up iterator by one node towards stop
    // Precondition: !offEnd(), iterator !=NULL
    // Postcondition: The iterator will now point to the next node, towards stop.
    void moveIterPrevious();
    // Moves down iterator by one node towards start
    // Precondition: !offEnd(), iterator != NULL
    // Postcondition: The iterator will now point to the previous node, towards start.

/**Additional List Operations*/

    void displayList(ostream&) const;
    // Prints the contents of the linked list to screen or file
    // 		separated by a blank space
    void displayNumberedList(ostream&) const;
    //Prints contents of the linked list to screen or file in the format
    // 		#: <element> followed by a newline
};



/*
 *
 *
 * FROM LIST.CPP
 *
 *
 */

/**Constructors and Destructors*/
#include "List.h"
#include <iostream>

template<class listdata>
List<listdata>::List()
{
	start = NULL;
	stop = NULL;
	iterator = NULL;
	length = 0;
}
	// Default constructor; initializes and empty list

template<class listdata>
List<listdata>::List(const List &list) {		//const because contents of List NOT changing
	if (list.start == NULL) //If the original list is empty, make an empty list for this list
	{

		start = stop = iterator = NULL;

	} else {
		start = new Node(list.start->data); //calling Node constructor, passing original list's start data
		Node* temp = list.start; //set a temporary node pointer to point at the start of the original list
		//Node* temp2 = list.stop;
		iterator = start; //set iterator to point to the start node of the new list

		while (temp->next != NULL) {

			temp = temp->next; //advance up to the next node in the original list
			iterator->next = new Node(temp->data); //using node constructor to create new node w/ copy of data
			iterator->next->previous = iterator;	// set prev pointer to new node
			iterator = iterator->next; //advance to this new node

		}

		stop = iterator; 	// iterator will go to last node, becomes new stop
		iterator = NULL;	//reset iterator

	}

	length = list.length;
}
	//Copy Constructor

template<class listdata>
List<listdata>:: ~List()
{
	Node* b = start;
	Node* a = NULL;
	while (b != NULL)
	{
		a = b->next;
		delete b;
		b = a;
	}
}
    //Destructor. Frees memory allocated to the list

/**Accessors*/

template<class listdata>
listdata List<listdata>::getStart() const
{
	assert(length !=0);
	return start->data;
}
    //Returns the data at the start of the list

template<class listdata>
listdata List<listdata>::getStop() const
{
	assert(length != 0);
	return stop->data;
}
    //Returns the data at the end of the list

template<class listdata>
listdata List<listdata>::getIterator() const
{
	assert(iterator != NULL);
	return iterator->data;
}
	//Returns data point at by the iterator

template<class listdata>
bool List<listdata>::isEmpty() const
{
	return length == 0;
}
    //Determines whether a list is empty.

template<class listdata>
bool List<listdata>::offEnd() const
{
	return iterator == NULL;
}
	//Determines if iterator is off the end of the list

template<class listdata>
int List<listdata>::getLength() const
{
	return length;
}
    //Returns the size of the list

template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(length != list.length)
        return false;
    Node* temp1 = start;
    Node* temp2 = list.start;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

/**Manipulation Procedures*/

template<class listdata>
void List<listdata>:: removeStart()
{
	assert(length != 0);
	if (length == 1)
	{
		delete start;
		start = stop = NULL;
		length = 0;
	} else
	{
		Node* temp = start;
		start = start->next;
		start->previous= NULL;// new start's previous points to null
		delete temp;
		length--;
	}
}
    //Removes the value stored in first node in the list

template<class listdata>
void List<listdata>::removeStop()
{
	assert(length != 0);
	if (length == 1)
	{
		delete stop;
		start = stop = NULL;
		length = 0;
	} else
	{
		Node* temp = start;
		while(temp->next != stop) //move temp to second to last node in list
		{
			temp = temp->next;
		}
		delete stop;
		stop = temp; //set stop to be the former second to last node stored in temp
		stop->next = NULL;//set pointer to point at NULL rather than deallocated memory
		length--;

	}
}
    //Removes the value stored in the last node in the list

template<class listdata>
void List<listdata>::insertStart (listdata data)
{
	Node* N = new Node(data);
	if (length == 0)
	{
		start = N;
		stop = N;
	} else
	{
		N->next = start;	// Sets the node next to the new one to the original start
		start->previous = N;
		start = N;			// Start is now the new node
	}

	length++;				//List length increased
}
    //Inserts a new data at the beginning of the list

template<class listdata>
void List<listdata>::insertStop(listdata data)
{
	Node* N = new Node(data);
	if (length == 0)
	{
		start = N;
		stop = N;
	} else
	{
		stop->next = N;		//Originally pointed to NULL, now points to the new node
		N->previous= stop;
		stop = N;			//Stop will now be the new node
	}
	length++;
}
    //Inserts a new data at the end of the list

template<class listdata>
void List<listdata>::startIterator()
{
	iterator = start;
}

	//Moves the iterator to the start of the list

template<class listdata>
void List<listdata>::removeIterator()
{
	assert(!offEnd());
	if(iterator == start)
	{
		removeStart();
	} else if (iterator == stop)
	{
		removeStop();
	} else
	{
		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->previous;
		delete iterator;
		iterator = NULL;
		length--;
	}
}
    //Removes the element currently pointed to by the iterator
    //Iterator then points to NULL

template<class listdata>
void  List<listdata>:: insertIterator(listdata data)
{
	assert(!offEnd());
	if(iterator == stop)
	{
		insertStop(data);
	} else {
		Node* N = new Node(data);
		N->previous = iterator;
		N->next= iterator->next;
		iterator->next->previous = N;
		iterator->next = N;
		length++;
	}
}
    // Inserts an element after the node currently pointed to by the iterator

template<class listdata>
void List<listdata>:: moveIterNext()
{
	assert(!offEnd());
	iterator = iterator->next;
}
    // Moves up iterator by one node towards stop

template<class listdata>
void List<listdata>:: moveIterPrevious()
{
	assert(!offEnd());
	iterator = iterator->previous;
}
    // Moves down iterator by one node towards start


/**Additional List Operations*/
template<class listdata>
void List<listdata>::displayList(ostream& out) const
{
	if(length == 0)
	{
		out <<""<< endl;
	}
	Node* temp = start;			//Temp iterator

	while (temp != NULL)
	{
		out << temp->data << ' ';			// Prints the item the iterator is pointing to
		temp = temp->next;		// Advances the pointer to the next node
	}

	out << endl;		// This ends the list and will go to a new line
}

	// Prints List object

template<class listdata>
void List<listdata>::displayNumberedList(ostream& out) const
{
	Node* temp = start;			//Temp iterator
	int i = 1;
	while (i < length + 1 && temp != NULL)
	{
		out << i <<':'<< temp->data << "\n";			// Prints the item the iterator is pointing to
		temp = temp->next;		// Advances the pointer to the next node
		i++;
	}

	out << endl;		// This ends the list and will go to a new line
}


#endif /* LIST_H_ */
