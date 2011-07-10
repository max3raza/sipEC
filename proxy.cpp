#include "proxy.h"

Proxy::Proxy(QObject* parent, quint16 listenPort, QHostAddress address,quint16 serverPort) {
	this->listenPort=listenPort;
	this->listenAddress=QHostAddress("127.0.0.1");
	this->serverAddress=address;
	this->serverPort=serverPort;
	this->state=QAbstractSocket::UnconnectedState;
	this->outSocket=NULL;
	this->inSocket=NULL;
	this->listenSocket=NULL;
}

Proxy::~Proxy() {
	if (outSocket != NULL)
		delete outSocket;
	if (listenSocket != NULL)
		delete listenSocket;
}

void Proxy::messageBox(QString text) {
	QMessageBox mb;
	mb.setText(text);
	mb.exec();
}

QString Proxy::getText() {
	return QString("Proxy");
}

void Proxy::startup() {
	listenSocket=new QTcpServer(this);
	if (!listenSocket->listen( listenAddress, listenPort))
		messageBox("Could not create listen socket");
	QObject::connect(listenSocket,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}

void Proxy::onNewConnection() {
	if (!listenSocket->hasPendingConnections())
		return;
	inSocket=listenSocket->nextPendingConnection();
	listenSocket->close();
	outSocket=new QTcpSocket(this);
	connect(outSocket, SIGNAL(connected()), this, SLOT(onConnected()));
	connect(outSocket, SIGNAL(stateChaged()), this, SLOT(onStateChanged()));
	connectToHost();
	messageBox("New Connection");
}

void Proxy::connectToHost() {
	if (repeatNum <= MAX_RETRY) {
		repeatNum++;
		outSocket->connectToHost(serverAddress, serverPort, QIODevice::ReadWrite);
	} else {
		state=QAbstractSocket::UnconnectedState;
		outSocket->close();
		inSocket->close();
		repeatNum=0;
	}
}

void Proxy::onConnected() {
	repeatNum=0;
	state=outSocket->state();
}

void Proxy::onStateChanged() {
	if (outSocket->state() ==  QAbstractSocket::UnconnectedState && 
		state != QAbstractSocket::UnconnectedState )
	{
		connectToHost();
	}
}