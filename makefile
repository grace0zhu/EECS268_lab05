prog: main.o Executive.o Map.o
	g++ -std=c++11 -g -Wall main.o Executive.o Map.o -o prog

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Map.o: Map.h Map.cpp
	g++ -std=c++11 -g -Wall -c Map.cpp
Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean: 
	rm *.o prog
