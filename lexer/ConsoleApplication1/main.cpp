

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "enumConvertToStr.h"
#include <vector>
#include <set>
#include <algorithm>
#include "Types.h"
#include "TokenState.h"

using namespace std;

vector<Token> getToken(string token)
{
	TokenState tokenState;
	vector<Token> ArrayOftoken;

	ParseToken(token, tokenState, ArrayOftoken);

	return ArrayOftoken;
}

void Lexer(const string& readTxt)
{
	ifstream fileIn(readTxt);
	string token;

	while (!fileIn.eof())
	{
		//fileIn >> token;

		getline(fileIn, token);
		vector<Token> expectToken = getToken(token);

		for (int i = 0; i < expectToken.size(); i++)
		{
			cout << state_to_string(expectToken[i].tokenType) << " : " << expectToken[i].value << endl;
		}
	}


}



int main(int argc, char* argv[])
{

	if (argc != 3)
	{
		cout << "Error in Argument listing: lexer.exe  first.txt second.txt " << endl;
		return -1;
	}

	Lexer(argv[1]);
}
