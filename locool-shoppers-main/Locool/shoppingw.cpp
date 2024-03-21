#include "shoppingw.h"
#include "ui_shoppingw.h"
#include "item.hpp"
#include "store.hpp"
#include "mainwindow.hpp"
#include <QMessageBox>
#include "databaseabstraction.hpp"

shoppingW::shoppingW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shoppingW)
{
    ui->setupUi(this);
    dbs.connOpen(ASSET_ROOT.path() + QDir::separator() + "locoolDatabase.db");

}

shoppingW::~shoppingW()
{
    delete ui;
}


void shoppingW::on_pushButton_addItem_clicked()
{
    QString itemType, itemPrice;
    Item item1;
    itemType=ui->itemTypeEdit->text();
    itemPrice=ui->itemPriceEdit->text();
    item1.setItemType(itemType);
    item1.setItemPrice(itemPrice);
    dbs.insertItem(item1);
}


void shoppingW::on_pushButton_addStore_clicked()
{
    QString storeName, storeType;
    store s;
    storeName=ui->storeNameEdit->text();
    storeType=ui->storeTypeEdit->text();
    s.setStoreName(storeName);
    s.setStoreType(storeType);
    dbs.insertStore(s);

}




void shoppingW::on_pushButton_UpdateItem_clicked()
{

    QString itemType, itemPrice;
    Item item1;
    itemType=ui->itemTypeEdit->text();
    itemPrice=ui->itemPriceEdit->text();
    item1.setItemType(itemType);
    item1.setItemPrice(itemPrice);
    dbs.UpdateItem(item1);

}


void shoppingW::on_pushbutton_UpdateStore_clicked()
{
    QString storeName, storeType;
    store s;
    storeName=ui->storeNameEdit->text();
    storeType=ui->storeTypeEdit->text();
    s.setStoreName(storeName);
    s.setStoreType(storeType);
    dbs.UpdateStore(s);

}


void shoppingW::on_pushButton_ViewItems_clicked()
{
    dbs.viewItems();
    QSqlQueryModel * model1;
    model1 = dbs.viewItems();
    ui->tableView->setModel(model1);
}


void shoppingW::on_pushButton_ViewStores_clicked()
{
    QSqlQueryModel * model1;
    model1 = dbs.viewStores();
    ui->tableView->setModel(model1);
}


void shoppingW::on_pushButton_back_clicked()
{
    close();
}



