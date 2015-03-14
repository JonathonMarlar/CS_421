#pragma once

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int dfa_PROGRAM(string line);
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