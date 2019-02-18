#include "server.h"
#include "serversocketadapter.h"

#include "calcsockdecorator.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QString>

Server::Server(int nPort, QObject *parent) : QObject(parent),
  m_ptcpServer(new QTcpServer(this)) {

  connect(m_ptcpServer, SIGNAL(newConnection()), SLOT(on_newConnection()));

  if (false == m_ptcpServer->listen(QHostAddress::Any, nPort)) {
    m_ptcpServer->close();
    throw m_ptcpServer->errorString();
  } 
}

void Server::on_newConnection() {
  QTextStream(stdout) << "new connection" << endl;

  CalcSockDecorator *decoratedSock = new CalcSockDecorator
      (new ServerSocketAdapter(m_ptcpServer->nextPendingConnection(), this), this);

  decoratedSock->sendString("connect");

  connect(decoratedSock, SIGNAL(disconnected()), SLOT(on_disconnected()));
  connect(decoratedSock, SIGNAL(message(QString)), SLOT(on_message(QString)));
  connect(this, SIGNAL(message(QString)), decoratedSock, SLOT(on_send_request(QString)));
}

void Server::on_disconnected() {
  QTextStream(stdout) << "client disconnected" << endl;
}

void Server::on_message(QString msg) {
  emit message(msg);
}


