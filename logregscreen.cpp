#include "logregscreen.h"
#include "ui_logregscreen.h"
LogRegScreen::LogRegScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogRegScreen)
{
    ui->setupUi(this);
    connect(ui->page, SIGNAL(loginPushButton_clicked()), this, SLOT(setSecondPage()));
    connect(ui->page_2, SIGNAL(regPushButton_clicked()), this, SLOT(setFirstPage()));
    connect(ui->page_2, SIGNAL(closeFormClicked()), this, SLOT(closeForm()));
    connect(ui->page, SIGNAL(closeFormClicked()), this, SLOT(closeForm()));
    connect(ui->page_2, SIGNAL(signIn(QString, QString)), this, SLOT(slotSignIn(QString, QString)));
    connect(ui->page, SIGNAL(reg(QString, QString, QString)), this, SLOT(slotreg(QString,QString,QString)));
}

LogRegScreen::~LogRegScreen()
{
    delete ui;
}

void LogRegScreen::setFirstPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void LogRegScreen::setSecondPage()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void LogRegScreen::closeForm()
{
    this->close();
}

void LogRegScreen::slotSignIn(QString name, QString pass)
{
    emit signInSig(name,pass);
}

void LogRegScreen::slotreg(QString name, QString login, QString pass)
{
    emit reg(name, login, pass);
}
