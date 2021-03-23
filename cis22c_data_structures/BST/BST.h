/*
 * Calista Tee & Trang Van
 *
 * LAB 6: BST
 *
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <string>
#include <assert.h>
#include <ostream>		// For out

using namespace std;

template<typename bstdata>

class BST {
private:
    struct Node {
        bstdata data;
        Node* left;
        Node* right;

        Node(bstdata newdata){
            data = newdata;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    /**Private helper functions*/
    void insertHelper(Node* root, bstdata data);
    //private helper function for insert
    //recursively inserts a value into the BST

    void inOrderPrintHelper(ostream& out, Node* root) const;
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest

    void preOrderPrintHelper(ostream& out, Node* root) const;
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order

    void postOrderPrintHelper(ostream& out, Node* root) const;
    //private helper function for postOrderPrint
    //recursively prints tree values in post order

    void copyHelper(Node* copy);
    //recursive helper function to the copy constructor

    void destructorHelper(Node* root);
    //private helper function for the destructor
    //recursively frees the memory in the BST

    bool searchHelper(Node* root, bstdata data) const;
    //recursive helper function to search
    //returns whether the value is found in the tree

    bstdata minimumHelper(Node* root) const;
    //recursive helper function to minimum
    //returns the minimum value in the tree

    bstdata maximumHelper(Node* root) const;
    //recursive helper function to maximum
    //returns the maximum value in the tree

    Node* removeHelper(Node* root, bstdata data);
    //recursive helper function to remove
    //removes data from the tree

    void getSizeHelper(Node* root, int& size)const;
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size

    int getHeightHelper(Node* root) const;
    //recursive helper function to the height function
    //returns the height of the tree

public:

    /**constructors and destructor*/

    BST();
    //Instantiates a new BST

    BST(const BST &bst);
    //copy constructor

    ~BST();
    //deallocates the tree memory

    /**access functions*/

    bstdata minimum() const;
    //returns the minimum value in the BST
    //pre: !empty()

    bstdata maximum() const;
    //returns the maximum value in the BST
    //pre: !empty()

    bool isEmpty() const;
    //determines whether the BST is empty

    int getSize()const;
    //returns the size of the tree

    bstdata getRoot() const;
    //returns the value stored at the root of the BST
    //pre: !isEmpty()

    int getHeight() const;
    //returns the height of the tree

    bool search(bstdata data) const;
    //returns whether the data is found in the tree
    //pre: !isEmpty()

    /**manipulation procedures*/

    void insert(bstdata data);
    //inserts new data into the BST

    void remove(bstdata data);
    //removes the specified value from the tree
    //pre: data is located in the tree
    //pre: !isEmpty()

    /**additional functions*/

    void inOrderPrint(ostream& out) const;
    //calls the inOrderPrint function to print out the values
    //stored in the BST

    void preOrderPrint(ostream& out) const;
    //calls the reOrderPrint function to print out the values
    //stored in the BST

    void postOrderPrint(ostream& out) const;
    //calls the postOrderPrint function to print out the values
    //stored in the BST
};
#endif /* BST_H_ */

// CONSTRUCTOR
template <class bstdata>
BST<bstdata>::BST() {
	root = NULL;
}


// COPY CONSTRUCTOR
template <class bstdata>
void BST<bstdata>::copyHelper(Node* copy)
{
	if(copy)
	{
		insert(copy->data);
		copyHelper(copy->left);
		copyHelper(copy-> right);
	}

}

template <class bstdata>
BST<bstdata>::BST(const BST &bst) {
	 root=NULL;
	 copyHelper(bst.root);
}


//DESTRUCTOR
template <class bstdata>
void BST<bstdata>::destructorHelper(Node* root) {
	if (root != NULL)
	{
		destructorHelper(root->left);
		destructorHelper(root->right);
		delete root;
	}
}


template <class bstdata>
BST<bstdata>::~BST()
{
	destructorHelper(root);
}

// ACCESS FUNCTION
template <class bstdata>
bstdata BST<bstdata>::getRoot() const {
	assert(!isEmpty());

	return root->data;
}

// *INSERT* PRIVATE HELPER FUNCTION
template <class bstdata>
void BST<bstdata>::insertHelper(Node* root, bstdata data) {
	if (data == root->data)
	{
		return;
	} else if (data < root->data)
	{
		if (root->left == NULL)
		{
			root->left = new Node(data);
		} else
		{
			insertHelper(root->left, data);
		}

	}else
	{
		if (root->right == NULL)
		{
			root->right = new Node(data);
		} else
		{
		insertHelper(root->right, data);
		}
	}
}


// *INSERT* WRAPPER FUNCTION
template <class bstdata>
void BST<bstdata>::insert(bstdata data)
{
    if (root == NULL)
    {
        root = new Node(data); //if the tree is empty insert the value at the root
    }
    else
    {
        insertHelper(root, data); //otherwise call the helper function, passing it the root
    }
}

template <class bstdata>
bool BST<bstdata>::isEmpty() const
{
	return root == NULL;
}



//*GETSIZE* HELPER

template <class bstdata>
void BST<bstdata>::getSizeHelper(Node* root, int& size) const
{
	if (root != NULL)
	{
		getSizeHelper(root->left, size);
		size +=1;
		getSizeHelper(root->right, size);
	}
}

