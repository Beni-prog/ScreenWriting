#pragma once
#include <vector>

using namespace std;

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {};
};

class Subject
{
private:
	vector<Observer*> observers;
public:
	void addObs(Observer* obs)
	{
		observers.push_back(obs);
	}
	void notify()
	{
		for (auto el : observers)
		{
			el->update();
		}
	}
};