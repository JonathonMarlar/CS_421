#include <iostream>
#include <string>
#include <regex>
#include "dfa.h"
using namespace std;

// To save us the trouble of remembering the correct token IDs,
// let's use an enumeration to 'save' them in the program
enum TokenID
{
	PROGRAM = 1,
	VAR,
	BEGIN,
	END,
	ENDP,
	INTEGER,
	FOR,
	READ,
	WRITE,
	TO,
	DO,
	SEMICOLON,
	COLON,
	COMMA,
	EQUALS,
	PLUS,
	MINUS,
	TIMES,
	DIV,
	LEFTPAREN,
	RIGHTPAREN,
	IDENTIFIER,
	NUM
};

/*
dfa_*:
- Takes in a line string
- Letter by letter, checks until there is a space (or max identifier of 16 chars
- Checks against regular expression (or DFA) and changes tokens accordingly
- Returns the token ID
*/
int dfa_PROGRAM(string line)
{
	// it can be an identifier if it isn't PROGRAM
	int tokenID = IDENTIFIER;
	regex r("PROGRAM");
	char* lookahead = &line[0];
	string temp = "";

	// the lookahead will continue until it finds a space or is longer than 16 chars
	while ((*lookahead != ' ') || (temp.length() < 16))
	{
		// add this to temp
		temp = temp + *lookahead;
		lookahead++;
	}

	// if it matches our DFA, then the token ID changes
	if (regex_match(temp, r))
		tokenID = PROGRAM;

	return tokenID;
}

int dfa_VAR(string line) { return 0; }
int dfa_BEGIN(string line) { return 0; }
int dfa_END(string line) { return 0; }
int dfa_INTEGER(string line) { return 0; }
int dfa_FOR(string line) { return 0; }
int dfa_READ(string line) { return 0; }
int dfa_WRITE(string line) { return 0; }
int dfa_TO(string line) { return 0; }
int dfa_DO_OR_DIV(string line) { return 0; }
int dfa_id(string line) { return 0; }
int dfa_int(string line) { return 0; }
int dfa_SEMI(string line) { return 0; }
int dfa_EQ_OR_COL(string line) { return 0; }
int dfa_COMMA(string line) { return 0; }
int dfa_PLUS(string line) { return 0; }
int dfa_MINUS(string line) { return 0; }
int dfa_TIMES(string line) { return 0; }
int dfa_LEFTPAREN(string line) { return 0; }
int dfa_RIGHTPAREN(string line) { return 0; }