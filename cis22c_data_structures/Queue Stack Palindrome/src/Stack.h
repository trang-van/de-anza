/**

* Calista Tee and Trang van

* CIS 22C, Lab 3

* Stack.h

*/

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <cstddef>
#include <assert.h>

using namespace std;

template <class stackdata>
class Stack
{
    public:
        /**constructors and destructors*/

        Stack();

        //initializes an empty stack
        //postcondition: an empty stack

        Stack(const Stack &S);
        //initializes this stack to have same elements as S
        //postcondition: a copy of stack


        ~Stack();
        //frees memory allocated to the stack
        //postcondition: memory for stack has been freed

        /**manipulation procedures*/

        void pop();
        //removes an element from the top of the stack
        //precondition: size != 0
        //postcondition: an element has been removed from the top of the stack

        void push(stackdata data);
        //adds an element to the top of the stack
        //postcondition: an element added to the top of the stack

        /**accessors*/


       bool operator==(const Stack &S);
       //returns whether this stack is equal to another stack S

       stackdata peek() const;
       //returns the element at the top of the stack
       //precondition: size != 0

       int getSize() const;
       //returns the size of the stack

       bool isEmpty() const;
       //returns whether the stack is empty


       /**additional operations*/

       void displayStack(ostream& out) const;
       //prints the elements in the stack each element separate by a blank space to stdout

    private:
       struct Node {
           stackdata data;
           Node* next;

           Node(stackdata ndata) {
                data = ndata;
                next = NULL;
          }
       };

       Node* top;
       int size;

};

template <class stackdata>
Stack<stackdata>:: Stack()
{
	top = NULL;
	size = 0;
}

template <class stackdata>
Stack<stackdata>:: Stack(const Stack &S)
{
	if (S.top == NULL)
	{
		top = NULL;
		size = 0;
	} else
	{
		top = new Node(S.top->data);
		Node* temp = S.top;
		Node * temp2 = top;

		size = 1;

		while (temp->next != NULL)
		{
			temp = temp->next;		// from original list
			temp2->next= new Node(temp->data);
			size++;
		}

	}
}

template <class stackdata>
Stack<stackdata>::~Stack()
{
	Node* b = top;
	Node* a= NULL;
	while (b != NULL)
	{
		a = b->next;
		delete b;
		b = a;
	}
}

template <class stackdata>
void Stack<stackdata>:: push(stackdata data)
{
	Node* N = new Node(data);
	if (size == 0)
	{
		top = N;
	} else
	{
		N->next = top;
		top = N;
	}

	size ++;
}

template <class stackdata>
void Stack<stackdata>::pop()
{
	assert(size != 0);

	if (size==1) {
		delete top;
		top = NULL;
	} else {
		Node* temp = top;
		top = top->next;
		delete temp;
	}
	size--;
}

template <class stackdata>
stackdata Stack<stackdata>::peek() const
{
	assert (size != 0);
	return top->data;
}

template <class stackdata>
int Stack<stackdata>::getSize() const
{
	return size;
}

template <class stackdata>
bool Stack<stackdata>::isEmpty() const
{
	return size == 0;
}

template <class stackdata>
bool Stack<stackdata>::operator==(const Stack &S)
{
	if (size != S.size) {
		return false;
	} else {
		Node* temp1 = top;
		Node* temp2 = S.top;

		while (temp1 != NULL) {
			if (temp1->data != temp2->data) {
					return false;
			} else {
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
	}
	return true;

}

template <class stackdata>
void Stack<stackdata>:: displayStack(ostream& out) const
{
	Node * temp = top;

	while (temp != NULL)
	{
		out << temp->data << ' ';
		temp = temp->next;
	}

	out << endl;
}


#endif /* STACK_H */
