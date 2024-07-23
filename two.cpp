#include "two.h"
#include "ui_two.h"
#include <QMessageBox>
#include <QPixmap>
#include "three.h"
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
    QString login = ui ->lineEdit->text();
    QString password = ui -> pass ->text();

    if (login == "Codi" && password == "test"){
       QMessageBox::information(this, "Ура" ,"Регистрация прошла успешно" );
    }
    else {
       QMessageBox::warning(this, "Авторизация" ,"Регистрация прошла не успешно" );

    }
    three window;
    window.setModal(true);
    window.exec();
}

