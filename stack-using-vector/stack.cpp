/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders, with credit to Rika Yoshii
 * Date: 09/16/2011
 * Description:
 * A Stack class implementation file, based on a vector.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Stack implementation file */

#include <iostream>
#include "stack.h"

using namespace std;

// A basic constructor, using arrays so nothing fancy here.
// We initialize top to -1 to indicate the vector is empty.
stack::stack()
{
	top = -1;
}

// Nothing to do in the destructor.
stack::~stack() {};

// As mentioned in the constructor,
// we declare '-1' to mean the stack is empty.
bool stack::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

// Always false, because a vector is never full
bool stack::isFull()
{
	return false;
}

// Push an element onto the stack
// Always check if the stack isFull() first, and throw an Overflow if needed.
// Actually handling the Overflow is up to the client
// Otherwise:
// 	increment top to get to the next slot, and then place elem there.
void stack::push(el_t elem)
{
	if (isFull())
	{
		throw Overflow();
	}
	else
	{
		top++;
		el.push_back(elem);
	}
}

// Pop an element from the stack
// Always check if the stack isEmpty() first, and throw an Underflow if needed.
// Actually handling the Underflow is up to the client
// Note, pop() uses pass-by-reference to be consistent with push()
// Otherwise:
// 	set the elem reference to be in the top-th slot and then decrement top.
void stack::pop(el_t& elem)
{
	if (isEmpty())
	{
		throw Underflow();
	}
	else
	{
		elem = el[top];
		el.pop_back();
		top--;
	}
}

// Peek at an element at the top of the stack without removing it.
// Always check if the stack isEmpty() first, and throw an Underflow if needed.
// Actually handling the Underflow is up to the client
// Note, like pop(), topElem() uses pass-by-reference.
// Otherwise:
// 	set the elem reference to be the top-th slot. Do not decrement top.
void stack::topElem(el_t& elem)
{
	if (isEmpty())
	{
		throw Underflow();
	}
	else
	{
		elem = el[top];
	}
}

// Displays "[ empty ]" if the stack is currently empty.
// Otherwise, displays each element on it's own line.
void stack::displayAll()
{
	if (isEmpty())
	{
		cout << "[ empty ]" << endl;
	}
	else
	{
		for (int i = top; i >= 0; i--)
		{
			cout << el[i] << endl;
		}
	}
}

// Iteratively pop's all elements until the stack isEmpty()
void stack::clearIt()
{
	while (!isEmpty())
	{
		el_t elem;
		pop(elem);
	}
}

