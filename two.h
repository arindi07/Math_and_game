#ifndef TWO_H
#define TWO_H

#include <QDialog>

namespace Ui {
class two;
}

class two : public QDialog
{
    Q_OBJECT

public:
    explicit two(QWidget *parent = nullptr);
    ~two();

private slots:
    void on_pushButton_clicked();

private:
    Ui::two *ui;
};

#endif // TWO_H
