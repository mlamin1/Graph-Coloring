#include "Graph.h"
#include <iostream>
#include <string>



/***************************************************************/
//addVertex function						/
//Adds a vertex to the graph if it is not already added		/
/***************************************************************/
void Graph::addVertex(std::string vertex)
{
	auto search = Courses.find(vertex);
	if(search == Courses.end())
	{
		std::vector<std::string> new_vect;
		Courses.insert(std::pair<std::string, std::vector<std::string>> (vertex, new_vect));
	}


}




/***************************************************************/
//addEdge function						/
//adds an edge between 2 vertices that was send from the main	/
/***************************************************************/
void Graph::addEdge(std::string V1, std::string V2) 
{
	addVertex(V1);
	addVertex(V2);
	if(V1 != V2)
	{
		bool is_In = false;
		bool is_In2 = false;
		for(int it = 0; it < Courses[V1].size(); it++)
		{
			if(Courses[V1].at(it) == V2)
			{
				is_In = true;
			}
		}
		for(int it = 0; it < Courses[V2].size(); it++)
		{
			if(Courses[V2].at(it) == V1)
			{
				is_In2 = true;
			}
		}
		if(is_In == false && is_In2 == false)
		{
			Courses[V1].push_back(V2);
			Courses[V2].push_back(V1);
		}
	}
}


/***************************************************************/
//Print function						/
//Prints the adjacency list for the vertex and their neighbors	/
/***************************************************************/
void Graph::Print()
{
	std::cout << "Adjacency List" << std::endl;
	for(const auto &[index, v]: Courses)
	{
		std::cout << index << " : ";
		for(auto it = v.begin(); it != v.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

}




/***************************************************************/
//greedyColoring function					/
//Algortithm used to color our graph based on the conflict of 	/
//our graph							/
/***************************************************************/
void Graph::greedyColoring()
{
	//used to color the graphs to differentiate more easily
	const std::string red("\033[0;31m");
	const std::string green("\033[1;32m");
	const std::string yellow("\033[2;33m");
	const std::string cyan("\033[0;36m");
	const std::string magenta("\033[0;35m");
	const std::string blue("\033[0;94m");
	const std::string reset("\033[0m");
	vector<int> result_v;

	for(const auto &[index, v]: Courses)
	{
		result_v.push_back(-1);
	}
	
	// Assign the first color to first vertex 
	result_v.front() = 0;	

	// Initialize remaining V-1 vertices as unassigned 
	for(int i = 1; i < result_v.size(); i++)
	{
		result_v[i] = -1;	// no color is assigned to u
	}
	
	
	// A temporary array to store the available colors. True 
	// value of available[cr] would mean that the color cr is 
	// assigned to one of its adjacent vertices 
	bool available[result_v.size()]; 
	for (int cr = 0; cr < result_v.size(); cr++)
	{	
		available[cr] = false; 
	}

	// Assign colors to remaining V-1 vertices 
	int temp_num = 1;
	for(const auto &[index, v]: Courses)
	{
		// Process all adjacent vertices and flag their colors 
		// as unavailable 
		for(int i = 0; i < Courses[index].size(); i++)
		{	
			if(result_v[i] != -1)
			{
				available[result_v[i]] = true;
			}
		}
		
		// Find the first available color 
		int cr; 
		for (cr = 0; cr < result_v.size(); cr++)
		{	
			if (available[cr] == false) 
				break; 
		}

		result_v[temp_num] = cr; // Assign the found color 
		temp_num++;

		// Reset the values back to false for the next iteration 
//		for(int i = 0; i < result_v.size(); i++)
		for(int i = 0; i < Courses[index].size(); i++)	
		{
			if(result_v[i] != -1)
				available[result_v[i]] = false;
		}
	} 

	// print the result 
	int temp = 0;
	std::cout << std::endl;	
	for(const auto &[index, v]: Courses)
	{

		if(result_v[temp] == 0)
		{
			std::cout<< red << "Class: " << index << " -----> Color " <<result_v[temp] << reset << std::endl;
		}
		else if(result_v[temp] == 1)
		{
			std::cout << green << "Class: " << index << " -----> Color " <<result_v[temp] << reset << std::endl;
		}
		else if(result_v[temp] == 2)
		{
			std::cout << yellow << "Class: " << index << " -----> Color " <<result_v[temp] << reset << std::endl;
		}
		else if(result_v[temp] == 3)
		{
			std::cout << cyan << "Class: " << index << " -----> Color " <<result_v[temp] << reset << std::endl;
		}
		else if(result_v[temp] == 4)
		{
			std::cout << magenta << "Class: " << index << " -----> Color " <<result_v[temp] << reset << std::endl;
		}
		else if(result_v[temp] == 5)
		{
			std::cout << blue << "Class: " << index << " -----> Color " <<result_v[temp] << reset << std::endl;
		}
		temp++;
	}
}   
