#include "trueorfalse.h"
#include "ui_trueorfalse.h"
#include "glavnoe.h"

using namespace std;

trueorfalse::trueorfalse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trueorfalse)
{
    ui->setupUi(this);
    srand(time(nullptr));

    trueButton = new QPushButton("Правда", this);
    falseButton = new QPushButton("Ложь", this);
    ui->verticalLayout->addWidget(trueButton);
    ui->verticalLayout->addWidget(falseButton);
    connect(trueButton, &QPushButton::clicked, this, & trueorfalse::checkAnswer);
    connect(falseButton, &QPushButton::clicked, this, & trueorfalse::checkAnswer);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(generateMathQuestion()));

    generateMathQuestion();
}

trueorfalse::~trueorfalse()
{
    delete ui;
}

void trueorfalse::generateMathQuestion()
{
    if (numQuestions >= 15) {
        timer->stop();
        ui->questionLabel->setText("Молодец! Конец игры");
        QString result = QString("Правильных ответов: %1 из %2").arg(correctAnswers).arg(totalQuestions);
        ui->feedbackLabel->setText(result);
        return;
    }

    num1 = rand() % 15;
    num2 = rand() % 15;
    operation = rand() % 3;
    result = calculateResult(num1, num2, operation);

    isTrue = rand() % 2; // Случайное булевское значение (0 или 1)

    QString question;
    if (isTrue) {
        question = QString("Выражение %1 %2 %3 = %4 верное?").arg(num1).arg(operators[operation]).arg(num2).arg(result);
    } else {
        int wrongResult = result + rand() % 5 - 2; // Неверный результат, отличающийся от правильного на +/-2
        question = QString("Выражение %1 %2 %3 = %4 верное?").arg(num1).arg(operators[operation]).arg(num2).arg(wrongResult);
    }
    ui->questionLabel->setText(question);

    numQuestions++;
    totalQuestions++;
}

void trueorfalse::checkAnswer()
{
    QPushButton *selectedOption = qobject_cast<QPushButton*>(sender());
    if (!selectedOption) {
        return;
    }

    bool userAnswer = (selectedOption == trueButton);
    if (userAnswer == isTrue) {
        ui->feedbackLabel->setText("Правильно! Дальше");
        correctAnswers++;
    } else {
        ui->feedbackLabel->setText("Неправильно");
    }

    generateMathQuestion();

    timer->start(10000); // Timer interval in milliseconds (e.g., 10000 for 10 seconds)
}

int trueorfalse::calculateResult(int num1, int num2, int operation)
{
    const char* op = operators[operation];
    if (*op == '+') {
        return num1 + num2;
    } else if (*op == '-') {
        return num1 - num2;
    } else if (*op == '*') {
        return num1 * num2;
    } else if (*op == '/') {
        if (num2 == 0) {
            return 0; // Обработка деления на ноль
        }
        return num1 / num2;
    }
    return 0; // Default return if operation is not valid
}

void trueorfalse::on_pushButton_clicked()
{
    hide();
    three window;
    window.setModal(true);
    window.exec();
}
