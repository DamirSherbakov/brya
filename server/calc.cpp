#include "calc.h"
#include <QScriptEngine>

Calc::Calc(QString expr, QObject *parent) : QObject(parent), m_expr(expr) {
}

void Calc::run() {
  QScriptEngine engine;
  QString res = m_expr + " = " + engine.evaluate(m_expr).toString();
  if (engine.hasUncaughtException())
    emit result("");
  else
    emit result(res);
}
