/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Author: Bill Sanders
 * Date: 11/22/2011
 * HW: HW6
 * Compiler: G++
 * Compilation line: g++ app.cpp linked-list.cpp slinked-list.cpp dgraph.cpp
 * Header file of a directed graph
 * Description:
 * The header file for a directed graph.
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Directed graph header file */

#include "slinked-list.h"

using namespace std;

const int MAX_SIZE = 20;

class dgraph
{
	protected:
		// The basic building block of a graph is a vertex.
		// A vertex has some associated data, and a pointer to a list of its adjacent vertices.
		// The pointer may point to NULL if the vertex is a dead end.
		struct Gvertex
		{
			char name;
			int mark;
			int out_degree;
			slist adj_list;
		};

		// This is the main data structure we use to keep track of our vertices.
		Gvertex Gtable[MAX_SIZE];

		// Currently not necessary, but we'll leave it in for now.
		// Contains the number of vertices in the graph.
		int count;

	public:
		// Public constructor/destructor.
		dgraph();
		~dgraph();

		// An exception class, raised if we search for a vertex and don't find it.
		class VertexNotFound {};
		
		// Member functions
		void fillTable();
		void displayGraph();
		int findOutDegree(char vertex_name);
		slist findAdjacencyList(char vertex_name);
};
