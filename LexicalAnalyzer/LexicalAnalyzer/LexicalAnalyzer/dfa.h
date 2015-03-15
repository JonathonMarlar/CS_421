#pragma once

#include <iostream>
#include <string>
#include <regex>
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

int dfaTextToken(string line, string expr, int goalTokenID);
int getToken(string line, string expr, int goalTokenID);

/*
int dfa_VAR(string line);
int dfa_BEGIN(string line);
int dfa_END(string line);
int dfa_INTEGER(string line);
int dfa_FOR(string line);
int dfa_READ(string line);
int dfa_WRITE(string line);
int dfa_TO(string line);
int dfa_DO_OR_DIV(string line);
int dfa_id(string line);
int dfa_int(string line);
int dfa_SEMI(string line);
int dfa_EQ_OR_COL(string line);
int dfa_COMMA(string line);
int dfa_PLUS(string line);
int dfa_MINUS(string line);
int dfa_TIMES(string line);
int dfa_LEFTPAREN(string line);
int dfa_RIGHTPAREN(string line);
*/