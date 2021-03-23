/**

* Calista Tee and Trang van

* CIS 22C, Lab 3

* StackTest.cpp

*/

/*
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

	cout << "===== STACK TEST =====" << endl;

	Stack<int> S;
	Stack<int> S2;

	// BUILDING LIST S
	cout << "\n ** BUILD STACK **" <<endl;

	cout << "Empty? Should print true: " << boolalpha << S.isEmpty() << endl;
	S.push(10);		// Last element
	S.push(3);
	S.push(5);
	S.push(8);		//Now the top

	cout << "Empty? Should print false: " << boolalpha << S.isEmpty() << endl;

	cout << "Should print 8 5 3 10:";
	S.displayStack(cout);

	cout << "\n ** POP FUNCTION TEST **" <<endl;

	S.pop();
	cout << "Should print 5 3 10: ";
	S.displayStack(cout);

	S.pop();
	cout << "Should print 3 10:";
	S.displayStack(cout);

	cout << "\n ** GET SIZE AND PEEK TEST **" <<endl;

	cout << "Size should be 2: " << S.getSize() << endl;
	cout << "Peek should print 3: " << S.peek() << endl;

	// BUILDING LIST Q2
	S2.push(5);
	S2.push(10);
	S2.push(3);

	cout << "\n ** COMPARE S AND S2 **" <<endl;

	cout << "Stack: ";
	S.displayStack(cout);

	cout << "Should print 3 10 5: ";
	S2.displayStack(cout);
	// Expecting 3 10 5

	if (S == S2) {
		cout << "Lists are equal" << endl;
	} else {
		cout << "Lists NOT equal." << endl;		//Expecting not equal
	}

	Stack<int> S_copy(S);

	cout << "\n ** BUILD STACK COPY **" <<endl;
	cout << "Stack: ";
	S.displayStack(cout);
	cout << "Stack Copy: ";
	S_copy.displayStack(cout);

	if (S == S_copy) {
		cout << "Lists are equal." << endl;		// Should be equal
	} else {
		cout << "Lists NOT equal." << endl;
	}

	return 0;
}

*/
/*
	 ===== STACK TEST =====

	 ** BUILD STACK **
	Empty? Should print true: true
	Empty? Should print false: false
	Should print 8 5 3 10:8 5 3 10

	 ** POP FUNCTION TEST **
	Should print 5 3 10: 5 3 10
	Should print 3 10:3 10

	 ** GET SIZE AND PEEK TEST **
	Size should be 2: 2
	Peek should print 3: 3

	 ** COMPARE S AND S2 **
	Stack: 3 10
	Should print 3 10 5: 3 10 5
	Lists NOT equal.

	 ** BUILD STACK COPY **
	Stack: 3 10
	Stack Copy: 3 10
	Lists are equal.

 */
