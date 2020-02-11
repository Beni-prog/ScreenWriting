#include "OOPRetakeExam.h"
#include <QtWidgets/QApplication>
#include"ScreenWritingRepository.h"
#include "WriterWindow.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ScreenWritingRepository repo("ideas.txt", "writers.txt");
	vector<Writer> writers = repo.getWriters();
	repo.testAll();
	for (auto el : writers)
	{
		WriterWindow* gui = new WriterWindow(repo, el.getExpertize(),el.getName());
		gui->show();
	}
	return a.exec();
}
