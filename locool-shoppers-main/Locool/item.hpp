#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include "mainwindow.hpp"

class Item
{
public:
    Item();
    void setItemPrice(QString price);
    void setItemType(QString type);
    QString getItemType();
    QString getPrice();

private:
    QString itemPrice;
    QString itemType;
    friend class shoppingW;
    friend class databaseAbstraction;
    friend class Testing;

};

#endif // ITEM_HPP
