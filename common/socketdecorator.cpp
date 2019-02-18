#include "socketdecorator.h"

SocketDecorator::SocketDecorator(ISocketAdapter *sock, QObject *parent) :
  ISocketAdapter(parent), m_pSock(sock) {
  connect(m_pSock, SIGNAL(disconnected()), SLOT(on_disconnected()));
  connect(m_pSock, SIGNAL(message(QString)), SLOT(on_message(QString)));
}

SocketDecorator::~SocketDecorator() {
}

void SocketDecorator::on_disconnected() {
  emit disconnected();
}
