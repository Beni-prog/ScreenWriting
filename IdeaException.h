#pragma once
#include <string>
using namespace std;

class IdeaException
{
private:
	string error;
public:
	IdeaException(string error):error(error){}
	string what() { return error; }
};