#include "_3fastmath.h"
#include "ui__3fastmath.h"
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "fastmath.h"

using namespace std;

_3fastmath::_3fastmath(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::_3fastmath)
{
    ui->setupUi(this);
    srand(time(nullptr));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(generateMathQuestion()));

    generateMathQuestion();
}

_3fastmath::~_3fastmath()
{
    delete ui;
}

void _3fastmath::generateMathQuestion()
{
    if (numQuestions >= 15) {
        timer->stop();
        ui->questionLabel->setText("Молодец!Конец игры");
        QString result = QString("Правильных ответов: %1 из %2").arg(correctAnswers).arg(totalQuestions);
        ui->feedbackLabel->setText(result);
        return;
    }

    num1 = rand() % 15;
    num2 = rand() % 15;
    operation = rand() % 3;
    result = calculateResult(num1, num2, operation);

    QString question = QString("Решите выражение: %1 %2 %3").arg(num1).arg(operators[operation]).arg(num2);
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

void _3fastmath::checkAnswer()
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

int _3fastmath::calculateResult(int num1, int num2, int operation)
{
    switch (operators[operation]) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    }
    return 0; // Default return if operation is not valid
}




void _3fastmath::on_pushButton_clicked()
{
    hide();
    fastmath window;
    window.setModal(true);
    window.exec();
}

