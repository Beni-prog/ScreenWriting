#pragma once
#include <string>
using namespace std;
class Writer
{
private:
	string name;
	string expertize;
public:
	Writer(string name, string expertize):name(name),expertize(expertize){}

	string getName() { return name; }
	string getExpertize() { return expertize; }
	~Writer();
};

