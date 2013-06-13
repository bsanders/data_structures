/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/25/2011
 * HW: HW3P3
 * Compiler: G++
 * Compilation line: g++ app.cpp linked-list.cpp [slinked-list.cpp]
 * Header file of a Linked List
 * Description:
 * The header file for a basic single-linked list.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Linked List header file */

#include <vector>
typedef char el_t;

using namespace std;


// The single Linked List class
// Data members are marked "protected" instead of "private" for use in later classes.
class llist
{
	protected:
		// The basic building block of a Linked list is a node.
		// A node has some piece of data, and a pointer to the next node in the list.
		// The pointer may point to NULL if this node is the last in the list.
		struct Node
		{
			el_t Elem;
			Node *Next;
		};

		int count;		// The counter variable is not used to determine emptiness
									// But rather to help when looping around the list.
		Node *front;	// front is a pointer to a Node which is at the "front" of the list.
		Node *rear;		// front is a pointer to a Node which is at the "rear" of the list.
	
		// a helper function used by addRear or addFront to reduce code duplication.
		void createFirst(el_t NewNum); // 'protected' because it is somewhat dangerous.
		
	public:
		// Public constructor/destructor.
		llist();			// Does not create any nodes, but init's front/rear to NULL
		~llist();			// Iteratively calls deleteFront() until the list is empty.
		
		// These empty classes are used for Exception handling.
		class Underflow {};		// the list is being accessed but is empty
		class OutOfRange {};	// the list is being accessed but the index provided is too low/high.

		// Member functions //
		
		// Useful helper functions for a linked list
		bool isEmpty() const;				// Just checks to see if the list is empty or not
		void displayAll();		// Displays [ empty ] or list contents in brackets
		
		// Adds an element to the front or back of a list, creating nodes.
		void addRear(el_t NewNum);
		void addFront(el_t NewNum);
		
		// Removes the element (and deletes the node) from the list front or back.
		// (returns it in pass-by-reference.)
		void deleteRear(el_t& OldNum);
		void deleteFront(el_t& OldNum);
		
		// Adds/removes the element at a specified 1-based index and re-links the list.
		void addBeforeIth(int I, el_t OldNum);
		void deleteIth(int I, el_t& OldNum);
};

