#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();
signals:
    void regPushButton_clicked();
    void closeFormClicked();
    void signIn(QString name, QString pass);
private slots:
    void on_regPushButton_clicked();

    void on_logButtonBox_accepted();

    void on_logButtonBox_rejected();

private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
