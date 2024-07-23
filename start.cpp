#include "start.h"
#include "ui_start.h"
#include "avtoriz.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    hide();
    two window;
    window.setModal(true);
    window.exec();
}

