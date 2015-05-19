/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QListView *listView;
    QLabel *label;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QStringLiteral("MyDialog"));
        MyDialog->resize(596, 344);
        pushButton = new QPushButton(MyDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 75, 23));
        pushButton_3 = new QPushButton(MyDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 80, 75, 23));
        pushButton_4 = new QPushButton(MyDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 290, 75, 23));
        listView = new QListView(MyDialog);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(260, 10, 301, 241));
        label = new QLabel(MyDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 20, 131, 20));

        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "Goods Effectiveness", 0));
        pushButton->setText(QApplication::translate("MyDialog", "load", 0));
        pushButton_3->setText(QApplication::translate("MyDialog", "Solve", 0));
        pushButton_4->setText(QApplication::translate("MyDialog", "exit", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
