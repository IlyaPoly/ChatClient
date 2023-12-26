#include "registerform.h"
#include "ui_registerform.h"
#include <QMessageBox>

RegisterForm::RegisterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
}

RegisterForm::~RegisterForm()
{
    delete ui;
}

void RegisterForm::on_loginPushButton_clicked()
{
    emit loginPushButton_clicked();
}


void RegisterForm::on_regButtonBox_accepted()
{
    if (ui->passRegLineEdit->text() == ui->confrimPassLineEdit->text() && ui->loginRegLineEdit->text() != "")
        emit reg(ui->nameRegLineEdit->text(), ui->loginRegLineEdit->text(), ui->passRegLineEdit->text());
    else if (ui->passRegLineEdit->text() != ui->confrimPassLineEdit->text())
    QMessageBox::warning(this, tr("Wrong"), tr("Password confirmation error!"), QMessageBox::Ok);
    else
    QMessageBox::warning(this, tr("Wrong"), tr("Login cannot be empty"), QMessageBox::Ok);
}


void RegisterForm::on_regButtonBox_rejected()
{
    emit closeFormClicked();
}

