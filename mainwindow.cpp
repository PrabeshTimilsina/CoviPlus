#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

//void Database::connectDB(QString XXX){
//       db=QSqlDatabase::addDatabase("QMYSQL");
//       db.setHostName("127.0.0.1");      // Connect to the database host name , Here we need to pay attention to （ If it is ”127.0.0.1“, Unable to connect , Is changed to localhost)
//       db.setPort(3306);                 // Connection database port number , Consistent with settings
//       db.setDatabaseName(XXX);      // Connection database name , Consistent with settings
//       db.setUserName("root");          // Database user name , Consistent with settings
//       db.setPassword("password");    // Database password , Consistent with settings
//       qDebug()<<" Start connecting ";
//   }

//  QSqlDatabase Database::getDB() {
//      return db;
//  }

//  bool Database::connectionDB() {
//      db.open();
//      if(!db.open()) {
//          return false;
//      }
//      else {
//           return true;
//      }
//  }


MainWindow::~MainWindow()
{
    delete ui;
}

Database updatehos;
void MainWindow::on_pushButton_update_clicked()
{
    updatehos.connectDB("hospital");

        if(!updatehos.connectionDB()) {
            qDebug()<<" Can't connect "<<"connect to mysql error"<<updatehos.getDB().lastError().text();
            return ;
        }
        else {
             qDebug()<<" Successful connection."<<"Connected to mysql.";
             QString address= ui->address->text();
             QString email= ui->email->text();
             QString phone= ui->phone->text();
             QString fax= ui->fax->text();
             QString Ropen= ui->Ropen->text();
             QString Rclose= ui->Rclose->text();
             QString beds= ui->beds->text();
             QString Ocylinders= ui->Ocylinders->text();
             QString ventilators= ui->ventilators->text();
             QString icu= ui->icu->text();
             QString ambulance= ui->ambulance->text();
             QString website= ui->website->text();

             QSqlQuery qry;

             qry.prepare("update hospitals set address='"+address+"', email='"+email+"', phone='"+phone+"', fax='"+fax+"', registrationOpenTime='"+Ropen+"', registrationCloseTime='"+Rclose+"', numOfBeds='"+beds+"', numOfOxygenCylinders='"+Ocylinders+"', numOfVentilater='"+ventilators+"', numOfICU='"+icu+"', ambulance='"+ambulance+"', website='"+website+"' where id='1'");


             if(qry.exec()){
                  QMessageBox:: information(this, "Updated", "Your data has been updated");

                  this->hide();
             }
             else{
                 QMessageBox:: information(this, "Not updated", "There was a problem with updating.");
             }
        }
}


void MainWindow::on_pushButton_close_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_hospital_clicked()
{

    data = new Data(this);
        data->show();
}


void MainWindow::on_pushButton_patients_clicked()
{
    patients= new Patients(this);
    patients->show();
}

