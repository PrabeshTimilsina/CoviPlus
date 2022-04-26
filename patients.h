#ifndef PATIENTS_H
#define PATIENTS_H

#include <QDialog>
#include"data.h"

namespace Ui {
class Patients;
}

class Patients : public QDialog
{
    Q_OBJECT

public:
    explicit Patients(QWidget *parent = nullptr);
    ~Patients();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_refresh_clicked();

private:
    Ui::Patients *ui;
};

#endif // PATIENTS_H
