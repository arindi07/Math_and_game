#include "glavnoe.h"
#include "ui_glavnoe.h"
#include"avtoriz.h"
#include <QBrush>
#include <QImage>
#include "fastmath.h"
#include "tablymnozh.h"
#include"trueorfalse.h"
#include"interestingmath.h"

three::three(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::three)

{

    ui->setupUi(this);
}

three::~three()
{
    delete ui;
}

void three::on_pushButton_4_clicked()
{
    hide();
    two window;
    window.setModal(true);
    window.exec();
}


void three::on_pushButton_3_clicked()
{
    hide();
    fastmath window;
    window.setModal(true);
    window.exec();
}


void three::on_pushButton_6_clicked()
{
    hide();
    tablymnozh window;
    window.setModal(true);
    window.exec();
}


void three::on_pushButton_2_clicked()
{
    hide();
    trueorfalse window;
    window.setModal(true);
    window.exec();
}


void three::on_pushButton_5_clicked()
{
    hide();
    interestingmath window;
    window.setModal(true);
    window.exec();
}