// *GETSIZE* WRAPPER
template <class bstdata>
int BST<bstdata>::getSize()const
{
	int size = 0;
	getSizeHelper(root, size);
	return size;
}


// DISPLAY FUNCTIONS
template <class bstdata>
void BST<bstdata>::inOrderPrintHelper(ostream& out, Node* root) const
{
	if (root != NULL)
		{
			inOrderPrintHelper(out,root->left);
			out << root->data <<" ";
			inOrderPrintHelper(out,root->right);
		}
}

//calls the inOrderPrint function to print out the values
//stored in the BST

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream& out) const
{
	if (isEmpty()) {
		out <<"";
	} else {
		inOrderPrintHelper(out, root);
	}

	out <<endl;
}

template <class bstdata>

void BST<bstdata>::preOrderPrintHelper(ostream& out, Node* root) const
{
	if (root != NULL)
	{
		out << root->data <<" ";
		preOrderPrintHelper(out,root->left);
		preOrderPrintHelper(out,root->right);
	}
}


//calls the reOrderPrint function to print out the values
//stored in the BST
template <class bstdata>
void BST<bstdata>::preOrderPrint(ostream& out) const
{
	if (isEmpty())
	{
		out << "";
	} else {
		preOrderPrintHelper(out, root);
	}

	out << endl;
}

// *POST ORDER PRINT* HELPER
//private helper function for postOrderPrint
//recursively prints tree values in post order
template <class bstdata>
void BST<bstdata>::postOrderPrintHelper(ostream& out, Node* root) const {
	if (root != NULL) {
		postOrderPrintHelper(out, root->left);
		postOrderPrintHelper(out, root->right);
		out << root->data << " ";

	} else {
		return;
	}
}


// *POST ORDER PRINT* WRAPPER
//calls the postOrderPrint function to print out the values
//stored in the BST
template <class bstdata>
void BST<bstdata>::postOrderPrint(ostream& out) const {

	if (isEmpty())
	{
		out << "";
	} else
	{
		postOrderPrintHelper(out, root);
	}

	out <<endl;

}

// SEARCH HELPER
template <class bstdata>
bool BST<bstdata>::searchHelper(Node* root, bstdata data) const
{
	if (data == root ->data){
		return true;
	} else if (data < root->data)
	{
		if (root->left == NULL)
		{
			return false;
		} else
		{
			searchHelper(root->left, data);
		}
	}else
	{
		if (root->right == NULL)
		{
			return false;
		} else
		{
			searchHelper(root->right, data);

		}
	}
}

// SEARCH WRAPPER
template <class bstdata>
bool BST<bstdata>::search(bstdata data) const
{
	assert(!isEmpty());
	if (data == root->data)
	{
        return true;
	}else
	{
		return searchHelper(root, data); //call helper function
	}
}


template <class bstdata>
bstdata BST<bstdata>::minimumHelper(Node* root) const
{
	if (root->left != NULL) {
		minimumHelper(root->left);
	} else {
		return root->data;
	}
}

template <class bstdata>
bstdata BST<bstdata>::minimum() const
{
	assert(!isEmpty());
	return minimumHelper(root->left);
}

template <class bstdata>
bstdata BST<bstdata>::maximumHelper(Node* root) const {
	if (root->right != NULL) {
		maximumHelper(root->right);
	} else {
		return root->data;
	}
}

template <class bstdata>
bstdata BST<bstdata>::maximum() const {
	assert(!isEmpty());
	return maximumHelper(root->right);
}


template <class bstdata>
typename BST<bstdata>::Node* BST<bstdata>::removeHelper(Node* root, bstdata data)
{
	if (root == NULL)
	{
		return root;
	} else if (data < root->data)
	{
		root->left = removeHelper(root->left, data);
	} else if (data > root->data)
	{
		root->right = removeHelper(root->right, data);
	} else {
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		} else if (root->left != NULL && root->right == NULL)
		{
			Node*temp = root;
			root = root->left;
			delete temp;
		} else if (root->left == NULL && root->right != NULL)
		{
			Node*temp = root;
			root = root->right;
			delete temp;
		} else
		{
			int minVal = minimumHelper(root->right);
			root->data = minVal;
			root->right = removeHelper(root->right, minVal);
		}
	}

	return root;

}

template <class bstdata>
void BST<bstdata>::remove(bstdata data)
{
	assert(!isEmpty());
	removeHelper(root,data);
}

// getHeight Helper
template <class bstdata>
int BST<bstdata>::getHeightHelper(Node* root) const
{
	int lHeight = -1;
	int rHeight = -1;

	if (root == NULL)
	{
		return 0;
	}

	if (root->left != NULL)
	{
		lHeight = getHeightHelper(root->left);

	}else if (root->right != NULL)
	{
		rHeight = getHeightHelper(root->right);
	}

	if (lHeight > rHeight)
	{
		return lHeight +1;
	} else {
		return rHeight +1;
	}

}

// getHeight Wrapper
template <class bstdata>
int BST<bstdata>::getHeight() const
{
	return getHeightHelper(root);
}

