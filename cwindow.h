#ifndef CWINDOW_H
#define CWINDOW_H
#include <QtGui>
#include "proxy.h"

class CWindow : public QWidget
{
public:
	CWindow();
	virtual ~CWindow();
private:
	QPushButton* startBtn;
	QTextEdit* log;
	QVBoxLayout* v_layout;
slots:
	void onStartBtnClick();
};
#endif