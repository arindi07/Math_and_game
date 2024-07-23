#ifndef VXOD_H
#define VXOD_H

#include <QDialog>

namespace Ui {
class vxod;
}

class vxod : public QDialog
{
    Q_OBJECT

public:
    explicit vxod(QWidget *parent = nullptr);
    ~vxod();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::vxod *ui;
};

#endif // VXOD_H
