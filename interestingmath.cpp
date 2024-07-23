#include "interestingmath.h"
#include "ui_interestingmath.h"
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "glavnoe.h"

using namespace std;

interestingmath::interestingmath(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interestingmath)
{
    ui->setupUi(this);
    srand(time(nullptr));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(generateMathQuestion()));

    generateMathQuestion();
}

interestingmath::~interestingmath()
{
    delete ui;
}

void interestingmath::generateMathQuestion()
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
    num3 = rand() % 15; // Генерируем третье число
    operation = rand() % 4; // Добавляем деление
    result = calculateResult(num1, num2, num3, operation);

    QString question = QString("Решите выражение: %1 %2 %3 %4 %5").arg(num1).arg(operators[operation]).arg(num2).arg(operators[operation]).arg(num3);
    ui->questionLabel->setText(question);

    QStringList answerOptions;
    answerOptions << QString::number(result);
    for (int i = 0; i < 3; ++i) {
        int randomNum = rand() % 15; // Generate random incorrect options
        answerOptions << QString::number(randomNum);
    }

    random_device rd;
    mt19937 gen(rd());

    std::shuffle(answerOptions.begin(), answerOptions.end(), gen); // Shuffle the answers

    QLayoutItem *item;
    while((item = ui->optionsLayout->layout()->takeAt(0)) != 0)
    {
        item->widget()->setParent(NULL);
        delete item;
    }

    for (int i = 0; i < answerOptions.size(); ++i) {
        QRadioButton *optionButton = new QRadioButton(answerOptions.at(i), this);
        ui->optionsLayout->addWidget(optionButton);
        connect(optionButton, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    }

    numQuestions++;
    totalQuestions++;
}

void interestingmath::checkAnswer()
{
    QRadioButton *selectedOption = qobject_cast<QRadioButton*>(sender());
    if (!selectedOption) {
        return;
    }

    int userAnswer = selectedOption->text().toInt();
    if (userAnswer == result) {
        ui->feedbackLabel->setText("Правильно! Дальше");
        correctAnswers++;
    } else {
        ui->feedbackLabel->setText("Неправильно");
    }

    // Clear previous options
    QLayoutItem *item;
    while ((item = ui->optionsLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    generateMathQuestion();

    timer->start(10000); // Timer interval in milliseconds (e.g., 10000 for 10 seconds)
}

int interestingmath::calculateResult(int num1, int num2, int num3, int operation)
{
    const char* op = operators[operation];
    int result1 = 0;

    // Вычисляем результат для первых двух чисел
    if (*op == '+') {
        result1 = num1 + num2;
    } else if (*op == '-') {
        result1 = num1 - num2;
    } else if (*op == '*') {
        result1 = num1 * num2;
    } else if (*op == '/') {
        if (num2 != 0) {
            result1 = num1 / num2;
        }
    }

    int result2 = 0;

    // Вычисляем окончательный результат с использованием третьего числа
    if (*op == '+') {
        result2 = result1 + num3;
    } else if (*op == '-') {
        result2 = result1 - num3;
    } else if (*op == '*') {
        result2 = result1 * num3;
    } else if (*op == '/') {
        if (num3 != 0) {
            result2 = result1 / num3;
        }
    }

    return result2;
}

void interestingmath::on_pushButton_clicked()
{
    hide();
    three window;
    window.setModal(true);
    window.exec();
}
