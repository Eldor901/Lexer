#pragma once
#include <string>
#include "pch.h"
#include "enumConvertToStr.h"
#include <string>

using namespace std;

enum class TokenState {
	Integer,
	Identifier,
	EndLine,
	LeftCurlyBraket,
	RightCurlyBraket,
	RightParenthesis,
	LeftParenthesis,
	KeyWord,
	Plus,
	Minus,
	Divide,
	Multiply,
	Equal,
	Unexpected,
	Separator,
	Hex,
	Binary,
	Float,
	Lexer,
	Delimet,
	DoubleDelimet,
	Double,
	Exepted,
	NumbralSystem,
	StringSystem,
	StringUncomplited,
	String,
	Comma
};


string state_to_string(TokenState &tokenState);
