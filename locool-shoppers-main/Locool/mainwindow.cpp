#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDebug>
#include "shoppingw.h"
#include "item.hpp"
#include "store.hpp"
#include "databaseabstraction.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix (ASSET_ROOT.path() + QDir::separator() + "locoolpic.png");
    ui->label_pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    shoppingW shop;
    shop.setModal(true);
    shop.exec();
    qDebug() << "User clicked on a button";
}


