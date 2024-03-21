#ifndef STORE_HPP
#define STORE_HPP
#include <iostream>
#include "mainwindow.hpp"

class store
{
public:
    store();
    void setStoreName(QString name);
    void setStoreType(QString type);
    QString getStoreName();
    QString getStoreType();

private:
    QString storeName;
    QString storeType;
    //friend class shoppingW;
    friend class databaseAbstraction;
    friend class Testing;
};

#endif // STORE_HPP
