#ifndef GLAVNOE_H
#define GLAVNOE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>

struct User {
    QString login;
    QString name;
};

class MySQLiteDB {
public:
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    User user;

    MySQLiteDB() {
        db.setDatabaseName("C:\\Users\\arina\\OneDrive\\Documents\\kyrs\\kyr.db");

        if (!db.open())
        {
            qDebug() << "Ошибка подключения к базе данных:" << db.lastError().text();
        } else {
            qDebug() << "open";
        }
    }
};

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

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::three *ui;
};

#endif // GLAVNOE_H
