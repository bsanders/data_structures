/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders, with credit to Rika Yoshii
 * Date: 09/16/2011
 * Description:
 * A Stack class header file, based on a vector.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Stack header file */

typedef char el_t;
#include <vector>

using namespace std;

class stack
{
	private:
		// Hide access to the vector and our tracker variable
		vector<el_t> el;
		int top;
	
	public:
		// Public constructor/destructor
		stack();
		~stack();
		
		// These empty classes are used for Exception handling.
		class Overflow {};  // The underlying vector (and thus, the stack) is over capacity.
		class Underflow {}; // The underlying vector (and thus, the stack) is empty.

		// Member functions //
		
		// Useful helper functions for a stack
		bool isEmpty();
		bool isFull(); // Always returns false.
		void displayAll();
		void clearIt();
		
		// Note, for consistency with push...
		// ... pop() and topElem() use pass-by-reference
		// Internally, these throw Overflow and Underflow, if necessary
		void push(el_t);
		void pop(el_t&);
		void topElem(el_t&);
};

