#ifndef CWINDOW_H
#define CWINDOW_H
#include <QtGui>
#include "proxy.h"

class CWindow : public QWidget
{
Q_OBJECT
public:
    /* constructor */
	CWindow();
	/* destructor */
	virtual ~CWindow();
private:
    /* private variables*/
	QPushButton* startBtn;
	QTextEdit* log;
	QVBoxLayout* v_layout;
	Proxy* proxy;
private slots:
    /* click start button */
	void onStartBtnClick();
};
#endif
