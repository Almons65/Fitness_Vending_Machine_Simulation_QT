#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secwindow.h"
#include "thiwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(880, 460);
    this->setWindowTitle("Main");
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    secwindow sec;
    sec.setModal(true);
    sec.exec();
}




void MainWindow::on_pushButton_2_clicked()
{
    thiwindow thi;
    thi.setModal(true);
    thi.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

