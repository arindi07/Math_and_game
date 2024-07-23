#ifndef XOD_H
#define XOD_H

#include <QDialog>

namespace Ui {
class xod;
}

class xod : public QDialog
{
    Q_OBJECT

public:
    explicit xod(QWidget *parent = nullptr);
    ~xod();

private slots:
    void on_pushButton_2_clicked();


    void on_loginButton_clicked();

private:
    Ui::xod *ui;
};

#endif // XOD_H
