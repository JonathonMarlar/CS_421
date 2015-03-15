/*
Lexical Analyzer (Scanner)
Jonathon Cole Marlar
CS 421 - Automata Theory and Compiler Construction
20 March 2015
*/
#include <iostream>
#include <string>
#include <fstream>
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
	ProcessBuffer("example.txt");

	// any test cases or debugging functions should go here.
	// cout << dfaTextToken("PROGRAMMEEEEEEEEEEI ", "PROGRAM", PROGRAM) << endl;

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

/*
ProcessBuffer:
- For each line, reads letters one by one
- Recognizes tokens using a regular expression (or dfa)
- Stores data into hash table
*/
void ProcessBuffer(string filename)
{
	// open the cleaned file
	string line;
	ifstream cleanCode(filename);

	if (cleanCode.is_open())
	{
		int lineNum = 1;

		while (getline(cleanCode, line))
		{
			// print the line of code first
			cout << lineNum << " " << line << endl;
			lineNum++;

			// now we have to scan in, char by char, to find tokens
			char* start = &line[0];

			while (*start != NULL)
			{
				char* lookahead = start;
				string temp = "";

				while (*lookahead != ' ')
				{
					// add the text to temp
					temp = temp + *lookahead;
					lookahead++;

					if (temp.length() == 16 || *lookahead == NULL || *lookahead == ';')
						break;
				}

				// print out the token code and its value
				switch (*start)
				{
				case 'P':
				{
					cout << "\t" << getToken(temp, "PROGRAM", PROGRAM) << " " << temp << endl;
				} break;
				case 'V':
				{
					cout << "\t" << getToken(temp, "VAR", VAR) << " " << temp << endl;
				} break;
				case 'B':
				{
					cout << "\t" << getToken(temp, "BEGIN", BEGIN) << " " << temp << endl;
				} break;
				case 'E':
				{
					if (*(lookahead - 1) == '.')
						cout << "\t" << getToken(temp, "END.", ENDP) << " " << temp << endl;
					else
						cout << "\t" << getToken(temp, "END", END) << " " << temp << endl;
				} break;
				case 'I':
				{
					cout << "\t" << getToken(temp, "INTEGER", INTEGER) << " " << temp << endl;
				} break;
				case 'F':
				{
					cout << "\t" << getToken(temp, "FOR", FOR) << " " << temp << endl;
				} break;
				case 'R':
				{
					cout << "\t" << getToken(temp, "READ", READ) << " " << temp << endl;
				} break;
				case 'W':
				{
					cout << "\t" << getToken(temp, "WRITE", WRITE) << " " << temp << endl;
				} break;
				case 'D':
				{
					if (*(lookahead - 1) == 'V')
						cout << "\t" << getToken(temp, "DIV", DIV) << " " << temp << endl;
					else
						cout << "\t" << getToken(temp, "DO", DO) << " " << temp << endl;
				} break;
				case ';':
				{
					cout << "\t" << getToken(temp, ";", SEMICOLON) << " " << temp << endl;
				} break;
				case ':':
				{
					if (*(lookahead - 1) == '=')
						cout << "\t" << getToken(temp, ":=", EQUALS) << " " << temp << endl;
					else
						cout << "\t" << getToken(temp, ":", COLON) << " " << temp << endl;
				} break;
				case ',':
				{
					cout << "\t" << getToken(temp, ",", COMMA) << " " << temp << endl;
				} break;
				case '+':
				{
					cout << "\t" << getToken(temp, "+", PLUS) << " " << temp << endl;
				} break;
				case '-':
				{
					cout << "\t" << getToken(temp, "-", MINUS) << " " << temp << endl;
				} break;
				case '*':
				{
					cout << "\t" << getToken(temp, "*", TIMES) << " " << temp << endl;
				} break;
				case '(':
				{
					cout << "\t" << getToken(temp, "(", LEFTPAREN) << " " << temp << endl;
				} break;
				case ')':
				{
					cout << "\t" << getToken(temp, ")", RIGHTPAREN) << " " << temp << endl;
				} break;
				case '0': case '1': case '2': case '3': case '4': case '5':
				case '6': case '7': case '8': case '9':
				{
					cout << "\t" << getToken(temp, "[0-9]+", NUM) << " " << temp << endl;
				} break;
				default:
				{
					cout << "\t" << getToken(temp, "PROGRAM", PROGRAM) << " " << temp << endl;
				}
				}

				// we need to make sure the pointer ahead isn't null before jumping the river
				if (*lookahead != NULL && *lookahead != ';')
					start = lookahead + 1;
				else
					start = lookahead;
			}
		}
		cleanCode.close();
	}
}