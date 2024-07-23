#include "fastmath.h"
#include "ui_fastmath.h"
#include "glavnoe.h"
#include "_2fastmath.h"
#include"_3fastmath.h"
#include"_4fastmath.h"

fastmath::fastmath(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fastmath)
{
    ui->setupUi(this);
}

fastmath::~fastmath()
{
    delete ui;
}

void fastmath::on_pushButton_4_clicked()
{
    hide();
    three window;
    window.setModal(true);
    window.exec();
}


void fastmath::on_pushButton_clicked()
{
    hide();
    _2fastmath window;
    window.setModal(true);
    window.exec();
}


void fastmath::on_pushButton_3_clicked()
{
    hide();
    _3fastmath window;
    window.setModal(true);
    window.exec();
}


void fastmath::on_pushButton_2_clicked()
{
    hide();
    _4fastmath window;
    window.setModal(true);
    window.exec();
}

