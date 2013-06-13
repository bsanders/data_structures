/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 10/09/2011
 * Description:
 * A client application which uses a stack class.
 * This program prompts for a postfix-notation expression.
 * Then operates on the expression using a stack and the algo below.
 * * * * * * * * * * * * * * * * * * * * * * * * * */

// A concise psuedo-code version of postfix notation evaluation: 

/* while items in expression:
 * 	read item
 * 	if item is number:
 * 		push item                 <--- possible overflow()
 * 	else if item is operator:
 * 		pop two items             <--- possible underflow()
 * 		apply operator to the two items
 * 		push result
 * 	else item is invalid:       <--- non-digit, non operator character, error.
 * 		quit
 * pop last item in stack
 * 	display                     <--- possible remnants on stack, error.
 * end.
 */

/* Stack client file */

#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

// Helper functions. These just display error messages for Under/Overflows
void reportOverflowError(stack& myStack, string& input_str);
void reportUnderflowError(stack& myStack, string& input_str);

int main()
{
	stack s;
	
	// Prompt for input
	cout << "Please type an expression in postfix notation." << endl;
	string input_expr;
	cin >> input_expr;
	
	// We could use a for loop over string.length,
	// but it wouldn't look much nicer?
	// C++ needs a decent foreach loop  :o/
	// So instead we loop over each character in the string, until the null-char
	int i = 0;
	while (input_expr[i] != '\0')
	{
		char ch;
		ch = input_expr[i];
		
		// is this a valid digit?
		// Checks the ascii value of the character
		// See, http://en.wikipedia.org/wiki/ASCII#ASCII_printable_characters
		if ((int(ch) >= 48) && (int(ch) <= 57))
		{
			int x = int(ch) - 48; // '0' is character 48, so 0-48=0, etc.

			// Lets try to push() it on the stack, checking for Overflow errors
			try
			{
				s.push(x);
			}
			catch (stack::Overflow)
			{
				reportOverflowError(s, input_expr);
				return(1);
			}
		}
		// Not a digit, maybe its one of [*+-/] ?
		else if ((ch == '*') || (ch == '+') || (ch == '-') || (ch == '/'))
		{
			int left_operand, right_operand;
			
			// Try to pop() two items off the stack, checking for underflows
			// Then operate on them based on what 'ch' is.
			try
			{
				s.pop(right_operand);
				s.pop(left_operand);

				if (ch == '*')
				{
					s.push(left_operand * right_operand);
				}
				else if (ch == '+')
				{
					s.push(left_operand + right_operand);
				}
				else if (ch == '-')
				{
					s.push(left_operand - right_operand);
				}
				else if (ch == '/')
				{
					s.push(left_operand / right_operand);
				}
			}
			catch (stack::Underflow)
			{
				reportUnderflowError(s, input_expr);
				return(1);
			}
			// Overflow shouldn't be possible here, as we just removed two elements
			// But we'll keep it anyway.
			catch (stack::Overflow)
			{
				reportOverflowError(s, input_expr);
				return(1);
			}
		}
		else // arbitrary non-numeric, non-operator character in string.
		{
			cout << "Error!" << endl;
			cout << "'" << ch << "' is not a valid operator or number" << endl;
			cout << "Please check your expression and retry." << endl;
			return(1);
		}
		
		i++;  // To get to the next char in input_expr
	} // we got to the null-character/end of string

	// All done, lets get the result.
	int result;
	try
	{
		s.pop(result);
	}
	catch (stack::Underflow)
	{
		// This only occurs if I clear the stack (s.clearIt()).
		// Currently does not happen.
		return(1);
	}

	// Only occurs if there was still stuff on the stack after that last pop()
	// This means the expression is messed up.  Warn user and quit.
	if (!s.isEmpty())
	{
		cout << "Error!" << endl;
		cout << "Incomplete expression.  Too few operators." << endl;
		cout << "Your expression: " << input_expr << endl;
		// cout << "Contents of stack at Underflow:" << endl; // These two lines for diagnostic purposes
		// s.displayAll();
		cout << "Please check your expression and retry." << endl;
		return(1);
	}
	
	// Finally, if everything worked out, display the result and quit.
	cout << "The result is: " << result << endl;
	return(0);
}

// Implementations of our error message functions.
// They give an appropriate warning, display the expression and stack contents
void reportOverflowError(stack& myStack, string& input_str)
{
	cout << "Your expression was too long to fit on the stack." << endl;
	cout << "Your expression: " << input_str << endl;
	// cout << "Contents of stack at Overflow:" << endl; // These two lines for diagnostic purposes
	// myStack.displayAll();
}

void reportUnderflowError(stack& myStack, string& input_str)
{
	cout << "Your expression was missing an operator or number." << endl;
	cout << "Your expression: " << input_str << endl;
	// cout << "Contents of stack at Underflow:" << endl; // These two lines for diagnostic purposes
	// myStack.displayAll();
}


