#include "xod.h"
#include "ui_xod.h"
#include "avtoriz.h"
#include "glavnoe.h"
#include <QSqlQuery>
#include <QMessageBox>


xod::xod(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::xod)
{
    ui->setupUi(this);
}

xod::~xod()
{
    delete ui;
}

void xod::on_pushButton_2_clicked()
{
    hide ();
    two window;
    window.setModal(true);
    window.exec();
}

void xod::on_loginButton_clicked()
{
    QString login = ui->loginLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT Name, Login FROM users WHERE Login = :login AND Password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if (query.exec() && query.next())
    {
        // Пользователь найден, авторизация успешна
        QString name = query.value("Name").toString();
        QString userLogin = query.value("Login").toString();

        // Закрываем окно авторизации
        this->close();
        hide ();
        three window;
        window.setModal(true);
        window.exec();
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Неверный логин или пароль.");
    }


}

