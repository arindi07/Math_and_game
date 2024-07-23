#include "start.h"
#include <QApplication>
#include <QDebug>
#include "avtoriz.h"
#include "glavnoe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/img/teacher.png"));
    Widget w;
    w.show();
    return a.exec();
}

