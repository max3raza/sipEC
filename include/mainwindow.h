#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "cwindow.h"

class MainWindow : public QMainWindow
{
Q_OBJECT
private:
	CWindow* cwindow;
	QMenuBar* menuBar;
	QAction* settingAction;
public:
	MainWindow(QWidget* parent);
	virtual ~MainWindow();
};

#endif
