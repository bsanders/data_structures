/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Rika Yoshii, using binary search tree class by Bill Sanders
 * Date: 11/01/2011
 * HW: HW4
 * Compiler: G++
 * Compilation line: g++ hw4Client.cpp binstree.cpp
 * Binary Search Tree Implementation
 * Description:
 * This program tests the basic functionality of a BST
 * Search, Traverse, Delete and Insert nodes.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
using namespace std;

#include "binstree.h"

int main()
{
	BST MyTree;  // my first binary search tree

	for(int i = 1; i <=9 ; i=i+2)   // inserting 1,3,5,7,9 into the tree
		MyTree.Insertvertex(i);

	for(int i = 10; i >=2 ; i=i-2)     // inserting 10,8,6,4,2 into the tree
		MyTree.Insertvertex(i);

	MyTree.ShowInOrder();  // should show in the sorted order

	MyTree.ShowPreOrder(); // should show the parent before children

	//********************************************************

	cout << "===  Starting a new tree with 7 nodes ===="<< endl;
	BST Nums;  // Nums is the second binary search tree

	// creates a shallowest 7 node tree (draw this)
	Nums.Insertvertex(3);  // root
	Nums.Insertvertex(1);  // level 1 L
	Nums.Insertvertex(2);    // level 2 R
	Nums.Insertvertex(0);    // level 2 L
	Nums.Insertvertex(5);  // level 1 R
	Nums.Insertvertex(6);    // level 2 R
	Nums.Insertvertex(4);    // level 2 L
	Nums.Insertvertex(4);   // should be an error

	//and show the nodes in sorted order
	Nums.ShowInOrder();

	//and then delete some nodes 

	//  - level 2 right most leaf
	Nums.DeleteVertex(6);

	// - level 1 right mode node with one left child
	Nums.DeleteVertex(5);

	// - level 0 root with two children
	Nums.DeleteVertex(3);

	// - deleting a non-existing one
	Nums.DeleteVertex(7);

	//and then show the remaining nodes in sorted order
	Nums.ShowInOrder();
}


