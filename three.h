#ifndef THREE_H
#define THREE_H

#include <QDialog>

namespace Ui {
class three;
}

class three : public QDialog
{
    Q_OBJECT

public:
    explicit three(QWidget *parent = nullptr);
    ~three();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::three *ui;
};

#endif // THREE_H
