#include "ScreenWritingRepository.h"
#include<fstream>
#include "Utils.h"
#include "IdeaException.h"
#include<algorithm>
ScreenWritingRepository::ScreenWritingRepository(string ideaFile, string writerFile):ideaFile(ideaFile), writerFile(writerFile)
{
	this->readFromFile();
}

void ScreenWritingRepository::readFromFile()
{
	ifstream ifs1(this->ideaFile, ifstream::in);
	ifstream ifs2(this->writerFile, ifstream::in);

	string line;
	vector<string> tokens;

	while (getline(ifs1, line))
	{
		tokens = tokenize(line, '|');
		ideas.push_back(Idea(tokens[0], tokens[1], tokens[2], stoi(tokens[3])));
	}

	while (getline(ifs2, line))
	{
		tokens = tokenize(line, '|');
		writers.push_back(Writer(tokens[0], tokens[1]));
	}
}

void ScreenWritingRepository::addIdea(Idea i)
{
	if (i.getDescr() == "")
		throw IdeaException("The description can not be empty!");
	if (i.getAct() < 1 || i.getAct() > 3)
		throw IdeaException("The act is not correct!");
	for (auto el : ideas)
		if (i.getAct() == el.getAct() && i.getDescr() == el.getDescr())
			throw IdeaException("This idea already exists!");
	ideas.push_back(i);
	this->notify();
}

void ScreenWritingRepository::removeIdea(string descr)
{
	ideas.erase(find_if(ideas.begin(), ideas.end(),[descr](Idea i) {
		if (i.getDescr() == descr && i.getStatus() == "proposed")
			throw IdeaException("The status must be accepted!");
		return i.getDescr() == descr;
	}));
	this->notify();
}

void ScreenWritingRepository::acceptIdea(string descr, string name)
{
	auto idea = find_if(ideas.begin(), ideas.end(), [descr](Idea i) {
		if (i.getStatus() == "accepted")
			throw IdeaException("The status must be proposed!");
		return i.getDescr() == descr && i.getStatus() == "proposed";
	});
	idea->changeIdea();
	this->notify();
}

void ScreenWritingRepository::saveIdea(string fileName)
{
	ofstream ofs(fileName, ofstream::trunc);

	vector<Idea> act1;
	vector<Idea> act2;
	vector<Idea> act3;

	copy_if(ideas.begin(), ideas.end(), back_inserter(act1), [](Idea i) {
		return i.getAct() == 1&& i.getStatus()=="accepted";
	});
	copy_if(ideas.begin(), ideas.end(), back_inserter(act2), [](Idea i) {
		return i.getAct() == 2 && i.getStatus() == "accepted";
	});
	copy_if(ideas.begin(), ideas.end(), back_inserter(act3), [](Idea i) {
		return i.getAct() == 3 && i.getStatus() == "accepted";
	});
	ofs << "Act1: \n";
	for (auto el : act1)
		ofs << el.getDescr() << "(" << el.getCreator() << ")" << "\n";
	ofs << "Act2: \n";
	for (auto el : act2)
		ofs << el.getDescr() << "(" << el.getCreator() << ")" << "\n";
	ofs << "Act3: \n";
	for (auto el : act3)
		ofs << el.getDescr() << "(" << el.getCreator() << ")" << "\n";
}

void ScreenWritingRepository::testAll()
{
	ScreenWritingRepository repo("ideas.txt", "writers.txt");
	vector<Idea> ideas = repo.getIdeas();

	repo.addIdea(Idea("idea6", "proposed", "me", 1));
	ideas = repo.getIdeas();
	assert(ideas[ideas.size() - 1].getAct() == 1);
	assert(ideas[ideas.size() - 1].getDescr() == "idea6");
	assert(ideas[ideas.size() - 1].getStatus() == "proposed");
	assert(ideas[ideas.size() - 1].getCreator() == "me");

	repo.removeIdea("idea4");
	
	assert(ideas[ideas.size() - 1].getAct() == 1);
	assert(ideas[ideas.size() - 1].getDescr() == "idea6");
	assert(ideas[ideas.size() - 1].getStatus() == "proposed");
	assert(ideas[ideas.size() - 1].getCreator() == "me");
}

ScreenWritingRepository::~ScreenWritingRepository()
{
}
