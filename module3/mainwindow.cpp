#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui-> tableWidget -> setEditTriggers(QAbstractItemView::NoEditTriggers);

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_add_clicked()
{


    Password.push_back(ui-> passWord -> text());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(ui ->name->text())) ;
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(ui ->phonenum->text())) ;
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(ui ->email->text())) ;
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(ui ->address->text())) ;
    ui ->name->setText("");
    ui ->phonenum->setText("");
    ui ->email->setText("");
    ui ->address->setText("");
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui -> passWord -> setText("");

    /*for(auto i : Password)
           qDebug() << i;*/
}


void MainWindow::on_remove_clicked()
{

    int a = (ui ->whichindex->text()).toInt();

    if(ui-> passWord -> text() == Password.at(a - 1)){
        ui-> tableWidget->removeRow(a-1);
        ui ->name->setText("");
        ui ->phonenum->setText("");
        ui ->email->setText("");
        ui ->address->setText("");
        Password.removeAt(a-1);
        QMessageBox::information(this,"Alles gut","Removed well");
    }
    else{
        QMessageBox::critical(this,"Warning","Wrong password");
    }
    ui -> passWord -> setText("");


}


void MainWindow::on_edit_clicked()
{

    int a = (ui ->whichindex->text()).toInt();

    if(ui-> passWord -> text() == Password.at(a - 1)){
        ui->tableWidget->setItem(a-1,0,new QTableWidgetItem(ui ->name->text())) ;
        ui->tableWidget->setItem(a-1,1,new QTableWidgetItem(ui ->phonenum->text())) ;
        ui->tableWidget->setItem(a-1,2,new QTableWidgetItem(ui ->email->text())) ;
        ui->tableWidget->setItem(a-1,3,new QTableWidgetItem(ui ->address->text())) ;
        ui ->name->setText("");
        ui ->phonenum->setText("");
        ui ->email->setText("");
        ui ->address->setText("");
        QMessageBox::information(this,"Alles gut","Edited well");
    }
    else{
        QMessageBox::critical(this,"Warning","Wrong password");
    }
    ui -> passWord -> setText("");


}




void MainWindow::on_find_clicked()
{

    int a = (ui ->whichindex->text()).toInt();
    ui ->name->setText((ui->tableWidget->item(a-1,0))->text());
    ui ->phonenum->setText((ui->tableWidget->item(a-1,1))->text());
    ui ->email->setText((ui->tableWidget->item(a-1,2))->text());
    ui ->address->setText((ui->tableWidget->item(a-1,3))->text());
}
