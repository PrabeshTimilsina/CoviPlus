#include "patients.h"
#include "ui_patients.h"

Patients::Patients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Patients)
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

Patients::~Patients()
{
    delete ui;
}

void Patients::on_pushButton_back_clicked()
{
    this->hide();
}

Database viewpatients;
void Patients::on_pushButton_refresh_clicked()
{
    viewpatients.connectDB("hospital");
   QSqlQueryModel *model=new QSqlQueryModel();
   viewpatients.connectionDB();


   QSqlQuery *qry=new QSqlQuery(viewpatients.db);
   qry->prepare("select * from appointments");
   qry->exec();
   model->setQuery(*qry);
   ui->tableView->setModel(model);
   qDebug()<<(model->rowCount());
}

