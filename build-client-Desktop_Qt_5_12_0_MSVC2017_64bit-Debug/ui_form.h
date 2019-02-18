/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTextEdit *messages;
    QPushButton *send;
    QLineEdit *message;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(240, 288);
        messages = new QTextEdit(Form);
        messages->setObjectName(QString::fromUtf8("messages"));
        messages->setGeometry(QRect(10, 10, 221, 231));
        messages->setReadOnly(true);
        send = new QPushButton(Form);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(180, 250, 51, 31));
        message = new QLineEdit(Form);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(10, 250, 161, 31));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        send->setText(QApplication::translate("Form", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
