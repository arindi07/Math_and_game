#ifndef FASTMATH_H
#define FASTMATH_H

#include <QDialog>

namespace Ui {
class fastmath;
}

class fastmath : public QDialog
{
    Q_OBJECT

public:
    explicit fastmath(QWidget *parent = nullptr);
    ~fastmath();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::fastmath *ui;
};

#endif // FASTMATH_H
