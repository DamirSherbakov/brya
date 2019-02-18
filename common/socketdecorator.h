#ifndef SOCKETDECORATOR_H
# define SOCKETDECORATOR_H
# include "isocketadapter.h"

class SocketDecorator : public ISocketAdapter {
  Q_OBJECT
public:
  explicit SocketDecorator(ISocketAdapter *sock, QObject *parent = 0);
  virtual ~SocketDecorator();
  virtual void sendString(const QString& str) = 0;
    //!< отправка сообщения через сокет
protected slots:
  void on_disconnected();
    //!< соединение разорвано (пришел сигнал от m_pSock)
  virtual void on_send_request(QString) = 0;
    //!< слот для отправки данных через сокет
  virtual void on_message(QString) = 0;
    //!< слот обработки сообщений, поступивших в сокет
protected:
  ISocketAdapter *m_pSock;
};

#endif // SOCKETDECORATOR_H
