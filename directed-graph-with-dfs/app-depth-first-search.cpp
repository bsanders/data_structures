/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 12/06/2011
 * HW: HW7
 * Compiler: G++
 * Compilation line: g++ app.cpp linked-list.cpp slinked-list.cpp dgraph.cpp stack.cpp
 * Implementation and test of a DFS algorithm on a direct graph
 * Description:
 * Implementation and test of a DFS algorithm on a direct graph
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Directed Graph client implementation file */

#include <iostream>
#include <ctype.h>

#include "stack.h"
#include "dgraph.h"

// Main creates a graph, a stack, and an slist.
// Then main fills the graph from a textfile.
// The starting vertex's adjacency list is then iteratively pushed onto the stack
// Then program loops
// It loops over the initial stack data, updating the "order" field,
// Adding the adjacency list of each vertex until the stack is exhausted.
int main()
{
	dgraph myGraph = dgraph();
	stack myStack = stack();

	// Load the initial data
	cout << "Loading data from file table.txt..." << endl;
	myGraph.fillTable(); // pulls vertex data from table.txt
	
	// Display the initial data
	cout << "Graph data:" << endl;
	cout << "Vertex\tOrder\tDegree\tAdjacencyList" << endl;
	myGraph.displayGraph();

	slist vertexAdjList = slist();
	
	// We'll start with Vertex A in the Graph.
	char vertex = 'A';
	cout << "Finding adjacency list for vertex '" << vertex << "'" << endl;
	vertexAdjList = myGraph.findAdjacencyList(vertex);

	// count will be incremented and used to track the order of the tree
	int count = 1;
	myGraph.visit(count, vertex);
	
	// Add the contents of this vertex's adjacency list to our stack
	while (!vertexAdjList.isEmpty())
	{
		vertexAdjList.deleteRear(vertex);
		myStack.push(vertex);
	}
	
	myStack.displayAll();
	
	// And begin to loop over the stack until all vertexes are visited and the stack is emptied.
	while (!myStack.isEmpty())
	{
		// Pop each vertex
		myStack.pop(vertex);
		cout << "Visiting vertex '" << vertex << "'" << endl;
		
		// If it's not marked...
		if (!myGraph.isMarked(vertex))
		{
			cout << "Vertex '" << vertex << "' has not been visited." << endl;
			cout << "Finding adjacency list for vertex '" << vertex << "'" << endl;
			// increment count before using it in the order data field
			count++;
			myGraph.visit(count, vertex); // now fill this vertex's order field
			vertexAdjList = myGraph.findAdjacencyList(vertex);
			
			// Now get this new vertex's adjacency list, and push it to the stack.
			char adj_vertex;
			while (!vertexAdjList.isEmpty())
			{
				vertexAdjList.deleteRear(adj_vertex);
				myStack.push(adj_vertex);
			}
			
			cout << "Stack contents after adding the adjacency list of vertex '" << vertex << "':" << endl;
			myStack.displayAll();
		}
		// If it's marked, skip it, we've already been there. (prevents infinite loop!)
		else
		{
			cout << "Vertex '" << vertex << "' has already been visited." << endl;
		}
	}
	
	cout << "Graph data, visited:" << endl;
	cout << "Vertex\tOrder\tDegree\tAdjacencyList" << endl;
	myGraph.displayGraph();
	
	return(0);
}
