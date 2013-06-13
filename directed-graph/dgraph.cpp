/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 11/22/2011
 * HW: HW6
 * Compiler: G++
 * Compilation line: g++ app.cpp linked-list.cpp slinked-list.cpp dgraph.cpp
 * Implementation file of a directed graph
 * Description:
 * The Implementation file for a directed graph.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Directed Graph implementation file */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "dgraph.h"

using namespace std;

// As per specs: 
// table.txt should have the following format:
// Each line is
// name	out-degree	a-list-of-its-adjacent-vertices-separated-by-blanks
// A	2	B	F

// fillTable() is currently hardcoded to pull data from a file 'table.txt',
// in the same directory as the executable.
// This function loops over the contents of the file, one line at a time,
// filling the dgraph's Gtable with Gvertices,
// and incrementing the dgraph's count.
// fillTable does not do error checking on the data in table.txt:
// It will happily fill a vertex from a line that claims "X	1000	B".
void dgraph::fillTable()
{
	// Open the file
	ifstream file("table.txt");
	string line;

	int i = 0; // Counter to loop through the Gtable array.
	
	// Loop over the file, one line at a time.
	while(getline(file, line))
	{
		char vert_name;
		int out_degree;
		char adj_vertex;
		
		slist adj_list = slist();

		// this lets us easily output whitespace delimited 'formatted' text into variables.
		stringstream listream(line);
		
		listream >> vert_name;
		listream >> out_degree;
		
		// everything left in listream (if anything!) is an adjacent vertex
		while(listream >> adj_vertex)
		{
			adj_list.addRear(adj_vertex);
		}

		// Now that we have successfully pulled data from the line, populate a Gvertex with it.
		Gvertex vert;
		vert.name = vert_name;
		vert.out_degree = out_degree;
		vert.adj_list = adj_list; // Calls copy constructor of slist.
		
		Gtable[i] = vert;
		i++;
		count++;
	}
	// When the loop ends, we've read every line of the file.
	// file (an ifstream object) closes automatically at the end of fillTable()
}

// Displays the graph in a neat tabular format.
// Simply loops over Gtable, MAX_SIZE times.
// Checks to see if name is != the nul character.  If so, vertex is empty, and don't print.
// Otherwise, print the vertex name, out degree, and adjacency list
void dgraph::displayGraph()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (Gtable[i].name != '\0')
		{
			cout << Gtable[i].name << '\t';
			cout << Gtable[i].out_degree << '\t';
			Gtable[i].adj_list.displayAll();  // Note, calls slist's displayAll()
		}
	}
}

// Loops through the Gtable up to MAX_SIZE times,
// Searching for the vertex_name that was specified
// If found, return the out_degree as an integer.
// Otherwise throws VertexNotFound if that vertex doesn't exist.
int dgraph::findOutDegree(char vertex_name)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (vertex_name == Gtable[i].name)
		{
			return(Gtable[i].out_degree);
		}
	}
	throw(dgraph::VertexNotFound());
}

// Loops through the Gtable up to MAX_SIZE times,
// Searching for the vertex_name that was specified
// If found, return a copy of the adjacency list
// Otherwise throws VertexNotFound if that vertex doesn't exist.
slist dgraph::findAdjacencyList(char vertex_name)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (vertex_name == Gtable[i].name)
		{
			return(Gtable[i].adj_list); // Implicitly calls copy constructor of slist
		}
	}
	throw(dgraph::VertexNotFound());
}

// This constructor initializes our data to indicate the graph is empty.
// The key here is that name is init'd as '\0', the nul character
// We use this nul character later to check if name has been written to.
dgraph::dgraph()
{
	count = 0;
	
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Gtable[i].name = '\0';
		Gtable[i].mark = 0;
		Gtable[i].out_degree = 0;
	}
}

// Calls the slist() destructor for each defined vertex to leave memory clean.
dgraph::~dgraph()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (Gtable[i].name != '\0')
		{
			// the slist destructor, iteratively destroys every item in the list
			Gtable[i].adj_list.~slist(); 
		}
	}
}
