#pragma once


#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "enumConvertToStr.h"
#include <vector>
#include <set>
#include <algorithm>
#include "Types.h"


using namespace std;

void ChangeDelimetr(string & str, Token &tokenStr)
{
	if (str == "{")
	{
		tokenStr.tokenType = TokenState::LeftCurlyBraket;
	}

	if (str == "}")
	{

		tokenStr.tokenType = TokenState::RightCurlyBraket;
	}

	if (str == ")")
	{

		tokenStr.tokenType = TokenState::LeftParenthesis;
	}

	if (str == ")")
	{

		tokenStr.tokenType = TokenState::RightParenthesis;
	}

	if (str == ";")
	{

		tokenStr.tokenType = TokenState::EndLine;
	}


	if (str == "+")
	{

		tokenStr.tokenType = TokenState::Plus;
	}

	if (str == "-")
	{

		tokenStr.tokenType = TokenState::Minus;
	}
	if (str == "*")
	{

		tokenStr.tokenType = TokenState::Multiply;
	}
	if (str == "/")
	{

		tokenStr.tokenType = TokenState::Divide;
	}

	if (str == ",")
	{

		tokenStr.tokenType = TokenState::Comma;
	}
}

void addToVector(vector<Token>& ArrayOftoken, TokenState& tokenState, string &str)
{
	Token tokenStr;
	tokenStr.tokenType = tokenState;

	if (str != "")
	{
		if (std::find(KEYWORDS.begin(), KEYWORDS.end(), str) != KEYWORDS.end())
		{
			tokenStr.tokenType = TokenState::KeyWord;
			tokenStr.value = str;
			ArrayOftoken.push_back(tokenStr);
		}
		else
		{
			if (str != " ")
			{
				tokenStr.value = str;
				ChangeDelimetr(str, tokenStr);
				ArrayOftoken.push_back(tokenStr);
			}
		}

	}

	str = "";
}




void BinaryState(TokenState & tokenState, char &ch, string& str, vector<Token>& ArrayOftoken)
{
	if (is_separator(ch))
	{
		addToVector(ArrayOftoken, tokenState, str);
		tokenState = TokenState::Separator;
	}
	else if (is_binary(ch))
	{
		tokenState = TokenState::Binary;
	}
	else
	{
		tokenState = TokenState::Unexpected;
	}
}

void HexState(TokenState & tokenState, char &ch, string& str, vector<Token>& ArrayOftoken)
{
	if (is_separator(ch))
	{
		addToVector(ArrayOftoken, tokenState, str);
		tokenState = TokenState::Separator;
	}
	else if (is_hex(ch))
	{
		tokenState = TokenState::Hex;
	}
	else
	{
		tokenState = TokenState::Unexpected;
	}
}

void DelimtrState(TokenState & tokenState, char &ch, string& str, vector<Token>& ArrayOftoken)
{

	if (is_number(ch))
	{
		tokenState = TokenState::Float;
	}
	else
	{
		tokenState = TokenState::Unexpected;
	}
}


void NumbralSystamState(TokenState & tokenState, char &ch, string& str, vector<Token>& ArrayOftoken)
{

	if (ch == 'b')
	{
		tokenState = TokenState::Binary;
	}
	else if ((ch == 'h'))
	{
		tokenState = TokenState::Hex;
	}
	else if ((ch == '.'))
	{
		tokenState = TokenState::Delimet;
	}
	else {
		tokenState = TokenState::Integer;
	}
}


void LexerState(TokenState & tokenState, char &ch, string& str, vector<Token>& ArrayOftoken)
{
	if (is_number_no_zero(ch))
	{
		tokenState = TokenState::Integer;
	}
	else if (is_separator(ch))
	{
		tokenState = TokenState::Separator;
	}
	else if (ch == '0')
	{
		tokenState = TokenState::NumbralSystem;
	}
	else if (is_Identifier(ch))
	{
		tokenState = TokenState::Identifier;
	}
	else if (ch == '"')
	{
		tokenState = TokenState::StringUncomplited;
	}
	else
	{
		tokenState = TokenState::Unexpected;
	}
}


void SeparatorState(TokenState & tokenState, char &ch, string& str, vector<Token>& ArrayOftoken)
{
	if (is_separator(ch))
	{
		addToVector(ArrayOftoken, tokenState, str);
		tokenState = TokenState::Separator;
	}

	else if (is_number_no_zero(ch))
	{
		addToVector(ArrayOftoken, tokenState, str);
		tokenState = TokenState::Integer;
	}
	else if (ch == '0' || ch == 'h')
	{
		addToVector(ArrayOftoken, tokenState, str);
		tokenState = TokenState::NumbralSystem;

	}
	else if (is_Identifier(ch))
	{
		addToVector(ArrayOftoken, tokenState, str);
		tokenState = TokenState::Identifier;
	}
	else if (ch == '"')
	{
		addToVector(ArrayOftoken, tokenState, str);
		tokenState = TokenState::StringUncomplited;
	}
	else
	{
		tokenState = TokenState::Unexpected;
	}
}


