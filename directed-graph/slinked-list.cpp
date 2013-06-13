/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/25/2011
 * HW: HW3P3
 * Compiler: G++
 * Compilation line: g++ app.cpp linked-list.cpp slinked-list.cpp
 * Implementation of a Searchable Linked List
 * Description:
 * The implementation of a single-linked list with search and replace functionality.
 * As well as a copy constructor and overloaded assignment operator
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Searchable Linked List implementation file */

#include <iostream>
#include "slinked-list.h"

using namespace std;

// Overloaded assignment operator.
// Note that OtherOne is being passed by reference
// The resulting List will be returned by reference
// This is used because the normal assignment operator wouldn't follow pointers
// If the object being assigned to is the original object, it merely returns it back
// Otherwise it clears the old contents of the list, then populates it with "OtherOne"
slist& slist::operator=(const slist& OtherOne)
{
	// First make sure this-> and OtherOne are not the same object.
	// To do this, compare the pointers to the objects.
	if (&OtherOne != this)
	{
		// In case we are copying into a list with existing entries,
		// this-> object has to be emptied first.
		el_t elem;
		while (!this->isEmpty())	// Loops through, deleting until empty
		{
			this->deleteRear(elem);  
		}
		
		// temp is a pointer we use to copy elements from OtherOne, starting at the beginning
		Node* temp = OtherOne.front;
		
		// Note, we add to rear from the front of the OtherOne to preserve order.
		while (temp != NULL)	// Loops until you reach the end of OtherOne. 
		{
			this->addRear(temp->Elem);	//temp’s element is added to this->
			temp = temp->Next;					// Go to the next node in OtherOne 
		}
	}
	return *this;		// Return this, whether it is the same object or a different one
}


// This is a copy constructor.
// This creates a copy of the Original list, item for item.
// Note that the Original is being passed to the constructor by reference
// to create a new object as a copy of the Original
// This is used because the default copy constructor does not follow pointers
// The function intializes an empty list, then fills it iteratively item-by-item 
slist::slist(const slist& Original)
{
	// Start by initializing the private data members of the new list.
	front = NULL;
	rear = NULL;
	count = 0;

	// temp is a pointer we use to copy elements from Original, starting at the beginning
	Node* temp = Original.front;  

	// Note, we add to rear from the front of the OtherOne to preserve order.
	while (temp != NULL)	// Loops until you reach the end of Original.
	{
		this->addRear(temp->Elem);	//temp’s element is added to this->
		temp = temp->Next;					// Go to the next node in OtherOne   
	}
	// Nothing to return, we've filled this object by reference
}

// Overloaded equality-test operator.
// This operator is used to see if two list objects are identical (they have the same content).
// There are a few cases which let you immediately decide the equality is true or false:
// 	Lists are definitely the same if one of the following is true: (return(true);)
// 		Case 1) if both lists are empty,
// 		Case 2) if they are the same object (they share the same memory location).
// 	Lists are definitely not identical if: (return(false);)
// 		Case 3) if the lists are different sizes.
// 	After these test cases are checked,
// 	you must then iterate through both lists, comparing each item
// 	As soon as you find a difference, you (return(false);)
bool slist::operator==(const slist& OtherOne)
{
	// Case 1
	// if they are both empty, they're the same (contents identical)
	// Note that the case where one is empty but the other is not is covered by case 3
	if (OtherOne.isEmpty() && this->isEmpty())
	{
		return true;
	}

	// Case 2
	// If they point the same location in memory, they must be the same object.
	// If they're the same object they must be equal.
	if (&OtherOne == this)
	{
		return true;
	}
	
	// Case 3
	// if they are of different sizes, they must be different
	if (count != OtherOne.count)
	{
		return false;
	}
	
	// finally, if they both have the same number of items,
	// but aren't pointing to the same memory location, and aren't both empty
	// we must go through element by element
	
	// We'll need a pair of node pointers, each will point to the same location in one list
	Node* P_this = front;
	Node* P_other = OtherOne.front;
	
	while (P_this != NULL)	// Loop until the end of the list (or we find a difference)
	{
		if (P_this->Elem != P_other->Elem)	// Check for equality of elements
		{
			return false;
		}

		P_this = P_this->Next;
		P_other = P_other->Next;
	}
	// lastly, if we go through the list without returning, all the elements are the same
	// and the lists are equal
	return true;
}


// Searches for an element in the linked list,
// If found, returns the position of the element,
// Else, returns 0.
// Note, if an element appears twice, search() will return the first occurance.
// Iterates over the list, following node->Next,
// until we either find the element or reach the end of the list.
int slist::search(el_t Key)
{
	// First check if the list is empty
	if (isEmpty())
	{
		throw Underflow();
	}
	
	Node *key_node = front; // key_node will eventually point to the node with our element

	int key_index = 1; // key_index is the counter we use to track the position

	// we loop until we reach the end of the node, or find the element.
	while (key_node != NULL)
	{
		if (key_node->Elem == Key)
		{
			return(key_index); // if we find the right element, return its position.
		}
		else // else, increment the position counter, and set node to be the next node.
		{
			key_index++;
			key_node = key_node->Next;
		}
	}
	return(0); // fail
}

// Goes to the Ith node in the list, and replaces its element with the paramter
// First checks that I is valid for this list (within the bounds, list isn't empty)
// Finally, if I is valid, loop through the list until we get to the Ith node,
// Then replace it's Elem.
void slist::replace(el_t Elem, int I)
{
	// Check if I is within the list bounds
	if ((I < 1) || (I > count+1))
	{
		throw OutOfRange();
	}
	// And that the list is not empty
	else if (isEmpty())
	{
		throw Underflow();
	}
	else
	{
		// key_node will eventually point to the node whose element we replace
		Node *key_node = front;

		// We loop through the node until we get to the Ith node.
		for (int i = 1; i < I; i++)
		{
			key_node = key_node->Next;
		}
		
		// Then just replace its Elem
		key_node->Elem = Elem;
	}
}

// This constructor initializes our data to indicate the list is empty.
slist::slist()
{
	front = NULL;
	rear = NULL;
	count = 0;
}

// Iteratively calls deleteFront() until the list is empty to leave memory clean.
slist::~slist()
{
	while (!isEmpty())
	{
		el_t item;
		deleteFront(item);
	}
}


