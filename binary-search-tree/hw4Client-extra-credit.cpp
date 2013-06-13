/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders, with credit to Rika Yoshii
 * Date: 11/01/2011
 * HW: HW4
 * Compiler: G++
 * Compilation line: g++ hw4Client-extra-credit.cpp binstree.cpp
 * Binary Search Tree Implementation
 * Description:
 * This program tests the functionality of a BST, with regards
 * to deleting the root node under various circumstances.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
using namespace std;

#include "binstree.h"

int main()
{
	cout << "===  Starting a new tree with 3 nodes ===="<< endl;
	
	// Consider 4 cases of deleting the root node:
	// Case 1: Root has 2 children
	// Case 2: Root has 1 right child
	// Case 3: Root has 1 left child
	// Case 4: Root has 0 children
	
	
	BST RootTest;
	RootTest.Insertvertex(3);	// 3 root becomes root node
	RootTest.Insertvertex(1);
	RootTest.Insertvertex(4);
	RootTest.ShowInOrder();
	RootTest.DeleteVertex(3);	// Testing case 1
	RootTest.ShowInOrder();		// 1 becomes root with right child '4'.
	RootTest.DeleteVertex(1);	// Testing case 2
	RootTest.ShowInOrder();		// 4 becomes root with no children.
	RootTest.Insertvertex(2);	// 2 becomes left child of 4
	RootTest.ShowInOrder();
	RootTest.DeleteVertex(4);	// Testing case 3
	RootTest.ShowInOrder();		// 2 becomes lonely root
	RootTest.DeleteVertex(2);	// Testing case 4
	RootTest.ShowInOrder();		// Deleted the lonely root, tree is now empty
}
