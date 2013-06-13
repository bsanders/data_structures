/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 09/21/2011
 * HW: HW2P1
 * Compiler: G++
 * Binary Search Algorithim Test
 * Description:
 * This program continuously prompts the user for a number
 * and searches for the number over an ordered list
 * using the recursive binarySearch method defined below
 * and returning the position the number was found in
 * or printing a message if not found.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stdio.h> // needed for sscanf(), used for scanning user input
#include <math.h>  // needed for floor()
#include <string>

using namespace std;

int binarySearch(int L[], int x, int first, int last);

int main()
{
	int orderedlist[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

	// Loop controller variable
	bool keep_looping = true;

	string myinput;
	int myquery;
	int result;

	// while-loop so user doesn't have to restart program to see different results
	while (keep_looping == true)
	{
		cout << "Enter a number to search for, or 'q' to quit." << endl;
		cin >> myinput;

		// Quit if user enters a string that starts with 'q'
		if (myinput[0] == 'q')
		{
			keep_looping = false;
			cout << "Have a nice day." << endl;
		}
		else
		{
			// We can't trust user input
			// So we scan the input string for a decimal
			// string->decimal results are stored in 'myquery',
			// and scan_results is 0 if nothing was parsed, 1 if myquery was filled
			int scan_results = sscanf(myinput.c_str(), "%d", &myquery);

			// User entered a string that didn't start with 'q'. just restart loop.
			if(scan_results == 0)
			{
				cout << "Sorry, that was not a valid response." << endl;
			}
			// Some weird input error.  Like hitting ctrl-d at the cin prompt.
			if(scan_results == EOF)
			{
				cout << "Sorry, there was an unrecoverable error due to invalid input.  Quitting..." << endl;
				return(1); // Quit the program here, otherwise we get an infinite loop.
			}
			// Finally, if we get here, we have usable input.
			else
			{
				// Calls the recursive binarySearch function.
				// 0 and 9 are the hard-coded first and last positions in the array.
				result = binarySearch(orderedlist, myquery, 0, 9);

				// result will be -1 if the number is not found, otherwise >= 0
				if (result >= 0)
				{
					cout << "The number was found in position " << result + 1 << endl;
				}
				else
				{
					cout << "Sorry, that number is not in the list." << endl;
				}
			}
		}
	}

	return(0);
}

// Binary searches through an ordered list, L[].
// x is the number we're searching for,
// first and last are the first and last elements in the list
// Returns the position in the list of the element if found
// Or, if not found, returns -1
int binarySearch(int L[], int x, int first, int last)
{
	// Get the middle position in the list, floor()'d
	int middle;
	middle = int(floor((first + last)/2.0));

	// Now we do a simple comparison
	
	// If x is equal to the number at the middle of the list,
	// we found the number, return.
	if (x == L[middle])
	{
		return(middle);
	}
	// If first and last are equal or first is bigger than last,
	// and we still haven't found x
	// return -1, because x isn't in L[]
	else if (first >= last)
	{
		return(-1);
	}
	
	// Next, if x is less than the number at the middle of the list,
	// cut our search in half by setting the next 'last' to be under current middle
	else if (x < L[middle])
	{
		last = middle - 1;
	}
	// And do the opposite if x is greater than the number at the middle of the list
	else if (x > L[middle])
	{
		first = middle + 1;
	}
	
	// Finally, if we didn't find x, or determine it is not in the list,
	// do the search again with a new first or last.
	return(binarySearch(L, x, first, last));
}
