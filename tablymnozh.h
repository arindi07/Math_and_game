#ifndef TABLYMNOZH_H
#define TABLYMNOZH_H

#include <QDialog>

namespace Ui {
class tablymnozh;
}

class tablymnozh : public QDialog
{
    Q_OBJECT

public:
    explicit tablymnozh(QWidget *parent = nullptr);
    ~tablymnozh();

private slots:
    void on_pushButton_clicked();



private:
    Ui::tablymnozh *ui;

};

#endif // TABLYMNOZH_H
