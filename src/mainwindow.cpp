#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
	cwindow= new CWindow();
	menuBar=new QMenuBar(this);
	settingAction=menuBar->addAction("Settings");
	setMenuBar(menuBar);
	setCentralWidget(cwindow);
}

MainWindow::~MainWindow() {
	if (cwindow != NULL)
		delete cwindow;
}
