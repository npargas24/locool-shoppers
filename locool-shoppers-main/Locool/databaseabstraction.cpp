#include "databaseabstraction.hpp"
#include <QMessageBox>

databaseAbstraction::databaseAbstraction()
{

}

bool databaseAbstraction::connOpen(QString filepath) {
    //make a sqlite database mydb
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(filepath);

    if(!mydb.open()) {
        qDebug()<<("Database not open");
        return false;
    }
    else {
        qDebug() << "Default";
        qDebug()<< ("Connected! connopen");
        return true;
    }
}

void databaseAbstraction::insertItem(Item itemObject) {

    if(!mydb.isOpen()) {
        qDebug()<<"Database not open";
    }

    QSqlQuery qry;

    QString itemType = itemObject.itemType;
    QString itemPrice = itemObject.itemPrice;

    qry.prepare("insert into locoolItems(Type, Price) values ('"+itemType+"', '"+itemPrice+"')");

    if(qry.exec()) {
        qDebug() << "saved";
    }
    else {
        qDebug() << "Error! no connection to insert";
    }
}


void databaseAbstraction::UpdateItem(Item itemObject) {
    if(!mydb.isOpen()) {
        qDebug()<<"Database not open";
    }

    QSqlQuery qry;
    QString itemType = itemObject.itemType;
    QString itemPrice = itemObject.itemPrice;


    qry.prepare("Update locoolItems set Type='"+itemType+"', Price='"+itemPrice+"'where Type='"+itemType+"'");

    if(qry.exec()) {
        qDebug() << "saved";
    }
    else {
        qDebug() << "Error!! No connection to table";
    }
}


void databaseAbstraction::insertStore(store storeObject) {
    if(!mydb.isOpen()) {
        qDebug()<<"Database not open";
    }

    QSqlQuery qry;
    QString storeName1 = storeObject.storeName;
    QString storeType1 = storeObject.storeType;

    qry.prepare("insert into locool_Stores(Name, TypeofStore) values ('"+storeName1+"', '"+storeType1+"')");

    if(qry.exec()) {
        qDebug() << "saved";
    }
    else {
        qDebug() << "Error! no connection to insert";
    }
}

QSqlQueryModel* databaseAbstraction::viewItems() {
    if(!mydb.isOpen()) {
        qDebug()<<"VIEWITEMS: Database not open";
    }

    QSqlQueryModel * nodal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(this->mydb);
    qry->prepare("select * from locoolItems");
    qry->exec();
    nodal->setQuery(*qry);

    return nodal;
}

QSqlQueryModel* databaseAbstraction::viewStores() {
    if(!mydb.isOpen()) {
        qDebug()<<"VIEWSTORES: Database not open";
    }

    QSqlQueryModel * nodal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(this->mydb);
    qry->prepare("select * from locool_Stores");
    qry->exec();
    nodal->setQuery(*qry);

    return nodal;
}

void databaseAbstraction::UpdateStore(store storeObject) {
    if(!mydb.isOpen()) {
        qDebug()<<"Database not open";
    }

    QSqlQuery qry;
    QString storeName = storeObject.storeName;
    QString storeType = storeObject.storeType;


    qry.prepare("Update locool_Stores set Name='"+storeName+"', TypeofStore='"+storeType+"'where Name='"+storeName+"'");
    qry.exec();
    if(qry.exec()) {
        qDebug() << "saved";
    }
    else {
        qDebug() << "Error!! No connection to table";
    }
}


void databaseAbstraction::connClose(){
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}
