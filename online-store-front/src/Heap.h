#ifndef HEAP_H_
#define HEAP_H_

#include <vector>
#include <iostream>
#include <cmath>
#include <assert.h>
#include <utility>
using namespace std;

template <class heapdata>
class Heap {
private:
    int heap_size;
    vector<heapdata> *heap;

    /**Helper Functions*/

    void heapify(int i);
    //helper function to build_heap, remove, and sort
    //bubbles an element down to its proper location within the heap

    void heap_increase_key(int i, heapdata key);
    //helper function to insert
    //bubbles an element up to its proper location

public:

    /**Constructors*/

    Heap(vector<heapdata> &v);
    //assigns heap to point to v, an unordered array
    //calls build_heap to convert the unordered array into a valid max heap

    /**Manipulation Procedures*/

    void build_heap();
    //Takes an unordered vector and builds it into a heap
    //Called as a helper function of the constructor
    //Calls heapify as a helper function

    void insert(heapdata value);
    //Inserts a new value onto the end of the heap and
    //Bubbles it up to the correct location in the heap
    //Calls heap_increase_key as a helper function

    void remove(int index);
    //removes the node at the provided index of the heap
    //pre: 1 <= i <= get_size()

    vector<heapdata> sort();
    //sorts a heap into ascending order
    //returns the sorted array of values
    //post: heap restored to max heap
    //calls build heap as a helper function
    //calls heapify as a helper function

    /**Access Functions*/

    heapdata get_max() const;
    //returns the maximum value in the heap
    //pre: heap_size > 0

    int get_parent(int i) const;
    //returns the location (index) of the element stored at index i
    //pre: 0 < i <= heap_size

    int get_left(int i)  const;
    //returns the location (index) of the left child of the element stored at i
    //pre: 0 < i <= heap_size

    int get_right(int i)  const;
    //returns the location (index) of the right child of the element stored at i
    //pre: 0 < i <= heap_size

    int get_size() const;
    //returns the heap_size (current number of elements

    heapdata get_element(int i) const;
    //returns the element at the specified index i
    //pre: 0 < i <= heap_size

    /**Additional Operations*/

    void displayHeap(ostream& out) const;
    //prints the heap in level order
    //Hint: level = floor(log2(i) + 1)

    void displayArray(ostream& out) const;
    //prints each element in the array (heap) separated by a comma

};

template <class heapdata>
void Heap<heapdata>::heapify(int i){
	int left = get_left(i), right = get_right(i), maxI = i;
	if(left<=heap_size && heap->at(left) > heap->at(i)){
		maxI=left;
	}
	if(right<=heap_size && heap->at(right) > heap->at(maxI)){
		maxI=right;
	}
	if(i!=maxI){
		swap(heap->at(i),heap->at(maxI));
		heapify(maxI);
	}
}

template <class heapdata>
void Heap<heapdata>::heap_increase_key(int i, heapdata key){
	int parent = get_parent(i);
	if(i>=2 && get_element(parent)<key){
		swap(heap->at(i),heap->at(parent));
		heap_increase_key(parent, key);
	}
}

/**Constructors*/

template <class heapdata>
Heap<heapdata>::Heap(vector<heapdata> &v){
	heap_size = v.size()-1;
	heap = &v;
	build_heap();
}

/**Manipulation Procedures*/

template <class heapdata>
void Heap<heapdata>::build_heap(){
	for(int n=heap_size/2; n>=1; n--){		// integer division
		heapify(n);
	}
}

template <class heapdata>
void Heap<heapdata>::insert(heapdata value){
	heap->push_back(value);
	heap_size++;
	heap_increase_key(heap_size,value);
}

template <class heapdata>
void Heap<heapdata>::remove(int index){
	assert(1<=index && index<= get_size());
	swap(heap->at(index),heap->at(heap_size));
	heap->pop_back();
	heap_size--;
	if(index<=heap_size){heapify(index);}
}

template <class heapdata>
vector<heapdata> Heap<heapdata>::sort(){
	vector<heapdata> v;
	int size = heap_size;

	while(heap_size){
		v.push_back(get_max());
		heap->at(1)=heap->at(heap_size);
		heapify(1);
		heap_size--;		// make these elements "invisible"
	}

	heap_size = size;
	build_heap();

	return v;
}

/**Access Functions*/

template <class heapdata>
heapdata Heap<heapdata>::get_max() const{
	assert(heap_size>0);
	return heap->at(1);
}

template <class heapdata>
int Heap<heapdata>::get_parent(int i) const{
	assert(0<i && i<=heap_size);
	return i/2;
}

template <class heapdata>
int Heap<heapdata>::get_left(int i)  const{
	assert(0<i && i<=heap_size);
	return i*2;
}

template <class heapdata>
int Heap<heapdata>::get_right(int i)  const{
	assert(0<i && i<=heap_size);
	return i*2+1;
}

template <class heapdata>
int Heap<heapdata>::get_size() const{
	return heap_size;
}

template <class heapdata>
heapdata Heap<heapdata>::get_element(int i) const{
	assert(0<i && i<=heap_size);
	return heap->at(i);
}

/**Additional Operations*/

template <class heapdata>
void Heap<heapdata>::displayHeap(ostream& out) const{
	int level = 1;
	for(int i=1; i<=heap_size; i++){
		if(floor(log2(i)+1)!=level){
			level++;
			out << endl;
		}
		out << heap->at(i).getID() << ":" << heap->at(i).getDateToShip() << " ";

	}
	out << endl;
}

template <class heapdata>
void Heap<heapdata>::displayArray(ostream& out) const{
	for(int i=1; i<=heap_size; i++){
		out << heap->at(i);
	}
	out << endl;
}

#endif /* HEAP_H_ */

