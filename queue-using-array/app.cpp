/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/09/2011
 * Description:
 * A client application which uses a queue class.
 * This program outputs ordered strings of iterations of A, B, and C
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */

/* start with three initial values, A, B and C
 * place these in the queue.                     <--- possible overflow
 * while queue is not full:
 * 	remove item from front of queue              <--- possible underflow
 * 	print item
 *  append "A" to item and add to rear of queue  <--- possible overflow
 * 	append "B" to item and add to rear of queue  <--- possible overflow
 *	append "C" to item and add to rear of queue  <--- possible overflow
 */

/* Stack client file */

#include <iostream>
#include "queue.h"
#include <string>

using namespace std;

int main()
{
	queue myLine;
	
	// Add the three initial values.
	try
	{
		myLine.add("A");
		myLine.add("B");
		myLine.add("C");
	}
	// Shouldn't overflow unless MAX_SIZE is set to below 3
	catch (queue::Overflow)
	{
		cout << "Error!" << endl;
		cout << "There is no room in the queue for any more items." << endl;
	}

	// int i = 1; Only used for enumeration.
	// Infinite loop.  We cycle through the loop until we Overflow.
	// We could keep track of how many lines we've written, and then quit at 25 (req'd by spec),
	// but this works just as well for this assignment.
	while (true)
	{
		el_t elem;
		
		// Get elem from the front of the queue
		try
		{
			myLine.remove(elem);
		}
		// Check for an underflow (won't happen in this program).
		catch (queue::Underflow)
		{
			cout << "Queue underflow" << endl;
		}
		// Then output the element.
		cout << elem << endl;
		
		// Enumerates the output. Be sure to also uncomment lines with i above/below.
		//cout << i << ": " << elem << endl;
		
		// Finally, try to add the next triplet of elements
		try
		{
			myLine.add(elem + 'A');
			myLine.add(elem + 'B');
			myLine.add(elem + 'C');
		}
		// This is where we'll end the loop when we have too many items in the queue.
		catch (queue::Overflow)
		{
			cout << "Error!" << endl;
			cout << "There is no room in the queue for any more items." << endl;
			cout << "Queue size: " << myLine.getSize() << endl;
			cout << "Queue contents: " << endl;
			myLine.displayAll();
			cout << "Array contents, enumerated: " << endl;
			myLine.enumerateAll();
			
			return(0);
		}
		
		//i++; // Was only used for enumeration.
	}
}
