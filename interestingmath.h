#ifndef INTERESTINGMATH_H
#define INTERESTINGMATH_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class interestingmath;
}

class interestingmath : public QDialog
{
    Q_OBJECT

public:
    explicit interestingmath(QWidget *parent = nullptr);
    ~interestingmath();
private slots:
    void generateMathQuestion();
    void checkAnswer();
    void on_pushButton_clicked();

private:
    Ui::interestingmath *ui;
    QTimer *timer;
    int num1, num2, num3; // Добавляем третье число
    int operation;
    int result;
    int correctAnswers = 0;
    int totalQuestions = 0;
    int numQuestions = 0;
    const char* operators[4] = {"+", "-", "*", "/"}; // Добавляем деление

    int calculateResult(int num1, int num2, int num3, int operation);
};

#endif // INTERESTINGMATH_H
