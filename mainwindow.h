#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <QComboBox>
#include "logregscreen.h"
#define PORT 30000
#define MESSAGE_LENGTH 1024

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void login(QString login, QString pass);
    void reg(QString name, QString login, QString pass);
    void on_actionConnect_triggered();
    void update();
    void slotSetTimerTime(int msec);
    void readAns();

    void on_sendAllPushButton_clicked();

    void on_actionDisconnect_triggered();

    void on_actionExit_triggered();

    void on_sendLoginPushButton_2_clicked();

    void on_actionOpen_new_windows_triggered();

private:
    Ui::MainWindow *ui;
    QTcpSocket* mySock = nullptr;
    QTimer timer;
    LogRegScreen* lgs;
    char message[MESSAGE_LENGTH]{};

};
#endif // MAINWINDOW_H
