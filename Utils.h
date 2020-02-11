#pragma once
#include<vector>
#include<string>
#include<sstream>

using namespace std;

vector<string> tokenize(string line, char delimiter)
{
	string token;
	vector<string> tokens;
	stringstream ss(line);

	while (getline(ss, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}