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
    QLabel *label_2;
    QLabel *label_3;
    QListView *listView_3;
    QListView *listView_2;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QStringLiteral("MyDialog"));
        MyDialog->resize(726, 478);
        pushButton = new QPushButton(MyDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 75, 23));
        pushButton_3 = new QPushButton(MyDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 0, 75, 23));
        pushButton_4 = new QPushButton(MyDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 0, 75, 23));
        pushButton_4->setMouseTracking(false);
        listView = new QListView(MyDialog);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 440, 711, 31));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setResizeMode(QListView::Adjust);
        label = new QLabel(MyDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(590, 450, 121, 20));
        label_2 = new QLabel(MyDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 30, 51, 31));
        label_3 = new QLabel(MyDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(440, 30, 221, 31));
        label_3->setMouseTracking(true);
        listView_3 = new QListView(MyDialog);
        listView_3->setObjectName(QStringLiteral("listView_3"));
        listView_3->setGeometry(QRect(370, 70, 301, 341));
        listView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_3->setResizeMode(QListView::Adjust);
        listView_2 = new QListView(MyDialog);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setGeometry(QRect(20, 70, 301, 341));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listView_2->sizePolicy().hasHeightForWidth());
        listView_2->setSizePolicy(sizePolicy);
        listView_2->setMaximumSize(QSize(301, 341));
        listView_2->setLayoutDirection(Qt::LeftToRight);
        listView_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        listView_2->setAutoScroll(false);
        listView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_2->setDragEnabled(false);
        listView_2->setDragDropOverwriteMode(false);
        listView_2->setDragDropMode(QAbstractItemView::NoDragDrop);
        listView_2->setMovement(QListView::Static);
        listView_2->setFlow(QListView::TopToBottom);
        listView_2->setProperty("isWrapping", QVariant(false));
        listView_2->setResizeMode(QListView::Fixed);
        listView_2->setLayoutMode(QListView::Batched);
        listView_2->setViewMode(QListView::ListMode);
        listView_2->setBatchSize(5);
        listView_2->setWordWrap(false);
        listView_2->setSelectionRectVisible(false);

        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "Goods Effectiveness", 0));
        pushButton->setText(QApplication::translate("MyDialog", "load", 0));
        pushButton_3->setText(QApplication::translate("MyDialog", "Solve", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("MyDialog", "saves last result", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButton_4->setText(QApplication::translate("MyDialog", "save result", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("MyDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Input</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MyDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Last Sucessful Output</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
