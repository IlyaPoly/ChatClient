#ifndef LOGREGSCREEN_H
#define LOGREGSCREEN_H

#include <QDialog>

namespace Ui {
class LogRegScreen;
}

class LogRegScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LogRegScreen(QWidget *parent = nullptr);
    ~LogRegScreen();
signals:
    void okRegClicked();
    void signInSig(QString name, QString pass);
    void reg(QString name, QString login, QString pass);
private slots:
    void setFirstPage();
    void setSecondPage();
    void closeForm();
    void slotSignIn(QString name, QString pass);
    void slotreg(QString name, QString login, QString pass);
private:
    Ui::LogRegScreen *ui;
};

#endif // LOGREGSCREEN_H
