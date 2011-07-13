#include "proxy.h"

/****************
* Constructor   *
****************/
Proxy::Proxy(QObject* parent, quint16 listenPort, QHostAddress address,quint16 serverPort) :
/*initialize members*/
conNum(0), repeatNum(0), outSocket(NULL), inSocket(NULL), listenSocket (NULL),
state(QAbstractSocket::UnconnectedState) ,fnInSocketReceive(NULL), fnOutSocketReceive(NULL) {
	this->listenPort=listenPort;
	this->listenAddress=QHostAddress("127.0.0.1");
	this->serverAddress=address;
	this->serverPort=serverPort;
 }
/****************
* Destructor    *
****************/
Proxy::~Proxy() {
	if (outSocket != NULL)
		delete outSocket;
	if (listenSocket != NULL)
		delete listenSocket;
}
/********************************
* function create message box   *
*  with debug message
********************************/
void Proxy::messageBox(QString text) {
	QMessageBox mb;
	mb.setText(text);
	mb.exec();
}

/****************
* startup proxy *
****************/
void Proxy::startup() {
	listenSocket=new QTcpServer(this);
	if (!listenSocket->listen(listenAddress, listenPort) )
		messageBox("Could not create listen socket");
	QObject::connect(listenSocket,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}

/****************************
 *receive new connection    *
 ***************************/
void Proxy::onNewConnection() {
	if ( !listenSocket->hasPendingConnections() || conNum > MAX_CONNECTIONS)
		return;
	inSocket=listenSocket->nextPendingConnection();
	conNum++;
	outSocket=new QTcpSocket(this);

	/*connect signals in and out sockets to slots*/
	connect(inSocket, SIGNAL(stateChanged()), this, SLOT(onInSockeStateChanged()));
	connect(outSocket, SIGNAL(connected()), this, SLOT(onConnected()));
	connect(outSocket, SIGNAL(stateChanged()), this, SLOT(onOutSocketStateChanged()));
	/* try to connect to server */
	connectToServer();
}

/****************************************
* function try to connect to the server *
****************************************/
void Proxy::connectToServer() {
	if (repeatNum <= MAX_RETRY) {
		repeatNum++;
		outSocket->connectToHost(serverAddress, serverPort, QIODevice::ReadWrite);
		outSocket->waitForConnected(15000);
	} else {
		state=QAbstractSocket::UnconnectedState;
		outSocket->close();
		inSocket->close();
		repeatNum=0;
	}
}
/****************************************************
* function called when out socket connect to host   *
****************************************************/
void Proxy::onConnected() {
	repeatNum=0;
	state=outSocket->state();

	/*connect signal readyRead() to slots*/
	connect(inSocket, SIGNAL(readyRead()), this, SLOT(onReadyInSocket()));
	connect(outSocket, SIGNAL(readyRead()), this, SLOT(onReadyOutSocket()));
}

/************************************
*    function called when change    *
*    state out socket               *
************************************/
void Proxy::onOutSocketStateChanged() {
	if (outSocket->state() ==  QAbstractSocket::UnconnectedState &&
		state != QAbstractSocket::UnconnectedState )
	{
		connectToServer();
	}
}

/************************************
*    function called when change    *
*    state in socket                *
************************************/
void Proxy::onInSockeStateChanged() {
    if (inSocket->state() == QAbstractSocket::UnconnectedState) {
        outSocket->close();
        state = QAbstractSocket::UnconnectedState;
    }
}
/****************************************
*  Slot when emit signal readyRead()    *
*  for inSocket
****************************************/
void Proxy::onReadyInSocket() {

    if (fnInSocketReceive != NULL) {
        /* if fnInSocketReceive != NULL*/
        if(fnInSocketReceive()){
            /* if fnInSocketReceive return TRUE
               send new data to out socket
            */

        }
    } else {
        /* if fnInSocketReceive==NULL*/
        /* send data to outSocket */

    }
}

/****************************************
*  Slot when emit signal readyRead()    *
*  for outSocket
****************************************/
void Proxy::onReadyOutSocket() {
    if (fnOutSocketReceive != NULL) {
        /* if fnOutSocketreceive != NULL */
        if (fnOutSocketReceive()) {
            /* if fnOutSocketreceive return TRUE  */
            /* send data to inSocket */

        }
    } else {
        /* fnOutSocketReceive == NULL */
        /* send data to inSocket*/


    }
}
