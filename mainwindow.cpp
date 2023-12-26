#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNetworkList(QStringList networkInterfaces)
{
    ui->comboBox->addItems(networkInterfaces);
}


void MainWindow::on_pushButton_clicked()
{
    emit resetNetworkWithIndex(ui->comboBox->currentIndex());
}

