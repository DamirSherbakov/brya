#ifndef CALCSOCKDECORATOR_H
# define CALCSOCKDECORATOR_H
# include "../common/socketdecorator.h"

class CalcSockDecorator : public SocketDecorator {
  Q_OBJECT
public:
  explicit CalcSockDecorator(ISocketAdapter *sock, QObject *parent = 0);
  virtual void sendString(const QString& str);
protected slots:
  virtual void on_send_request(QString);
  virtual void on_message(QString);
  void on_result(QString);
    //!< вычислено выражение
};

#endif // CALCSOCKDECORATOR_H
