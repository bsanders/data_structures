/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/25/2011
 * HW: HW3P3, extra credit
 * Compiler: G++
 * Compilation line: g++ app-ex-credit.cpp linked-list.cpp slinked-list.cpp
 * Test program for a Searchable Linked List
 * Description:
 * Runs a series of test operations on a searchable linked-list class.
 * Which test the functionality of the overloaded equality operator.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Linked List client file */

#include <iostream>
#include "slinked-list.h"

using namespace std;

void CopyTest(slist ListCopy, slist& ListOriginal);

// runs through a few basic operations, testing the copy constructor and assignment operator
int main()
{
	slist L1 = slist();
	slist L2 = slist();

	cout << "Checking to see if L1 is equal to L2 (testing isEmpty results, eg Case 1)" << endl;
	cout << "L1:" << endl;
	L1.displayAll();
	cout << "L2:" << endl;
	L2.displayAll();
	if (L1 == L1)
	{
		cout << "They are the same." << endl;
	}
	else
	{
		cout << "They are different." << endl;
	}

	L1.addFront(1);
	L1.addFront(3);
	L1.addFront(5);
	L1.addFront(7);
	L1.addFront(9);

	cout << "Checking to see if L1 is equal to itself (testing memory locations, eg Case 2)" << endl;
	cout << "L1:" << endl;
	L1.displayAll();
	cout << "L2:" << endl;
	L2.displayAll();
	if (L1 == L1)
	{
		cout << "They are the same." << endl;
	}
	else
	{
		cout << "They are different." << endl;
	}

	CopyTest(L1, L1);
	
	L2.addFront(2);
	L2.addFront(4);
	L2.addFront(6);
	L2.addFront(8);
	L2.addFront(10);
	
	cout << "Checking to see if L1 is equal to L2";
	cout << " (same count, different content)" << endl;
	cout << "L1:" << endl;
	L1.displayAll();
	cout << "L2:" << endl;
	L2.displayAll();
	if (L1 == L2)
	{
		cout << "They are the same." << endl;
	}
	else
	{
		cout << "They are different." << endl;
	}
	
	L2 = L1;

	cout << "Checking to see if L1 is equal to L2 after assigning L1 to L2";
	cout << " (testing content, should have different memory locations)" << endl;
	cout << "L1:" << endl;
	L1.displayAll();
	cout << "L2:" << endl;
	L2.displayAll();
	if (L1 == L2)
	{
		cout << "They are the same." << endl;
	}
	else
	{
		cout << "They are different." << endl;
	}

	el_t elem;
	L1.addBeforeIth(3, 11);
	L2.addBeforeIth(3, 22);

	cout << "Checking to see if L1 is equal to L2 after putting inserting in the middle";
	cout << " (testing content in middle of lists)" << endl;
	cout << "L1:" << endl;
	L1.displayAll();
	cout << "L2:" << endl;
	L2.displayAll();
	if (L1 == L2)
	{
		cout << "They are the same." << endl;
	}
	else
	{
		cout << "They are different." << endl;
	}
	
	return(0);
}

void CopyTest(slist ListCopy, slist& ListOriginal)
{
	cout << "Checking to see if ListCopy is equal to ListOriginal";
	cout << " (different memory locations, same content)" << endl;
	cout << "ListCopy:" << endl;
	ListCopy.displayAll();
	cout << "ListOriginal:" << endl;
	ListOriginal.displayAll();
	if (ListCopy == ListOriginal)
	{
		cout << "They are the same." << endl;
	}
	else
	{
		cout << "They are different." << endl;
	}

	ListCopy.addRear(2);

	cout << "Checking to see if ListCopy is equal to ListOriginal,";
	cout << " after adding an element (different counts, case 3)" << endl;
	cout << "ListCopy:" << endl;
	ListCopy.displayAll();
	cout << "ListOriginal:" << endl;
	ListOriginal.displayAll();
	if (ListCopy == ListOriginal)
	{
		cout << "They are the same." << endl;
	}
	else
	{
		cout << "They are different." << endl;
	}
}

