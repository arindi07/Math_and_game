#ifndef _4FASTMATH_H
#define _4FASTMATH_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class _4fastmath;
}

class _4fastmath : public QDialog
{
    Q_OBJECT

public:
    explicit _4fastmath(QWidget *parent = nullptr);
    ~_4fastmath();
private:
    QTimer *timer = new QTimer(this);
    int numQuestions = 0;
    int correctAnswers = 0; // New variable to track correct answers
    int totalQuestions = 0;
private slots:
    void generateMathQuestion();
    void checkAnswer();
    void on_pushButton_clicked();

private:
    int calculateResult(int num1, int num2, int operation);
    Ui::_4fastmath *ui;
    int num1, num2, operation, result;
    char operators[4] = { '+', '-', '*', '/' };
};

#endif // _4FASTMATH_H
