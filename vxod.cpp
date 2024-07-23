#include "vxod.h"
#include "ui_vxod.h"
#include "two.h"
#include "three.h"

vxod::vxod(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::vxod)
{
    ui->setupUi(this);
}

vxod::~vxod()
{
    delete ui;
}

void vxod::on_pushButton_2_clicked()
{

    two window;
    window.setModal(true);
    window.exec();
}


void vxod::on_pushButton_clicked()
{

    three window;
    window.setModal(true);
    window.exec();
}

