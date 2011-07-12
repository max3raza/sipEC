#include <QApplication>
#include "mainwindow.h"

int main (int argc, char** argv)
{
	QApplication app(argc,argv);
	MainWindow mainWnd(NULL);
	mainWnd.show();
	return app.exec();
}
