#include <iostream>
#include "Graph.h"

int main() 
{ 
	Graph g1(9); 
	g1.addVertex("COML 1126 8am");
	g1.addVertex("ANTHR 1400 8am");
	g1.addVertex("BIOG 1500 8am");
	g1.addVertex("CHEM 2070 8am");
	g1.addVertex("PE 1150 8am");
	g1.addVertex("ART 1250 8am");
	g1.addVertex("PHYS 2150 8am");
	g1.addVertex("COSC 1350 8am");
	g1.addVertex("ENGL 2120 8am");



	g1.addEdge("COML 1126 8am", "ANTHR 1400 8am");
	g1.addEdge("COML 1126 8am", "BIOG 1500 8am");
	g1.addEdge("COML 1126 8am", "CHEM 2070 8am");
	g1.addEdge("COML 1126 8am", "PHYS 2150 8am");
	g1.addEdge("ANTHR 1400 8am", "ENGL 2120 8am");
	g1.addEdge("BIOG 1500 8am", "CHEM 2070 8am");
	g1.addEdge("BIOG 1500 8am", "ART 1250 8am");
	g1.addEdge("BIOG 1500 8am", "PHYS 2150 8am");
	g1.addEdge("BIOG 1500 8am", "COSC 1350 8am");
	g1.addEdge("CHEM 2070 8am", "ART 1250 8am");
	g1.addEdge("CHEM 2070 8am", "ENGL 2120 8am");
	g1.addEdge("PE 1150 8am", "ART 1250 8am");
	g1.addEdge("PE 1150 8am", "ENGL 2120 8am");
	g1.addEdge("ART 1250 8am", "PHYS 2150 8am");
	g1.addEdge("ART 1250 8am", "COSC 1350 8am");
	g1.addEdge("ART 1250 8am", "ENGL 2120 8am");
	g1.addEdge("PHYS 2150 8am", "PE 1150 8am");
	
	std::cout << "*********************************" <<std::endl;
	std::cout << "	Courses To be taken	" << std::endl;
	std::cout << "*********************************" <<std::endl;

	std::cout << "COML 1126 8am" << std::endl;
	std::cout << "ANTHR 1400 8am"<< std::endl;
	std::cout << "BIOG 1500 8am"<< std::endl;
	std::cout << "CHEM 2070 8am"<< std::endl;
	std::cout << "PE 1150 8am"<< std::endl;
	std::cout << "ART 1250 8am"<< std::endl;
	std::cout << "PHYS 2150 8am"<< std::endl;
	std::cout << "COSC 1350 8am"<< std::endl;
	std::cout << "ENGL 2120 8am"<< std::endl;
	std::cout << std::endl;	
	std::cout << std::endl;		
	

	std::cout << "*********************************" <<std::endl;
	std::cout << "	Conflicting list	" << std::endl;
	std::cout << "*********************************" <<std::endl;
	g1.Print();
	std::cout << std::endl;	
	std::cout << std::endl;	
		
	std::cout << "*********************************" <<std::endl;
	std::cout << "	Coloring of Courses	" << std::endl;
	std::cout << "*********************************" <<std::endl;
	g1.greedyColoring(); 

	return 0; 
}
