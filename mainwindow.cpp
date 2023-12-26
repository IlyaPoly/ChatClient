#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.setInterval(ui->comboBox->currentText().toInt() * 1000);
    timer.setSingleShot(false);
    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotSetTimerTime(int)));
    lgs = new LogRegScreen;
    connect(lgs, SIGNAL(signInSig(QString, QString)), this, SLOT(login(QString, QString)));
    connect(lgs, SIGNAL(reg(QString, QString, QString)), this, SLOT(reg(QString, QString, QString)));
}

void MainWindow::login(QString login, QString pass)
{
    QString mess = "2" + login + " " + pass;
    mySock->write(mess.toLocal8Bit().data(), mess.length());
    mySock->waitForReadyRead(1000);
    timer.start();
}

void MainWindow::reg(QString name, QString login, QString pass)
{
    QString mess ="1" + name + " " + login + " " + pass;
    mySock->write(mess.toLocal8Bit().data(), mess.length());
    mySock->waitForReadyRead(1000);
    this->login(login,pass);
    this->update();
}

void MainWindow::update()
{
    char mess = '4';
    mySock->write(&mess, sizeof(mess));
    mySock->waitForReadyRead(1000);
    mess = '5';
    mySock->write(&mess, sizeof(mess));
    mySock->waitForReadyRead(1000);
}

void MainWindow::slotSetTimerTime(int msec)
{
    timer.setInterval(ui->comboBox->currentText().toInt() * 1000);
}

void MainWindow::readAns()
{
    char c;
    QScrollBar *br = ui->messageTextBrowser->verticalScrollBar();
    mySock->read(message, sizeof(message));
    c = message[0];
    strcpy(message,message+1);
    switch (c)
    {
        case '0':
        {
            QMessageBox::warning(this, tr("Wrong"), message, QMessageBox::Ok);
            if (lgs->isVisible())
                lgs->show();
            break;
        }
        case '1':
        {
            if (lgs->isVisible())
                lgs->close();
            break;
        }
        case '4':
        {
            ui->userTextBrowser->setText(message);
            break;
        }
        case '5':
        {
            ui->messageTextBrowser->setText(message);
            br->setValue(br->maximum());
            break;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    if (mySock != nullptr)
    delete mySock;
}

void MainWindow::on_actionConnect_triggered()
{
    lgs->show();
    ui->actionConnect->setEnabled(false);
    ui->actionDisconnect->setEnabled(true);
    mySock = new QTcpSocket();
    connect(mySock, SIGNAL(readyRead()), this, SLOT(readAns()));
    mySock->connectToHost("localhost", PORT);
    if(!mySock->waitForConnected())
    qDebug() << "Can't connect to host";
    else
    qDebug("Connect!");
}

void MainWindow::on_sendAllPushButton_clicked()
{
    if (ui->actionConnect->isEnabled())
    {
    QMessageBox::warning(this, tr("Wrong"), tr("No connection!"), QMessageBox::Ok);
    return;
    }
    if (ui->messageLineEdit->text() == "")
    {
    QMessageBox::warning(this, tr("Wrong"), tr("You message is empty!"), QMessageBox::Ok);
    return;
    }
    QString mess = "3all " + ui->messageLineEdit->text();
    ui->messageLineEdit->clear();
    qDebug(mess.toStdString().c_str());
    mySock->write(mess.toLocal8Bit().data(), mess.length());
    mySock->waitForReadyRead(1000);
}

void MainWindow::on_actionDisconnect_triggered()
{
    delete mySock;
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    timer.stop();
}

void MainWindow::on_actionExit_triggered()
{
    delete lgs;
    if (mySock)
    delete mySock;
    exit(0);
}

void MainWindow::on_sendLoginPushButton_2_clicked()
{
    QString mess = "3" + ui->loginTolineEdit->text()+ " " + ui->messageLineEdit->text();
    ui->messageLineEdit->clear();
    mySock->write(mess.toLocal8Bit().data(), mess.length());
    mySock->waitForReadyRead(1000);
}


void MainWindow::on_actionOpen_new_windows_triggered()
{
    MainWindow* nw = new MainWindow;
    nw->show();
}

