all: scanner

scanner: dfa.cpp main.cpp
	g++ -Wall -g -std=c++11 -c dfa.cpp
	g++ -Wall -g -std=c++11 main.cpp dfa.o -o scanner
