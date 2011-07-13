#include <QHostAddress>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostAddress>
#include <QMessageBox>
#include <QObject>
#define MAX_RETRY 5
#define MAX_CONNECTIONS 1

class Proxy : public QObject
{
	Q_OBJECT
public:
	/*constructor*/
	Proxy (QObject* parent, quint16 listenPort,QHostAddress address, quint16 serverPort);
	/*destructor */
	virtual ~Proxy();
	/*startup*/
	void startup();

	/* callback function*/
	bool (*fnInSocketReceive)();
	bool (*fnOutSocketReceive)();


private:
	/*variable*/
	QTcpSocket* inSocket;
	QTcpSocket* outSocket;
	QTcpServer* listenSocket;
	QHostAddress listenAddress;
	QHostAddress serverAddress;
	quint16 listenPort;
	quint16 serverPort;
	/* number of repeat to try
	 *establish connection to server
	 */
	quint16 repeatNum;
	quint16 conNum;
	QAbstractSocket::SocketState state;

	/*function*/
	void messageBox(QString text);
	void connectToServer();

	/*slots*/
private slots:
	void onNewConnection();
	void onConnected();
	void onOutSocketStateChanged();
    void onInSockeStateChanged();
    void onReadyInSocket();
    void onReadyOutSocket();
};
