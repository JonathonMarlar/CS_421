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
#include <cctype>
#include "dfa.h"
using namespace std;

void PreProcessBuffer(string filename);
void ProcessBuffer(string filename);

// DFA functions may go into another file entirely.

int main(int argc, char** argv)
{
	// Set up the symbol table here

	// Call the pre-processing buffer here
	PreProcessBuffer("example.txt");

	// Call the processing buffer here
	ProcessBuffer("clean.txt");

	// any test cases or debugging functions should go here.

	// system("PAUSE");
	return 0;
}

/*
PreProcessBuffer:
	- Takes in a file to be scanned
	- Takes out any comment lines (i.e. (* ... *)
	- Condenses any extraneous whitespace to a single space (' ')
	- This new format will be saved to a new file
	cleanedFile << line << endl;
*/
void PreProcessBuffer(string filename)
{
	string line;
	ifstream codeFile(filename);
	ofstream cleanedFile("clean.txt");
	bool inComment = false;

	if (codeFile.is_open() && cleanedFile.is_open())
	{
		while (getline(codeFile, line))
		{
			// we don't want to do anything until we hit a non-whitespace character
			char* it = &line[0];
			while (*it != NULL)
			{
				if (inComment == false)
				{
					if (isspace(*it))
					{
						if (*it != line[0] && !isspace(*(it - 1)))
							cleanedFile << *it;
					}
					else if (*it == '(' && *(it + 1) == '*')
					{
						inComment = true;
					}
					else
					{
						cleanedFile << (char) toupper(*it);
					}
				}
				else
				{
					if (*it == '*' && *(it + 1) == ')')
					{
						inComment = false;
						it++;
					}
				}
				it++;
			}
			cleanedFile << endl;
		}
		cleanedFile.close();
		codeFile.close();
	}
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
			// print the line number
			cout << lineNum << " " << line << endl;
			lineNum++;
			
			// now we have to scan in, char by char, to find tokens
			char* start = &line[0];
			
			// until we hit end of line, keep finding tokens!
			while (*start != NULL)
			{
				char* lookahead = start;
				string temp = "";
				
				while (!isDelimiter(*lookahead) && temp.length() != 16 && *lookahead != NULL && *lookahead != ' ')
				{
					// if we haven't hit a delimiter, add text to temp
					temp = temp + *lookahead;
					lookahead++;
				}
				
				// now we need to choose our 'dfa' by looking at the start pointer
				switch (*start)
				{
					case 'P':
						{
							cout << "\t" << getToken(temp, "PROGRAM", PROGRAM) << "  " << temp << endl;
							break;
						}
						
					case 'V':
						{
							cout << "\t" << getToken(temp, "VAR", VAR) << "  " << temp << endl;
							break;
						}
					case 'B':
						{
							cout << "\t" << getToken(temp, "BEGIN", BEGIN) << "  " << temp << endl;
							break;
						}
					case 'E':
						{
							if (*(lookahead-1) == '.')
								cout << "\t" << getToken(temp, "END.", ENDP) << "  " << temp << endl;
							else
								cout << "\t" << getToken(temp, "END", END) << "  " << temp << endl;
							break;
						}
					case 'I':
						{
							cout << "\t" << getToken(temp, "INTEGER", INTEGER) << "  " << temp << endl;
							break;
						}
					case 'F':
						{
							cout << "\t" << getToken(temp, "FOR", FOR) << "  " << temp << endl;
							break;
						}
					case 'R':
						{
							cout << "\t" << getToken(temp, "READ", READ) << "  " << temp << endl;
							break;
						}
					case 'W':
						{
							cout << "\t" << getToken(temp, "WRITE", BEGIN) << "  " << temp << endl;
							break;
						}
					case 'T':
						{
							cout << "\t" << getToken(temp, "TO", TO) << "  " << temp << endl;
							break;
						}
					case 'D':
						{
							if (*(lookahead-1) == 'V')
								cout << "\t" << getToken(temp, "DIV", DIV) << "  " << temp << endl;
							else
								cout << "\t" << getToken(temp, "DO", DO) << "  " << temp << endl;
							break;
						}
					// Delimiters are usually left on their own, so we don't need a regex for them
					case ';':
						{
							cout << "\t" << SEMICOLON << "  " << *start << endl;
							lookahead++;
							break;
						}
					case ':':
						{
							if (*(lookahead+1) == '=')
							{
								cout << "\t" << EQUALS << "  " << *start << *(start+1) << endl;
								lookahead++;
							}
							else
								cout << "\t" << COLON << "  " << *start << endl;
							lookahead++;
							break;
						}
					case ',':
						{
							cout << "\t" << COMMA << "  " << *start << endl;
							lookahead++;
							break;
						}
					case '+':
						{
							cout << "\t" << PLUS << "  " << *start << endl;
							break;
						}
					case '-':
						{
							cout << "\t" << MINUS << "  " << *start << endl;
							break;
						}
					case '*':
						{
							cout << "\t" << TIMES << "  " << *start << endl;
							break;
						}
					case '(':
						{
							cout << "\t" << LEFTPAREN << "  " << *start << endl;
							lookahead++;
							break;
						}
					case ')':
						{
							cout << "\t" << RIGHTPAREN << "  " << *start << endl;
							lookahead++;
							break;
						}
					case '0': case '1': case '2': case '3': case '4': case '5': 
					case '6': case '7': case '8': case '9': 
						{
							cout << "\t" << getToken(temp, "(0-9)+", NUM) << "  " << temp << endl;
							break;	
						}
					default:
						{
							cout << "\t" << getToken(temp, "N", IDENTIFIER) << "  " << temp << endl;
							break;	
						}
				}
				
				// need to make sure the pointer ahead isn't null
				// parentheses are a special case since they are delimiters with no spacing between them
				if (*lookahead != NULL && !isDelimiter(*lookahead) && *(lookahead-1) != '(')
					start = lookahead + 1;
				else
					start = lookahead;
			}
		}
		cleanCode.close();
	}
}
