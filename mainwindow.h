#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QtDebug>
#include<QtWidgets>
#include<QObject>
#include"data.h"
#include"patients.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_update_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_hospital_clicked();

    void on_pushButton_patients_clicked();

private:
    Ui::MainWindow *ui;

     Data *data;
     Patients *patients;
};

//class Database
//{
//private:
//    QSqlDatabase db;
//public:
//    void connectDB(QString);
//    QSqlDatabase getDB();
//    bool connectionDB();
//    bool connectionLogin();
//};
#endif // MAINWINDOW_H
