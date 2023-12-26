#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QWidget>

namespace Ui {
class RegisterForm;
}

class RegisterForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();

signals:
    void loginPushButton_clicked();
    void closeFormClicked();
    void reg(QString name, QString login, QString pass);
private slots:
    void on_loginPushButton_clicked();

    void on_regButtonBox_accepted();

    void on_regButtonBox_rejected();

private:
    Ui::RegisterForm *ui;
};

#endif // REGISTERFORM_H
