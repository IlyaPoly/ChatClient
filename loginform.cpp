#include "loginform.h"
#include "ui_loginform.h"
#include <QMessageBox>

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_regPushButton_clicked()
{
    emit regPushButton_clicked();
}


void LoginForm::on_logButtonBox_accepted()
{
    if (ui->loginLogLineEdit->text() != "" && ui->passLogLineEdit->text() != "")
    emit signIn(ui->loginLogLineEdit->text(), ui->passLogLineEdit->text());
    else
    QMessageBox::warning(this, tr("Wrong"), tr("Wrong data!"), QMessageBox::Ok);
}


void LoginForm::on_logButtonBox_rejected()
{
    emit closeFormClicked();
}

