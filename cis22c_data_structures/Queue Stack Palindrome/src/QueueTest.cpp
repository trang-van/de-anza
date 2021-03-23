/**

* Calista Tee and Trang van

* CIS 22C, Lab 3

* QueueTest.cpp

*/

/*
#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main() {

	Queue<int> Q;
	Queue<int> Q2;

	cout << "===== QUEUE TEST =====" <<endl;

	// BUILDING LIST Q

	cout << "\n** ENQUEUEING TEST **" <<endl;
	cout<<"Empty? Should be true: " << boolalpha << Q.isEmpty() <<endl;
	Q.enqueue(10);
	Q.enqueue(3);
	Q.enqueue(5);
	Q.enqueue(8);

	cout<<"Empty? Should be false: " <<Q.isEmpty() <<endl;

	cout<<"Should print 10 3 5 8:" <<endl;
	Q.displayQueue(cout);

	cout << "\n** DEQUEUEING TEST **" <<endl;
	Q.dequeue();
	cout<<"Should print 3 5 8:" <<endl;
	Q.displayQueue(cout);

	Q.dequeue();
	cout<<"Should print 5 8:" <<endl;
	Q.displayQueue(cout);

	cout << "\n** GET SIZE AND FRONT TEST **" <<endl;
	cout << "Size should be 2: " << Q.getSize() <<endl;
	cout << "Get front should print 5: " <<Q.getFront() <<endl;

	// BUILDING QUEUE Q2
	cout << "\n** BUILD QUEUE Q2 ** " <<endl;
	Q2.enqueue(5);
	Q2.enqueue(10);

	cout<<"Q2 should print 5 10:" <<endl;
	Q2.displayQueue(cout);

	cout << "\n** COMPARE Q AND Q2 **" <<endl;

	if (Q == Q2)
	{
		cout << "Lists are equal." <<endl;
	} else
	{
		cout << "Lists NOT equal." <<endl;		//Expecting not equal
	}

	cout << "\n** BUILD COPY OF Q **" <<endl;
	Queue<int> Q_copy(Q);

	cout << "Queue:";
	Q.displayQueue(cout);
	cout << "Queue Copy: ";
	Q_copy.displayQueue(cout);

	if (Q== Q_copy)
	{
		cout << "Lists are equal." <<endl;	//Expecting not equal
	} else
	{
		cout << "Lists NOT equal." <<endl;
	}


	return 0;
}
*/

/*
 	===== QUEUE TEST =====

	** ENQUEUEING TEST **
	Empty? Should be true: true
	Empty? Should be false: false
	Should print 10 3 5 8:
	10 3 5 8

	** DEQUEUEING TEST **
	Should print 3 5 8:
	3 5 8
	Should print 5 8:
	5 8

	** GET SIZE AND FRONT TEST **
	Size should be 2: 2
	Get front should print 5: 5

	** BUILD QUEUE Q2 **
	Q2 should print 5 10:
	5 10

	** COMPARE Q AND Q2 **
	Lists NOT equal.

	** BUILD COPY OF Q **
	Queue:5 8
	Queue Copy: 5 8
	Lists are equal.
	 *
 */
