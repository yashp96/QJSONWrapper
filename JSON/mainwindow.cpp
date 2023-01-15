#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myjson.setJSONFileName("data.json");
    myjson.readJSON(&jsonMap);

    int c =jsonMap.count();

    foreach(QString k, jsonMap.keys())
    {       
       ui->jsonList->insertRow(0);
       ui->jsonList->setItem(0,0, new QTableWidgetItem);
       ui->jsonList->setItem(0,1, new QTableWidgetItem);
       ui->jsonList->setItem(0,2, new QTableWidgetItem);
       ui->jsonList->item(0,0)->setText(QString().sprintf("%d",c));
       ui->jsonList->item(0,1)->setText(k);
       ui->jsonList->item(0,2)->setText(jsonMap[k].toString());
       c--;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    jsonMap["name"] = ui->jsonList->item(0,2)->text();
    jsonMap["location"] = ui->jsonList->item(1,2)->text();
    jsonMap["age"] = ui->jsonList->item(2,2)->text();

    myjson.writeJSON(jsonMap);
}

