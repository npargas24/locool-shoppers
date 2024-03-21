#ifndef SHOPPINGW_H
#define SHOPPINGW_H

#include <QDialog>
#include "mainwindow.hpp"
#include "databaseabstraction.hpp"

namespace Ui {
class shoppingW;
}

class shoppingW : public QDialog
{
    Q_OBJECT

public:
    MainWindow conn;
    explicit shoppingW(QWidget *parent = nullptr);
    ~shoppingW();
    QSqlDatabase pdb;
    databaseAbstraction dbs;

private slots:
    void on_pushButton_addItem_clicked();

    void on_pushButton_addStore_clicked();

    void on_pushButton_UpdateItem_clicked();

    void on_pushbutton_UpdateStore_clicked();

    void on_pushButton_ViewItems_clicked();

    void on_pushButton_ViewStores_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::shoppingW *ui;
};

#endif // SHOPPINGW_H
