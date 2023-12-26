#include <QTcpSocket>
#include <QApplication>
#include "mainwindow.h"

#define PORT 30000
#define MESSAGE_LENGTH 1024

int  main(int argc, char* argv[])
{
    QTcpSocket s;
    s.connectToHost("localhost", PORT);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
