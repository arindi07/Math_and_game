#include "three.h"
#include "ui_three.h"
#include"avtoriz.h""
#include <QBrush>
#include <QImage>

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

    two window;
    window.setModal(true);
    window.exec();
}

