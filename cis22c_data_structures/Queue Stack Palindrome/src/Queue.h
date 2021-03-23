/**

* Calista Tee and Trang van

* CIS 22C, Lab 3

* Queue.h

*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cstddef>
#include <assert.h>
using namespace std;

template<class queuedata>
class Queue {
public:
    /**constructors and destructors*/

    Queue();
    //initializes an empty queue
    //post: an empty queue created with default values for all fields

    Queue(const Queue &Q);
    //initializes queue to have same elements as another queue
    //post: a deep copy of queue

    ~Queue();
    //frees memory allocated to the queue
    //post: memory for queue has been freed

    /**manipulation procedures*/

    void dequeue();
    //removes an element from the front of the queue
    //pre: size!=0
    //post: an element removed from the front of the queue

    void enqueue(queuedata data);
    //adds an element to the end of the queue
    //post: an element added to the end of the queue

    /**accessors*/

    bool operator==(const Queue &Q);
    //returns whether this queue is equal to another queue

    queuedata getFront() const;
    //returns the element at the front of the queue
    //pre: size != 0

    int getSize() const;
    //returns the size of the queue

    bool isEmpty() const;
    //returns whether the queue is empty

    /**additional queue operations*/
    void displayQueue(ostream& out) const;
    //prints the elements in the queue separated by a blank space

private:
    struct Node {

        queuedata data;
        Node* next;
        Node(queuedata d) {
            next = NULL;
            data = d;

        }
    };

    Node* front;
    Node* end;
    int size;

};

template<class queuedata>
Queue<queuedata>::Queue()
{
	front = end = NULL;
	size = 0;
}

template<class queuedata>
Queue<queuedata>::Queue(const Queue &Q)
{
	if (Q.front == NULL)		//creates an empty queue
	{
		front = end = NULL;
		size = 0;
	} else
	{
		front = new Node(Q.front->data);
		Node* temp = Q.front;
		Node* temp2 = front;

		size = 1;

		while(temp->next != NULL)
		{
			temp = temp->next;
			temp2->next= new Node(temp->data);
			size++;
		}

		end = temp2;
	}
}

template<class queuedata>
Queue<queuedata>::~Queue()
{
	Node* b = front;
	Node* a = NULL;
	while (b != NULL)
	{
		a = b->next;
		delete b;
		b = a;
	}
}

template<class queuedata>
void Queue<queuedata>::dequeue()
{
	assert(size != 0);

	if(size==1) {
		delete front;
		front = end = NULL;
		size = 0;
	} else {
		Node* temp = front;
		front = front->next;
		delete temp;
		size--;
	}
}

template<class queuedata>
void Queue<queuedata>::enqueue(queuedata data)
{
	Node* N = new Node(data);

	if(size==0) {
		front = end = N;
	} else {
		end->next = N;
		end = N;	//set end to new node
	}
	size++;
}

//Question: For stack, does size matter? What's different b/w queue and stack?
template<class queuedata>
bool Queue<queuedata>::operator==(const Queue &Q)
{
	if(size != Q.size)
	{
		return false;
	}

	Node* temp1 = front;
	Node* temp2 = Q.front;

	while(temp1 != NULL)
	{
		if(temp1->data != temp2->data)
		{
			return false;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
}

template<class queuedata>
queuedata Queue<queuedata>::getFront() const
{
	assert(size != 0);
	return front->data;
}

template<class queuedata>
int Queue<queuedata>::getSize() const
{
	return size;
}

template<class queuedata>
bool Queue<queuedata>::isEmpty() const
{
	return size==0;
}

template<class queuedata>
void Queue<queuedata>::displayQueue(ostream &out) const
{
	Node* temp = front;

	while(temp!=NULL) {
		out <<temp->data <<" ";
		temp = temp->next;
	}

	out<<endl;
}


#endif /* QUEUE_H_ */