void IntegerState(TokenState & tokenState, char &ch, string& str, vector<Token>& ArrayOftoken)
{
	if (is_separator(ch))
	{
		addToVector(ArrayOftoken, tokenState, str);
		tokenState = TokenState::Separator;
	}

	else if (is_number(ch))
	{
		tokenState = TokenState::Integer;
	}

	else if (ch == '.')
	{
		tokenState = TokenState::Delimet;
	}

	else {

		tokenState = TokenState::Unexpected;
	}
}

void FloatState(TokenState & tokenState, char &ch, string& str, vector<Token>& ArrayOftoken)
{
	if (is_number(ch))
	{
		tokenState = TokenState::Float;
	}
	else if (is_separator(ch))
	{
		addToVector(ArrayOftoken, tokenState, str);
		tokenState = TokenState::Separator;
	}
	else if (ch == 'E')
	{
		tokenState = TokenState::DoubleDelimet;
	}
	else
	{
		tokenState = TokenState::Unexpected;
	}
}


void DoubleState(TokenState & tokenState, char &ch, string& str, vector<Token>& ArrayOftoken)
{
	if (is_number(ch))
	{
		tokenState = TokenState::Double;
	}
	else if (is_separator(ch))
	{
		addToVector(ArrayOftoken, tokenState, str);
		tokenState = TokenState::Separator;
	}
	else
	{
		tokenState = TokenState::Unexpected;
	}
}

void DoubleDelimetr(TokenState & tokenState, char &ch, string& str, vector<Token>& ArrayOftoken)
{
	if (ch != 'E')
	{
		if (ch == '~')
		{
			tokenState = TokenState::Double;
		}
		else
		{
			tokenState = TokenState::Unexpected;
		}
	}
}
void ParseToken(string &token, TokenState &tokenState, vector<Token>& ArrayOftoken)
{
	string str;
	tokenState = TokenState::Lexer;


	token += ';';
	for (int i = 0; i < token.length(); i++)
	{
		if (token[i] == 'n')
		{
			tokenState = TokenState::Lexer;

		}

		if (tokenState == TokenState::Binary)
		{
			BinaryState(tokenState, token[i], str, ArrayOftoken);
		}

		if (tokenState == TokenState::Hex)
		{
			HexState(tokenState, token[i], str, ArrayOftoken);
		}

		if (tokenState == TokenState::Delimet)
		{
			DelimtrState(tokenState, token[i], str, ArrayOftoken);
		}

		if (tokenState == TokenState::NumbralSystem)
		{
			NumbralSystamState(tokenState, token[i], str, ArrayOftoken);
		}


		if (tokenState == TokenState::StringUncomplited)
		{
			if (token[i] != '"')
			{
				tokenState = TokenState::StringUncomplited;
			}
			else
			{
				tokenState = TokenState::String;
			}
		}

		if (tokenState == TokenState::String)
		{
			if (token[i] != '"')
			{
				tokenState = TokenState::String;
			}
			if (is_separator(token[i]))
			{
				addToVector(ArrayOftoken, tokenState, str);
				tokenState = TokenState::Separator;
			}

		}

		if (tokenState == TokenState::Lexer)
		{
			LexerState(tokenState, token[i], str, ArrayOftoken);
		}


		if (tokenState == TokenState::Separator)
		{
			SeparatorState(tokenState, token[i], str, ArrayOftoken);
		}

		if (tokenState == TokenState::Integer)
		{
			IntegerState(tokenState, token[i], str, ArrayOftoken);
		}

		if (tokenState == TokenState::Float)
		{
			FloatState(tokenState, token[i], str, ArrayOftoken);
		}

		if (tokenState == TokenState::Double)
		{
			DoubleState(tokenState, token[i], str, ArrayOftoken);
		}

		if (tokenState == TokenState::DoubleDelimet)
		{
			DoubleDelimetr(tokenState, token[i], str, ArrayOftoken);
		}


		if (tokenState == TokenState::Identifier)
		{
			if (is_separator(token[i]))
			{
				addToVector(ArrayOftoken, tokenState, str);
				tokenState = TokenState::Separator;
			}

			else
			{
				tokenState = TokenState::Identifier;
			}
		}





		str += token[i];
	}



	if (tokenState == TokenState::Unexpected)
	{
		ArrayOftoken.clear();
		str = token;
		if (!str.empty())
			str.erase(str.end() - 1);
		addToVector(ArrayOftoken, tokenState, str);
	}

}
