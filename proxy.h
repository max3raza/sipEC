#include <QHostAddress>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostAddress>
#include <QMessageBox>
#include <QObject>
#define MAX_RETRY 5

class Proxy : public QObject
{
	Q_OBJECT
public:	
	/*constructor*/
	Proxy (QObject* parent, quint16 listenPort,QHostAddress address, quint16 serverPort);
	/*destructor */
	virtual ~Proxy();
	/*get Text*/
	QString getText();
	void startup();
	
	/* public signals*/
signals:
	void onInSocketReceive();
	void onOutSocketReceive();
	

private:
	/*variable*/
	QTcpSocket* inSocket;
	QTcpSocket* outSocket;
	QTcpServer* listenSocket;
	QHostAddress listenAddress;
	QHostAddress serverAddress;
	quint16 listenPort;
	quint16 serverPort;
	quint16 repeatNum;
	QAbstractSocket::SocketState state;
	
	/*function*/
	void messageBox(QString text);
	void connectToHost();
	
	/*slots*/
private slots:
	void onNewConnection();
	void onConnected();
	void onStateChanged();
	

};