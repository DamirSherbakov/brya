#ifndef SERVER_H
# define SERVER_H
# include <QObject>
# include <QList>

class QTcpServer;
class QTcpSocket;
class ISocketAdapter;

class Server : public QObject {
  Q_OBJECT
public:
  explicit Server(int nPort, QObject *parent = 0);
public slots:
  void on_newConnection();
  void on_disconnected();
  void on_message(QString);
signals:
  void message(QString);
protected:
  QTcpServer* m_ptcpServer;
};

#endif // SERVER_H
