#include "avtoriz.h"
#include "ui_avtoriz.h"
#include <QMessageBox>
#include "glavnoe.h"
#include "xod.h"
#include <QSqlQuery>
#include "profile.h"

two::two(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::two)
{
    ui->setupUi(this);


}

two::~two()
{
    delete ui;
}

void two::on_pushButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString login = ui->loginLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    QSqlQuery query;
    QString q = (new QString("INSERT INTO users (Name, Login, Password) VALUES ('%1', '%2', '%3')"))->arg(name).arg(login).arg(password);

    qDebug() << q;

    if (query.exec(q))
    {
        QMessageBox::information(this, "Регистрация", "Регистрация прошла успешно!");
        db.user = { login, name };
        // Profile* profile = new Profile;
        // profile->show();
        // this->hide();
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось зарегистрировать пользователя.");
    }

    hide();
    three window;
    window.setModal(true);
    window.exec();
}


void two::on_pushButton_2_clicked()
{
    hide();
    xod window;
    window.setModal(true);
    window.exec();
}




