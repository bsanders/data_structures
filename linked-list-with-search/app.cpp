/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/25/2011
 * HW: HW3P3
 * Compiler: G++
 * Compilation line: g++ app.cpp linked-list.cpp slinked-list.cpp
 * Test program for a Searchable Linked List
 * Description:
 * Runs a series of test operations on a searchable linked-list class.
 * Which test the functionality of the Copy constructor and assignment operator.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Linked List client file */

#include <iostream>
#include "slinked-list.h"

using namespace std;

void CopyTest(slist ListCopy);

// runs through a few basic operations, testing the copy constructor and assignment operator
int main()
{
	slist L1 = slist();
	L1.addFront(1);
	L1.addFront(3);
	L1.addFront(5);
	L1.addFront(7);
	L1.addFront(9);

	CopyTest(L1);
	
	L1.displayAll();
	
	L1 = L1;
	
	L1.displayAll();
	
	slist L2 = slist();
	L2.addFront(2);
	L2.addFront(4);
	L2.addFront(6);
	L2.addFront(8);

	L2.displayAll();
	
	L2 = L1;

	L2.displayAll();
	
	el_t elem;
	L1.deleteRear(elem);

	L1.displayAll();
	L2.displayAll();
	
	return(0);
}

void CopyTest(slist ListCopy)
{
	ListCopy.addRear(2);
	ListCopy.displayAll();
}

