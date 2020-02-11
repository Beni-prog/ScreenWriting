#pragma once
#include<string>
using namespace std;
class Idea
{
private:
	string description;
	string status;
	string creator;
	int act;
public:
	Idea(string description,string status, string creator, int act):description(description), status(status),creator(creator),act(act){}

	string getDescr() { return description; }
	string getStatus() { return status; }
	string getCreator() { return creator; }
	int getAct() { return act; }

	string toString() { return description + "|" + status + "|" + creator + "|" + to_string(act); }
	void changeIdea() { this->status = "accepted"; }
	~Idea();
};

