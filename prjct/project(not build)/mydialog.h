#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


private:
    Ui::MyDialog *ui;
    QString Nametoload;
    QString Nametosave;
};

#endif // MYDIALOG_H
