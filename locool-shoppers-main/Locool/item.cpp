#include "item.hpp"

Item::Item()
{
    itemPrice = "0";
    itemType = "default item";
}


void Item::setItemPrice(QString price) {
    itemPrice = price;
}
void Item::setItemType(QString type) {
    itemType = type;
}

QString Item::getItemType() {
    return itemType;
}

QString Item::getPrice() {
    return itemPrice;
}
