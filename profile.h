#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>

namespace Ui {
class Profile;
}

class Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    ~Profile();

    void setUserInfo(const QString& name, const QString& login, const QString& email, const QDate& registrationDate);

private slots:
    void on_deleteAccountButton_clicked();
    void on_logoutButton_clicked();
    void showEvent(QShowEvent*);

private:
    Ui::Profile *ui;
    QString m_userName;
    QString m_userLogin;
};

#endif // PROFILE_H
