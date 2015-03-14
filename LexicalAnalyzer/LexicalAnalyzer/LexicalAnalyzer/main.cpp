/*
Lexical Analyzer (Scanner)
Jonathon Cole Marlar
CS 421 - Automata Theory and Compiler Construction
20 March 2015
*/
#include <iostream>
#include <string>
#include <regex>
#include "dfa.h"
using namespace std;

void PreProcessBuffer(string filename);
void ProcessBuffer(string filename);

// DFA functions may go into another file entirely.

int main(int argc, char** argv)
{
	// Set up the symbol table here

	// Call the pre-processing buffer here

	// Call the processing buffer here

	// any test cases or debugging functions should go here.
	cout << dfa_PROGRAM("PROGRAMME ") << endl;

	system("PAUSE");
	return 0;
}

/*
PreProcessBuffer:
	- Takes in a file to be scanned
	- Takes out any comment lines (i.e. (* ... *)
	- Condenses any extraneous whitespace to a single space (' ')
	- This new format will be saved to a new file
*/
void PreProcessBuffer(string filename)
{
	// get rid of comment lines
	// collapse extraneous whitespace to a single space
	// convert character case
	// save this new format to a file
	// maybe return new file as a string?
}

void ProcessBuffer(string filename)
{
	
}