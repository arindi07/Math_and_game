#include "profile.h"
#include "ui_profile.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include "glavnoe.h"
#include "avtoriz.h"

Profile::Profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
}

Profile::~Profile()
{
    delete ui;
}

void Profile::setUserInfo(const QString& name, const QString& login, const QString& email, const QDate& registrationDate)
{
    m_userName = name;
    m_userLogin = login;

    ui->nameLabel->setText(m_userName);
    ui->loginLabel->setText(m_userLogin);
}

void Profile::on_deleteAccountButton_clicked()
{
    // Логика для удаления аккаунта пользователя
}

void Profile::on_logoutButton_clicked()
{
    // Логика для выхода из профиля пользователя
}

void Profile::showEvent(QShowEvent* event) {
    Q_UNUSED(event);
    //QObject* object = parent();
    //two* avtoriz = qobject_cast<two*>(object);
    //ui->lbName->setText(avtoriz->db.user.name);
}
