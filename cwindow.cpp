#include "cwindow.h"

CWindow::CWindow() {
	log=new QTextEdit(this);
	startBtn=new QPushButton("Start",this);
	v_layout=new QVBoxLayout();
	v_layout->addWidget(startBtn);
	v_layout->addWidget(log);
	setLayout(v_layout);
	proxy=new Proxy(this, 5060, QHostAddress("127.0.0.1"), 5060);
	connect(startBtn, SIGNAL(clicked()), this, SLOT(onStartBtnClick));
}
CWindow::~CWindow() {
	if (log != NULL)
		delete log;
}

void CWindow::onStartBtnClick() {
	proxy->startup();
}