#include "WriterWindow.h"
#include "qmessagebox.h"
#include "IdeaException.h"

vector<string> tokenize(string line, char delimiter);

WriterWindow::WriterWindow(ScreenWritingRepository& _repo, string descr, string name, QWidget *parent)
	: repo(_repo), descr(descr), name(name), QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->name));
	this->repo.addObs(this);
	
	if (descr != "senior")
	{
		ui.removePushButton->hide();
		ui.solvePushButton->hide();
	}
	this->connectSignalsAndSlots();
	this->update();
}


void WriterWindow::populateList()
{
	ui.ideaListWidget->clear();
	for (auto el : ideaList)
	{
		QListWidgetItem* item = new QListWidgetItem;
		item->setText(QString::fromStdString(el.toString()));
		ui.ideaListWidget->addItem(item);
	}
}

void WriterWindow::sortList()
{
	sort(ideaList.begin(), ideaList.end(), [](Idea i1, Idea i2) {
		if (i1.getAct() > i2.getAct())return false;
		if (i1.getAct() < i2.getAct())return true;
		if (i1.getCreator() > i2.getCreator())return false;
		if (i1.getCreator() < i2.getCreator())return true;
		return false;
	});
}

void WriterWindow::update()
{
	this->ideaList = repo.getIdeas();
	this->sortList();
	this->populateList();
}

void WriterWindow::addIdeaGUI()
{
	string descr = ui.descriptionLineEdit->text().toStdString();
	int act = ui.actLineEdit->text().toInt();
	string status = "proposed";
	try
	{
		this->repo.addIdea(Idea(descr, status, this->name, act));
		this->update();
	}
	catch(IdeaException e)
	{
		QMessageBox box;
		box.critical(0, "Error", QString::fromStdString(e.what()));

	}
}

void WriterWindow::removeIdeaGUI()
{
	vector<string> tokens = tokenize(ui.ideaListWidget->currentItem()->text().toStdString(), '|');

	try
	{
		this->repo.removeIdea(tokens[0]);
		this->update();
	}
	catch (IdeaException e)
	{
		QMessageBox box;
		box.critical(0, "Error", QString::fromStdString(e.what()));
	}
}

void WriterWindow::acceptIdeaGUI()
{
	vector<string> tokens = tokenize(ui.ideaListWidget->currentItem()->text().toStdString(), '|');

	try
	{
		this->repo.acceptIdea(tokens[0], this->name);
		this->update();
	}
	catch (IdeaException e)
	{
		QMessageBox box;
		box.critical(0, "Error", QString::fromStdString(e.what()));
	}
}

void WriterWindow::saveIdeaGUI()
{
	this->repo.saveIdea("plots.txt");
}

void WriterWindow::connectSignalsAndSlots()
{
	connect(ui.addPushButton, &QPushButton::clicked, this, &WriterWindow::addIdeaGUI);
	connect(ui.removePushButton, &QPushButton::clicked, this, &WriterWindow::removeIdeaGUI);
	connect(ui.solvePushButton, &QPushButton::clicked, this, &WriterWindow::acceptIdeaGUI);
	connect(ui.savePushButton, &QPushButton::clicked, this, &WriterWindow::saveIdeaGUI);
}

WriterWindow::~WriterWindow()
{
}
