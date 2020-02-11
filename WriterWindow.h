#pragma once

#include <QWidget>
#include "ui_WriterWindow.h"
#include "Observer.h"
#include"ScreenWritingRepository.h"
#include<string>
#include<vector>
using namespace std;
class WriterWindow : public QWidget,public Observer
{
	Q_OBJECT
private:
	ScreenWritingRepository& repo;
	vector<Idea> ideaList;
	string name;
	string descr;
public:
	WriterWindow(ScreenWritingRepository& _repo, string descr, string name, QWidget *parent = Q_NULLPTR);

	void populateList();
	void sortList();
	void update() override;
	void addIdeaGUI();
	void removeIdeaGUI();
	void acceptIdeaGUI();
	void saveIdeaGUI();
	void connectSignalsAndSlots();
	~WriterWindow();

private:
	Ui::WriterWindow ui;
};
