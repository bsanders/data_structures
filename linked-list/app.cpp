/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/13/2011
 * HW: HW3P1
 * Compiler: G++
 * Compilation line: g++ app.cpp linked-list.cpp
 * Test program for a Linked List
 * Description:
 * Runs a series of test cases on a linked-list class.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Linked List client file */

#include <iostream>
#include "linked-list.h"

using namespace std;

// Function prototypes for the tests we'll run.
void case1();
void case2();
void case3();
void case4();

// Main just runs 4 test cases as required by spec.
int main()
{
	cout << "**** Now attempting case 1 ****" << endl;
	case1();
	cout << "**** End of case 1 ****" << endl;

	cout << "**** Now attempting case 2 ****" << endl;
	case2();
	cout << "**** End of case 2 ****" << endl;

	cout << "**** Now attempting case 3 ****" << endl;
	case3();
	cout << "**** End of case 3 ****" << endl;

	cout << "**** Now attempting case 4 ****" << endl;
	case4();
	cout << "**** End of case 4 ****" << endl;

	return(0);
}

void case1()
{
	llist L = llist();

	if (L.isEmpty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		cout << "List is not empty" << endl;
	}
	
	L.displayAll();
	
	L.addRear(1);
	L.addRear(2);
	L.addRear(3);
	
	L.displayAll();
	
	el_t elem;
	L.deleteFront(elem);
	cout << elem << endl;
	L.deleteFront(elem);
	cout << elem << endl;
	
	L.displayAll();
	
	if (L.isEmpty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		cout << "List is not empty" << endl;
	}

	L.deleteFront(elem);
	cout << elem << endl;
	
	if (L.isEmpty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		cout << "List is not empty" << endl;
	}
}

void case2()
{
	llist L = llist();
	
	L.addFront(5);
	L.addFront(4);
	
	el_t elem;
	L.deleteFront(elem);
	
	L.addRear(6);
	L.addRear(8);
	L.addRear(9);
	
	L.displayAll();
	
	L.addBeforeIth(1, 4);
	L.addBeforeIth(4, 7);
	L.addBeforeIth(7, 10);
	
	try
	{
		L.addBeforeIth(9, 12);
	}
	catch (llist::OutOfRange)
	{
		cout << "The index you provided was out of the range of the list." << endl;
	}
	
	try
	{
		L.addBeforeIth(0, 0);
	}
	catch (llist::OutOfRange)
	{
		cout << "The index you provided was out of the range of the list." << endl;
	}
	
	L.displayAll();
	
	L.deleteIth(1, elem);
	cout << elem << endl;
	L.deleteIth(6, elem);
	cout << elem << endl;
	L.deleteIth(3, elem);
	cout << elem << endl;
	
	try
	{
		L.deleteIth(5, elem);
	}
	catch (llist::OutOfRange)
	{
		cout << "The index you provided was out of the range of the list." << endl;
	}

	try
	{
		L.deleteIth(0, elem);
	}
	catch (llist::OutOfRange)
	{
		cout << "The index you provided was out of the range of the list." << endl;
	}

	L.displayAll();

	while (!L.isEmpty())
	{
		L.deleteRear(elem);
		cout << elem << endl;
	}
	
	L.displayAll();
}

void case3()
{
	llist L = llist();
	
	try
	{
		L.addBeforeIth(0, 0);
	}
	catch (llist::OutOfRange)
	{
		cout << "The index you provided was out of the range of the list." << endl;
	}
	
	el_t elem;
	try
	{
		L.deleteFront(elem);
	}
	catch (llist::Underflow)
	{
		cout << "The list is currently empty." << endl;
	}
}

void case4()
{
	llist L = llist();
	
	el_t elem;
	try
	{
		L.deleteIth(2, elem);
	}
	catch (llist::OutOfRange)
	{
		cout << "The index you provided was out of the range of the list." << endl;
	}
	
	try
	{
		L.deleteRear(elem);
	}
	catch (llist::Underflow)
	{
		cout << "The list is currently empty." << endl;
	}
}


