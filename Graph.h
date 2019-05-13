#include <iostream> 
#include <list> 
#include <string>
#include <map>
#include <vector>
using namespace std; 

// A class that represents an undirected graph 
class Graph 
{ 
	int V;    // No. of vertices 
	list<int> *adj;    // A dynamic array of adjacency lists 
	std::map<std::string, std::vector<std::string>> Courses;
	public: 
	// Constructor and destructor 
	Graph(int V)   { this->V = V; adj = new list<int>[V]; } 
	~Graph()       { delete [] adj; } 

	// function to add an edge to graph 
	void addEdge(std::string v, std::string w);
	void addVertex(std::string);
	// Prints greedy coloring of the vertices 
	void Print();
	void greedyColoring(); 
}; 
