/* * * * * * * * * * * * * * * * * * * * * * * * * * 
* Author: Bill Sanders
* Date: 10/09/2011
* Description:
* A Queue class header file, based on an array.
* 
* * * * * * * * * * * * * * * * * * * * * * * * * */
/* Queue header file */

#include <string>

using namespace std;

// For now, the queue uses an array of integers, of size 10
typedef string el_t;
const int MAX_SIZE = 51;

class queue
{
	private:
		// Hide access to the array
		el_t el[MAX_SIZE];
		// Our tracker var's
		int count;	// number of elements in queue
		int front;	// which element is currently "in front"
		int rear;	// which element is currently "at the end"

	public:
		// Public constructor/destructor
		queue(); 
		~queue();

		// These empty classes are used for Exception handling.
		class Overflow {};  // The underlying array (and thus, the queue) is over capacity.
		class Underflow {}; // The underlying array (and thus, the queue) is empty.

		// Member functions //
		
		// Useful helper functions for a queue
		bool isEmpty();
		bool isFull();

		// Returns the number of elements in the queue
		int getSize();

		// Displays all elements in queue horizontally, or simply "[ empty ]"
		void displayAll();
		// same as display all, but enumerates the array slot the element has.
		void enumerateAll();

		// Note, for consistency with add...
		// ... remove() and frontElem() use pass-by-reference
		// Internally, these throw Overflow and Underflow, if necessary
		// add() places the element at rear
		// remove() removes the element at front
		// frontElem() returns the element at front, without removing.
		void add(el_t);
		void remove(el_t&);
		void frontElem(el_t&);

		// If empty, throws Underflow
		// If queue.getSize() == 1, do nothing
		// If queue.getSize() > 1 move the front elem to rear
		void goToBack();
};

