#include <iostream>
#include <string>
#include <regex>
#include <cctype>
#include "dfa.h"
using namespace std;

/*
dfa_*:
- Takes in a line string
- Letter by letter, checks until there is a space (or max identifier of 16 chars
- Checks against regular expression (or DFA) and changes tokens accordingly
- Returns the token ID
*/
/*
int dfaTextToken(string line, string expr, int goalTokenID)
{
	// it can be an identifier if it isn't PROGRAM
	int tokenID = IDENTIFIER;
	regex r(expr);
	char* lookahead = &line[0];
	string temp = "";

	// the lookahead will continue until it finds a space or is longer than 16 chars
	while (*lookahead != ' ')
	{
		// add this to temp
		temp = temp + *lookahead;
		lookahead++;

		if (temp.length() == 16)
			break;
	}

	// if it matches our DFA, then the token ID changes
	if (regex_match(temp, r))
		tokenID = goalTokenID;

	return tokenID;
}
*/

/*
getToken:
- Takes in a string, a regex, and a goal token ID
- Checks against regular expression (or DFA) and changes tokens accordingly
- Returns the token ID
*/
int getToken(string line, string expr, int goalTokenID)
{
	int tokenID = IDENTIFIER;
	regex r(expr);

	if (regex_match(line, r))
		tokenID = goalTokenID;

	// if it's still an identifier, we need to check if it's legit
	regex id("(A-Z)+(A-Z0-9_)*");
	if (tokenID == IDENTIFIER && !regex_match(line, id))
		tokenID = -1;

	return tokenID;
}

bool getDelimiter(char n)
{
	string delimiters = " ;:,()";

	for (int i = 0; i < delimiters.length(); i++)
	{
		if (n == delimiters[i])
			return true;
	}

	return false;
}
