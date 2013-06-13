/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 11/22/2011
 * HW: HW6
 * Compiler: G++
 * Compilation line: g++ app.cpp linked-list.cpp slinked-list.cpp dgraph.cpp
 * Implementation and test of a direct graph
 * Description:
 * Implementation and test of a direct graph.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Directed Graph client implementation file */

#include <iostream>
#include <ctype.h>

#include "dgraph.h"

// Helper functions
void reportAdjacencyList(dgraph& myGraph);
void reportOutDegree(dgraph& myGraph);

// The bulk of main() is a looping menu, prompting for the display of data about the graph.
int main()
{
	dgraph myGraph = dgraph();
	
	cout << "Loading data from file table.txt..." << endl;
	myGraph.fillTable(); // pulls vertex data from table.txt
	
	string input_expr;
	while (input_expr != "q")
	{
		// Prompt for input
		cout << "Select one:" << endl;
		cout << "1. Find Adjacency List of a vertex (a)" << endl;
		cout << "2. Find Out Degree of a vertex (o)" << endl;
		cout << "3. Display the graph as a table. (d)" << endl;
		cout << "4. Quit (q)" << endl;
		cout << "Choice (a/o/d/q): " << endl;
		cin >> input_expr;

		// I'm a nice guy, so user can input menu item number, or the letter, in either case
		if (input_expr == "1" || input_expr == "a" || input_expr == "A")
		{
			reportAdjacencyList(myGraph);
		}
		else if (input_expr == "2" || input_expr == "o" || input_expr == "O")
		{
			reportOutDegree(myGraph);
		}
		else if (input_expr == "3" || input_expr == "d" || input_expr == "D")
		{
			cout << "Vertex\tDegree\tAdjacencyList" << endl;
			myGraph.displayGraph();
		}
		else if (input_expr == "4" || input_expr == "q" || input_expr == "Q")
		{
			input_expr = "q"; // Normalize their answer so it satisfies the while loop
		}
		else // Bad input, re-prompt.
		{
			cout << "Please select one of the above options." << endl;
		}
	}
	return(0);
}

// Helper function to display results of a vertex inquiry
// Accepts a dgraph reference, prompts for user input for a vertex name
// Attempts to display the adjacency list of that vertex
// Or catches VertexNotFound if not.
void reportAdjacencyList(dgraph& myGraph)
{
	slist adj_list = slist();
	
	cout << "Enter the vertex you would like to search for:" << endl;

	string input_expr;
	cin >> input_expr;
	
	char vertex_name = toupper(input_expr[0]);

	cout << "Searching for vertex " << vertex_name << endl;
	try
	{
		adj_list = myGraph.findAdjacencyList(vertex_name);
		cout << "The adjacency list for that vertex is:" << endl;
		adj_list.displayAll();
	}
	catch (dgraph::VertexNotFound)
	{
		cout << "Sorry, couldn't find that vertex in the graph." << endl;
	}
}

// Helper function to display results of a vertex inquiry
// Accepts a dgraph reference, prompts for user input for a vertex name
// Attempts to display the degree of that vertex
// Or catches VertexNotFound if not.
void reportOutDegree(dgraph& myGraph)
{
	cout << "Enter the vertex you would like to search for:" << endl;

	string input_expr;
	cin >> input_expr;

	char vertex_name = toupper(input_expr[0]);

	cout << "Searching for vertex " << vertex_name << endl;
	try
	{
		cout << "The out degree for that vertex is:" << endl;
		cout << myGraph.findOutDegree(vertex_name) << endl;
	}
	catch (dgraph::VertexNotFound)
	{
		cout << "Sorry, couldn't find that vertex in the graph." << endl;
	}
}
