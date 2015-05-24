#include <QApplication>
#include "mydialog.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDialog *Mainwindow = new MyDialog;
    Mainwindow->show();
    return a.exec();
}
