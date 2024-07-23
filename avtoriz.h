#ifndef AVTORIZ_H
#define AVTORIZ_H

#include <QDialog>
#include "glavnoe.h"

namespace Ui {
class two;
}

class two : public QDialog
{
    Q_OBJECT

public:
    explicit two(QWidget *parent = nullptr);
    ~two();
    MySQLiteDB db = MySQLiteDB();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();




private:
    Ui::two *ui;
};

#endif // AVTORIZ_H
