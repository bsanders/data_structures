/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/04/2011
 * HW: HW2P2
 * Compiler: G++
 * Compilation line: g++ vector-merge-sort.cpp
 * Partial implementation of Merge Sort algorithm (combine function)
 * Description:
 * A client application which tests the combine function,
 * as part of the Merge Sort Algorithm.
 * This program currently prompts the user for two 3-value sets of numbers.
 * Each set is placed in a vector.
 * Each input is expected to be entered in increasing order.
 * Valid test cases: ("1 2 3", "4 5 6"), ("1 3 5", "2 4 6"), ("4 5 6", "1 2 3")
 * The combine() function then compares each element of the input vectors,
 * placing the result in order in a third vector.
 * The (combined, sorted) result vector is then printed to the console.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>
#include <stdio.h> // needed for sscanf(), used for scanning user input

using namespace std;

// Helper functions, defined below.
bool stringToInt(string input_str, int& result);
void fillArrayFromUser(vector<int>& vec);
void combine(vector<int>& A, vector<int>& B, vector<int>& R);

int main()
{
	// Our storage.
	vector<int> L1, L2, L3;
	
	// Get three values from the user
	cout << "Please enter three integers in increasing order for List 1:" << endl;
	fillArrayFromUser(L1);

	// Get three values from the user
	cout << "Please enter three integers in increasing order for List 2:" << endl;
	fillArrayFromUser(L2);

	// This is where all the real work is done.
	combine(L1, L2, L3);
	
	// Now just print the results.  Note this part works for result-vectors of any size
	cout << "The sorted result is:" << endl;
	for (int i = 0; i <= L3.size() - 1; i++)
	{
		cout << L3[i] << " ";
	}
	cout << endl;
	
	return(0);
}

// combine() takes two sorted vectors and combines them in a third sorted vector.
// The three vectors, A, B and R are passed by reference.
// A and B are the input, and each is expected to be in order already.
// R is the result vector, to be filled.
// Note, if A and B share an element, the element will appear twice in R.
// combine() Algorithm:
// While vectors_checked flag is false
// 	Read the first element from each vector A and B.
// 		if elem_a < elem_b:
// 			push elem_a onto vector R.
// 			increment the index of A.
// 		else
// 			push elem_b onto vector R.
// 			increment the index of B.
// 		If the index of either A or B reaches its size(),
// 			the remainder of the other vector can simply be appended to R.
// 			And the vectors_checked flag can be set to true.
// End Loop.
void combine(vector<int>& A, vector<int>& B, vector<int>& R)
{
	int index_a = 0;
	int index_b = 0;
	// an index_r not needed, as we just use push_back() on R.	

	bool vectors_checked = false; // Our completion flag.
	while (!vectors_checked)
	{
		// Actual comparisons
		if (A[index_a] < B[index_b])
		{
			R.push_back(A[index_a]);
			index_a++;
		}
		else // Note, this branch is followed if (A[index_a] == B[index_b]). Thats ok.
		{
			R.push_back(B[index_b]);
			index_b++;
		}
		
		// Rheck if we made it all the way through one of our input vectors.
		// This is our only function exit point, where we set vectors_checked to true.
		// Note, if index_a == A.size(), then B may still have values.
		if (index_a == A.size())
		{
			// Simple loop.  Starts where we left off in B, looping until we reach the end.
			for (int i = index_b; i <= B.size() - 1; i++)
			{
				R.push_back(B[i]);
			}
			vectors_checked = true;
		}
		// Note, if index_b == B.size(), then A may still have values.
		else if (index_b == B.size())
		{
			// Simple loop.  Starts where we left off in A, looping until we reach the end.
			for (int i = index_a; i <= A.size() - 1; i++)
			{
				R.push_back(A[i]);
			}
			vectors_checked = true;
		}
	}
}

// A convenience function (avoiding duplicated code)
// Pass in a vector by reference and it will fill it from user input.
// Currently set to allow three inputs, with retries if input was invalid.
// Input validity is checked by stringToInt() below.
void fillArrayFromUser(vector<int>& vec)
{
	string input_expr;

	for (int i=0; i <= 2; i++)
	{
		cin >> input_expr;
		
		int result;
		if (stringToInt(input_expr, result)) // see stringToInt() below.
		{
			vec.push_back(result); // If the conversion worked, push it to the end of vec
		}
		else // bad input, scold and decrement the counter to allow retry.
		{
			cout << "Sorry, that was not valid input.  Please try again." << endl;
			i--;
		}
	}
}

// A helper function.  Accepts a string and a reference to an integer.
// Attempts to parse an int out of the string and put it in result, if successful.
// Returns true if the attempt was successful, or false if it failed.
// Note: "123abc" will become 123, but "abc123" will not and will return false.
bool stringToInt(string input_str, int& result)
{
	// Scan the input string for a decimal
	// string->decimal results are stored in 'result',
	// and scan_results is 0 if nothing was parsed, 1 if result was filled
	int scan_results = sscanf(input_str.c_str(), "%d", &result);

	// User entered a string with no leading digits
	if(scan_results == 0)
	{
		return false;
	}
	// Some weird input error.  Like hitting ctrl-d at the cin prompt.
	else if(scan_results == EOF)
	{
		// Can't seem to get the stream back to sanity after this.  So just bail out.
		terminate();
	}
	// Finally, if we get here, we should have usable input.
	else
	{
		return(true);
	}
}

