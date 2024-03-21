#ifndef DATABASEABSTRACTION_HPP
#define DATABASEABSTRACTION_HPP

#include <QtSql>
#include <item.hpp>
#include <store.hpp>
#include <mainwindow.hpp>

class databaseAbstraction
{
public:
    QSqlDatabase mydb;
    databaseAbstraction();

    void insertItem(Item itemObject);
    void insertStore(store storeObject);
    void UpdateItem(Item itemObject);
    void UpdateStore(store storeObject);

    QSqlQueryModel* viewItems();
    QSqlQueryModel* viewStores();

    bool connOpen(QString databasePath);
    void connClose();


};

#endif // DATABASEABSTRACTION_HPP
