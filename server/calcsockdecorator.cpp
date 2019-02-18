#include "calcsockdecorator.h"
#include "calc.h"
#include <QThreadPool>

CalcSockDecorator::CalcSockDecorator(ISocketAdapter *sock, QObject *parent) :
  SocketDecorator(sock, parent) {
}

void CalcSockDecorator::on_message(QString msg) {
  Calc *calc = new Calc(msg, this);
  connect(calc, SIGNAL(result(QString)), SLOT(on_result(QString)));

  QThreadPool::globalInstance()->start(calc);
}

void CalcSockDecorator::sendString(const QString &str) {
  m_pSock->sendString(str);
}

void CalcSockDecorator::on_send_request(QString msg) {
  m_pSock->sendString(msg);
}

void CalcSockDecorator::on_result(QString res) {
  if (res == "")
    m_pSock->sendString("bad request");
  else
    emit message(res);
}
