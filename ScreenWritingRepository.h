#pragma once
#include <vector>
#include <string>
#include"Idea.h"
#include"Writer.h"
#include <assert.h>

#include "Observer.h"

using namespace std;

class ScreenWritingRepository:public Subject
{
private:
	vector<Idea> ideas;
	vector<Writer> writers;
	string ideaFile;
	string writerFile;
public:
	ScreenWritingRepository(string ideaFile, string writerFile);

	vector<Idea> getIdeas() { return ideas; }
	vector<Writer> getWriters() { return writers; }

	void readFromFile();
	/*
	DESCR:it adds a new idea
	IN:an idea i
	OUT:-
	THROWS: ann error if the act is not correct, the description is empt or it already exists
	*/
	void addIdea(Idea i);

	/*
	DESCR:it removes an idea
	IN: a description
	OUT:-
	THROWS: an error if the idea is not accepted
	*/
	void removeIdea(string descr);

	void acceptIdea(string descr, string name);
	void saveIdea(string fileName);

	void testAll();
	~ScreenWritingRepository();
};

