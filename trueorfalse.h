#ifndef TRUEORFALSE_H
#define TRUEORFALSE_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class trueorfalse;
}

class trueorfalse : public QDialog
{
    Q_OBJECT

public:
    explicit trueorfalse(QWidget *parent = nullptr);
    ~trueorfalse();
private slots:
    void on_pushButton_clicked();
    void generateMathQuestion();
    void checkAnswer();


private:
    Ui::trueorfalse *ui;
    QTimer *timer;
    int num1, num2, operation, result, correctAnswers = 0, numQuestions = 0, totalQuestions = 0;
    bool isTrue;
    const char* operators[4] = {"+", "-", "*", "/"};

    QPushButton *trueButton;
    QPushButton *falseButton;

    int calculateResult(int num1, int num2, int operation);
};

#endif // TRUEORFALSE_H
