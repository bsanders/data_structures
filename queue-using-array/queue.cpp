/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/09/2011
 * Description:
 * A Queue class implementation file, based on an array.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Queue implementation file */

#include <iostream>
#include "queue.h"

using namespace std;

// Standard constructor; just initialize our counting var's to zero.
queue::queue()
{
	count = 0;
	front = 0;
	rear = 0;
}

// Nothing to be done in the destructor.
queue::~queue() {};

// The queue uses the count variable to track capacity. 0 is 'empty'
bool queue::isEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}

// And full is MAX_SIZE, as defined in the header file.
bool queue::isFull()
{
	if (count == MAX_SIZE)
		return true;
	else
		return false;
}

// Just a getter member to allow the client to see the count.
int queue::getSize()
{
	return(count);
}

// Displays "[ empty ]" if the queue is currently empty.
// Otherwise, displays each element, horizontally, in order from front to rear.
void queue::displayAll()
{
	if (isEmpty())
	{
		cout << "[ empty ]" << endl;
	}
	else
	{
		int i = front; // start at front
		cout << "[ ";
		// Uses a do..while loop to run at least once, until we reach rear
		do
		{
			cout << el[i] << " ";
			i = (i + 1) % MAX_SIZE;
		} while (i != rear);
		cout << "]" << endl;
	}
}

// Displays "[ empty ]" if the queue is currently empty.
// Otherwise, displays each element, horizontally, in order from front to rear.
// Also enumerates each element, adding its actual place in the array.
void queue::enumerateAll()
{
	if (isEmpty())
	{
		cout << "[ empty ]" << endl;
	}
	else
	{
		int i = front;
		cout << "[ ";
		do
		{
			cout << " " << i << ":" << el[i] << " ";
			i = (i + 1) % MAX_SIZE;
		} while (i != rear);
		cout << " ]" << endl;
	}
}

// Adds an element to the end of the line (at array[rear])
// Checks that there is room on the array, throwing overflow if needed.
// Leaves handling the overthrow to the client
// Otherwise:
// 	place elem at array[rear]
// 	increment the counter var
// 	and change the new rear slot to be rear+1, wrapping around.
void queue::add(el_t elem)
{
	if (isFull())
	{
		throw Overflow();
	}
	else
	{
		el[rear] = elem;
		count++;
		rear = (rear + 1) % MAX_SIZE;  // Modulo is used to wrap around the aray
	}
}

// Removes an element from the head of the line (at array[front])
// Checks that there is room on the array, throwing underflow if needed.
// Leaves handling the underthrow to the client
// Note: uses pass-by-reference
// Otherwise:
// 	get elem from array[front]
// 	decrement the counter var
// 	and change the new front slot to be front+1, wrapping around.
void queue::remove(el_t& elem)
{
	if (isEmpty())
	{
		throw Underflow();
	}
	else
	{
		elem = el[front];
		count--;
		front = (front + 1) % MAX_SIZE;  // Modulo is used to wrap around the aray
	}
}

// Peek at an element at the front of the queue without removing it.
// Always check if the queue isEmpty() first, and throw an Underflow if needed.
// Actually handling the Underflow is up to the client
// Note, like remove(), frontElem() uses pass-by-reference.
// Otherwise:
// 	set the elem reference to be in the front-th slot. Do not decrement count.
void queue::frontElem(el_t& elem)
{
	if (isEmpty())
	{
		throw Underflow();
	}
	else
	{
		elem = el[front];
	}
}

// Send the element at front to rear.
// First check if the queue is empty, if so throw underflow
// If the queue count is at 1, there's no need to do anything at all.
// Finally, if there is an actual line count > 1,
// 	create an elem, remove into it, then add it back to the queue.
void queue::goToBack()
{
	if (isEmpty())
	{
		throw Underflow();
	}
	else if (getSize() == 1)
	{
		// Do nothing.
	}
	else
	{
		el_t elem;
		remove(elem);
		add(elem);
	}
}
