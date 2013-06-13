/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders, with credit to Rika Yoshii
 * Date: 10/09/2011
 * Description:
 * A Stack class header file, based on an array.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Stack header file */

// For now, the stack uses an array of integers, of size 10
static const int MAX = 10;
typedef int el_t;

class stack
{
	private:
		// Hide access to the array and our tracker variable
		el_t el[MAX];
		int top;
	
	public:
		// Public constructor/destructor
		stack();
		~stack();
		
		// These empty classes are used for Exception handling.
		class Overflow {};  // The underlying array (and thus, the stack) is over capacity.
		class Underflow {}; // The underlying array (and thus, the stack) is empty.

		// Member functions //
		
		// Useful helper functions for a stack
		bool isEmpty();
		bool isFull();
		void displayAll();
		void clearIt();
		
		// Note, for consistency with push...
		// ... pop() and topElem() use pass-by-reference
		// Internally, these throw Overflow and Underflow, if necessary
		void push(el_t);
		void pop(el_t&);
		void topElem(el_t&);
};

