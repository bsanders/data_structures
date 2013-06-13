/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/25/2011
 * HW: HW3P3
 * Compiler: G++
 * Compilation line: g++ app.cpp linked-list.cpp slinked-list.cpp
 * Header file of a Searchable Linked List
 * Description:
 * The header file for a single-linked list which has search and replace functionality.
 * As well as a copy constructor and overloaded assignment operator
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Searchable Linked List header file */

#include <vector>
#include "linked-list.h"
typedef int el_t;

using namespace std;

// The searchable Linked List class
class slist: public llist
{
	public:
		// Public constructor/destructor.
		slist();			// Does not create any nodes, but init's front/rear to NULL
		~slist();			// Iteratively calls deleteFront() until the list is empty.
		
		// copy constructor
		slist(const slist& Original);
		
		// overloaded assignment operator
		slist& operator=(const slist& OtherOne);
		
		// overloaded equality-test operator
		bool operator==(const slist& OtherOne);
		
		// Member functions //
		int search(el_t Key);
		void replace(el_t Elem, int I);
};

