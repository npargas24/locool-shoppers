#include "store.hpp"


store::store()
{
    storeName = "default";
    storeType = "default";
}

void store::setStoreName(QString name) {
    storeName = name;
}

void store::setStoreType(QString type) {
    storeType = type;
}

QString store::getStoreName() {
    return storeName;
}
QString store::getStoreType() {
    return storeType;
}
