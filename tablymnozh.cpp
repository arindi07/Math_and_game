#include "tablymnozh.h"
#include "ui_tablymnozh.h"
#include "glavnoe.h"

tablymnozh::tablymnozh(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tablymnozh)
{
    ui->setupUi(this);
}

tablymnozh::~tablymnozh()
{
    delete ui;
}

void tablymnozh::on_pushButton_clicked()
{
    hide();
    three window;
    window.setModal(true);
    window.exec();
}

