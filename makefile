run:	main.o Grapg.o
	g++ -o run main.o Grapg.o

Grapg.o:	Grapg.cpp Graph.h
	g++ -c -g -Wall -std=c++11 -std=c++17 -std=gnu++17 Grapg.cpp

main.o:	main.cpp Graph.h
	g++ -c -g -Wall -std=c++11 -std=c++17 -std=gnu++17 main.cpp

clean:
	rm -f run main.o Grapg.o

rebuild:
	make clean
	make
