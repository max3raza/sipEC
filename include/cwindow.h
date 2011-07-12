#ifndef CWINDOW_H
#define CWINDOW_H
#include <QtGui>
#include "proxy.h"

class CWindow : public QWidget
{
Q_OBJECT
public:
	CWindow();
	virtual ~CWindow();
private:
	QPushButton* startBtn;
	QTextEdit* log;
	QVBoxLayout* v_layout;
	Proxy* proxy;
private slots:
	void onStartBtnClick();
};
#endif
