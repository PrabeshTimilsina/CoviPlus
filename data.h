#ifndef DATA_H
#define DATA_H

#include <QDialog>
#include <QMainWindow>
#include <QLineEdit>
#include <QLinearGradient>
#include <QFont>
#include<QtSql>
#include<QSqlDatabase>


namespace Ui {
class Data;
}

class Data : public QDialog
{
    Q_OBJECT

public:
    explicit Data(QWidget *parent = nullptr);
    ~Data();

private slots:
    void on_pushButton_refresh_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::Data *ui;

};

class Database
{
private:

public:
     QSqlDatabase db;
    void connectDB(QString);
    QSqlDatabase getDB();
    bool connectionDB();
    bool connectionLogin();
};

#endif // DATA_H
