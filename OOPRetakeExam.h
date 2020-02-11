#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOPRetakeExam.h"

class OOPRetakeExam : public QMainWindow
{
	Q_OBJECT

public:
	OOPRetakeExam(QWidget *parent = Q_NULLPTR);

private:
	Ui::OOPRetakeExamClass ui;
};
