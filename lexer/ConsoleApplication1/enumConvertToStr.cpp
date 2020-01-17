
#include "pch.h"
#include "enumConvertToStr.h"
#include <string>

using namespace std;



string state_to_string(TokenState &token)
{
	switch (token)
	{
	case TokenState::Integer: return "Integer";
	case TokenState::Identifier: return "Identifier";
	case TokenState::EndLine: return "EndLine";
	case TokenState::LeftCurlyBraket: return "LeftCurlyBraket"; // "{"
	case TokenState::RightCurlyBraket: return "RightCurlyBraket"; // "}";
	case TokenState::RightParenthesis: return "RightParenthesis"; // "(";
	case TokenState::LeftParenthesis: return "LeftParenthesis"; // ")"
	case TokenState::KeyWord: return "KeyWord";
	case TokenState::Plus: return "Plus";
	case TokenState::Minus: return "Minus";
	case TokenState::Divide: return "Divide";
	case TokenState::Multiply: return "Multiply";
	case TokenState::Equal: return "Equal";
	case TokenState::Binary: return "Binary";
	case TokenState::Hex: return "Hex";
	case TokenState::Separator: return "Separator";
	case TokenState::Float: return "Float";
	case TokenState::Lexer: return "Lexer";
	case TokenState::Delimet: return "Delimet";
	case TokenState::Double: return "Float";
	case TokenState::NumbralSystem: return "NumbralSystem";
	case TokenState::StringSystem: return "StringSystem";
	case TokenState::String: return "String";
	case TokenState::StringUncomplited: return "StringUncomplited";
	case TokenState::Comma: return "Comma";




	default:  return "Unexpected";
	}

}
