#pragma once
#include "enumConvertToStr.h"
#include  <string>
#include <vector>

using namespace std;

struct Token
{
	TokenState tokenType = TokenState::Lexer;
	std::string value = "";
};

std::vector<std::string> KEYWORDS
{
		"var",
		"main",
		"import",
		"while",
		"break",
		"continue",
		"readln"
		"printl"
		"read"
		"print"
		"and",
		"or",
		"for",
		"if",
		"do",
		"bool",
		"int",
		"float",
		"function",
		"return",
		"void",
		"true",
		"false",
};

std::vector<std::string> SEPARATORS
{
	"{",
	"}",
	"(",
	")",
	";",
	"+",
	"-",
	"/",
	"*",
	",",
	":",
	";"
};


bool is_arifmetical_opiration(char ch) {
	switch (ch) {
	case '-':
	case '=':
	case '/':
	case '*':
		return true;
	default:
		return false;
	}
}


bool is_separator(char ch) {
	switch (ch) {
	case '{':
	case '}':
	case '(':
	case ')':
	case ';':
	case '+':
	case '-':
	case '=':
	case '/':
	case '*':
	case ',':
	case ':':
	case ' ':
		return true;
	default:
		return false;
	}
}


bool is_number(char ch) {
	switch (ch) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
	default:
		return false;
	}
}


bool is_number_no_zero(char ch) {
	switch (ch) {
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
	default:
		return false;
	}
}

bool is_binary(char ch) {
	switch (ch) {
	case '0':
	case '1':
		return true;
	default:
		return false;
	}
}



bool is_hex(char ch)
{
	if (is_number(ch))
	{
		return true;
	}

	switch (ch) {
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
		return true;
	default:
		return false;
	}
}

bool is_Identifier(char ch)
{
	int aciiNum = int(ch);

	if ((aciiNum >= 65 && aciiNum <= 90) || (aciiNum >= 97 && aciiNum <= 121) || ch == '-' || ch == '_')
	{
		return true;
	}

	return false;
}

bool is_Id_Start_Special(char ch)
{
	switch (ch) {
	case '_':
	case '-':
		return true;
	default:
		return false;
	}
}
