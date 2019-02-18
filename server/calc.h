#ifndef CALC_H
# define CALC_H

# include <QObject>
# include <QRunnable>

class Calc : public QObject, public QRunnable {
  Q_OBJECT
public:
  explicit Calc(QString expr, QObject *parent = 0);
  void run();
signals:
 void result(QString);
protected:
 QString m_expr;
};

#endif // CALC_H
