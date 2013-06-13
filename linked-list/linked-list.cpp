/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/13/2011
 * HW: HW3P1
 * Compiler: G++
 * Compilation line: g++ app.cpp linked-list.cpp
 * Implementation of a Linked List
 * Description:
 * The implementation of a basic single-linked list.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Linked List implementation file */

#include <iostream>
#include "linked-list.h"

using namespace std;

// This constructor initializes our data to indicate the list is empty.
llist::llist()
{
	front = NULL;
	rear = NULL;
	count = 0;
}

// Iteratively calls deleteFront() until the list is empty to leave memory clean.
llist::~llist()
{
	while (!isEmpty())
	{
		el_t item;
		deleteFront(item);
	}
}

// Tests the emptiness of the List.
// Note, count is not used, but instead we check if front and rear both point to NULL.
bool llist::isEmpty()
{
	if ((front == NULL) && (rear == NULL))
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

// Displays the list in a neat format.
// First checks to see if the list is empty, and displays that.
// Otherwise, we setup a temporary pointer starting at the front of the list.
// We then use count to cycle through the list, adjusting the pointer and printing all nodes.
void llist::displayAll()
{
	if (isEmpty())
	{
		cout << "[ empty ]" << endl;
	}
	else
	{
		Node *temp = front; // A temporary pointer used to cycle through the list.

		int i = 0;
		// Print a node, then set the temp pointer to point to that node's Next,
		// repeat until we've gone through all the nodes.
		while (i != count)
		{
			cout << "[ " << temp->Elem << " ] ";
			temp = temp->Next;
			i++;
		}
		cout << endl;
	}
}

// Adds an element to the end of the list.
// First checks to see if the list is empty.
// If so, passes off to createFirst() to handle that special case.
// Otherwise, set Rear's Next to be a new node (overriding its NULL value)
// Then point rear at this new node (the new rear)
// And fill its data value and set it's Next to NULL.
// Finally, we increment count.
void llist::addRear(el_t NewNum)
{
	if (isEmpty())
	{
		createFirst(NewNum);
	}
	else
	{
		rear->Next = new Node;	// This will become the new rear.
		rear = rear->Next;
		rear->Elem = NewNum;
		rear->Next = NULL;
	}
	count++;
}

// Adds an element to the front of the list.
// First checks to see if the list is empty.
// If so, passes off to createFirst() to handle that special case.
// Otherwise, create a new temporary node, and set Front to be it's Next.
// That takes care of the old front, so now we set temp to be the new front, and fill its data.
// Finally, we increment count.
void llist::addFront(el_t NewNum)
{
	if (isEmpty())
	{
		createFirst(NewNum);
	}
	else
	{
		Node *temp = new Node;	// This will become the new front.
		temp->Next = front;
		front = temp;
		front->Elem = NewNum;
	}
	count++;
}

// A helper function to reduce code duplication.
// This is the case in which the list is empty and we are creating its first node.
// First we create the node, then set its Next to NULL and filling its data value.
// Finally we point front and rear to this node, because its the only one in the list.
// Be careful.
// Makes two assumptions (thats why it's protected):
// 	1) you've checked isEmpty() yourself
// 	2) you will update count yourself
// if called on a non-empty list, it will truncate the list and leave dangling pointers to objects floating around in the heap, salt your lands and add your email address to multiple junk mailing lists.
void llist::createFirst(el_t NewNum)
{
	Node *temp = new Node;
	temp->Next = NULL;
	temp->Elem = NewNum;
	front = temp;
	rear = temp;
}


// Deletes an element from the rear of the list.
// Returns it to main via pass-by-reference.
// First checks to see if the list is empty, and throws an Underflow error.
// If the list is not empty:
// 	Fill OldNum (pass by reference) with the data from rear.
// 	Check If front->Next is NULL
// 		If so, this was the only node in the list, so
// 		Since we deleted it, set rear and front to NULL to indicate an empty list.
// 		Otherwise we have to determine the element just before Rear,
// 		so that we can make it the new rear.
// 		We cycle through the list,
// 		until we find that the next element is rear,
// 		Then delete rear (its data already handled) and make the temporary node the new rear.
// Finally, decrement count.
void llist::deleteRear(el_t& OldNum)
{
	if (isEmpty())
	{
		throw Underflow(); // The list is empty, you can delete anything from it.
	}
	else
	{
		OldNum = rear->Elem; // This passes the data by-reference back to main.
		
		// This is the case in which Count == 1
		if (front->Next == NULL)
		{
			front = NULL;
			rear = NULL;
		}
		else // The regular case (eg list has more than one node.)
		{
			Node *temp = front;	// Temp will eventually point to the second to last node

			while (temp->Next != rear)
			{
				temp = temp->Next;
			}
			
			delete rear;
			rear = temp;	// Set rear to be the second to last node.
			rear->Next = NULL;
		}

		count--;
	}
}

// Deletes an element from the front of the list.
// Returns it to main via pass-by-reference.
// First checks to see if the list is empty, and throws an Underflow error.
// If the list is not empty:
// 	Fill OldNum (pass by reference) with the data from front.
// 	Check If front->Next is NULL
// 		If so, this was the only node in the list, so
// 		Since we deleted it, set rear and front to NULL to indicate an empty list.
// 		Otherwise we have to move the second element in the list to make it the new front.
// 		Then delete the old front (its data already handled) and make the temporary node the new front.
// Finally, decrement count.
void llist::deleteFront(el_t& OldNum)
{
	if (isEmpty())
	{
		throw Underflow(); // The list is empty, you can delete anything from it.
	}
	else
	{
		OldNum = front->Elem; // This passes the data by-reference back to main.

		if (front->Next == NULL) // Handles the case where count == 1
		{
			front = NULL;
			rear = NULL;
		}
		else // The regular case (eg list has more than one node.)
		{
			Node *temp = front->Next; // temp points to the second node in the list
			delete front;
			front = temp;	// Set the second node to be the new front of the list.
		}
		count--;
	}
}

// Deletes an element from the Ith location in the list.
// Returns it to main via pass-by-reference.
// Note "I" starts counting at 1, not 0!
// First
// 	checks to see if "I" is below 1, or more than count (past the end of the list)
// 	if so, throws an OutOfRange error.
// Next, checks if list is empty,
// 	if so, throws an Underflow error.
// Next, if I is '1', we are simply deleting front
// 	So pass off the work to deleteFront()
// Next, if I is 'count', we are simply deleting rear
// 	So pass off the work to deleteRear()
// Finally, if I is somewhere in the middle of the list,
// 	Create two temporary Node pointers,
// 	And set one to point to front
// 	Now, loop over the list until we get to two nodes before the Ith node.
// 	Set the temporary node ot this node.
// 	Set the node we will delete to the node after that one.
// 	Fill OldNum (pass by reference) with the data from the node-to-be-deleted.
//  Then set the temporary node's Next to the node-to-be-deleted's Next.
// 	Then delete the node-to-be-deleted.
// Finally, decrement count.
void llist::deleteIth(int I, el_t& OldNum)
{
	if ((I < 1) || (I > count))
	{
		throw OutOfRange(); // The given index is to low or high for our list.
	}
	else if (isEmpty())
	{
		throw Underflow(); // The list is empty, you can delete anything from it.
	}
	else if (I == 1) // This is the case where we are deleting the first node.
	{
		deleteFront(OldNum);
	}
	else if (I == count) // This is the case where we are deleting the last node.
	{
		deleteRear(OldNum);
	}
	else
	{
		Node *temp, *temp_to_delete;
		temp = front;

		for (int i = 0; i < I-2; i++)
		{
			temp = temp->Next;
		}

		temp_to_delete = temp->Next;
		OldNum = temp_to_delete->Elem;
		temp->Next = temp_to_delete->Next;
		
		delete temp_to_delete;
		count--;
	}
}

// Adds an element to the list, just before the Ith location.
// Note "I" starts counting at 1, not 0!
// First
// 	checks to see if "I" is below 1, or more than count+1 (past the end of the list)
// 	if so, throws an OutOfRange error.
// Next, checks if list is empty,
// 	if so, throws an Underflow error.
// Next, if I is '1', we are simply adding to front
// 	So pass off the work to addFront()
// Next, if I is 'count', we are simply adding to rear
// 	So pass off the work to addRear()
// Finally, if I is somewhere in the middle of the list,
// 	Create two temporary Node pointers,
// 	And set one to point to front
// 	Now, loop over the list until we get to two nodes before the Ith node.
// 	Set the temporary node to this node.
// 	create a node object in the node-to-be-inserted pointer.
//  Then set the node-to-be-inserted's Next to the temporary node's Next.
// 	The set the temporary node's next to point to the node-to-be-inserted.
// 	Finally, fill the node-to-be-inserted's data
// Finally, increment count.
void llist::addBeforeIth(int I, el_t NewNum)
{
	if ((I < 1) || (I > count+1))
	{
		throw OutOfRange();
	}
	else if (isEmpty())
	{
		throw Underflow();
	}
	else if (I == 1)
	{
		addFront(NewNum);
	}
	else if (I == count + 1)
	{
		addRear(NewNum);
	}
	else
	{
		Node *temp, *temp_to_insert;
		temp = front;

		for (int i = 0; i < I-2; i++)
		{
			temp = temp->Next;
		}

		temp_to_insert = new Node;
		temp_to_insert->Next = temp->Next;
		temp->Next = temp_to_insert;
		temp_to_insert->Elem = NewNum;
		
		count++;
	}
}
