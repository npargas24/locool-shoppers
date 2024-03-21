#include <QtTest>
#include <QString>
#include "../Locool/mainwindow.hpp"
#include "../Locool/store.hpp"
#include "../Locool/item.hpp"
#include "../Locool/store.cpp"
#include "../Locool/item.cpp"

class Testing : public QObject
{
    Q_OBJECT


private slots:
    void test_case1();
    void test_setItemPrice();
    void test_storeConstructor();
    void test_itemConstructor();
    void test_setItemType();
    void test_setStoreName();
    void test_setStoreType();
};

void Testing::test_storeConstructor()
{
    store storeTest;
    QVERIFY(storeTest.storeName == "default");
}

void Testing::test_itemConstructor()
{
    Item item1;
    QVERIFY(item1.getPrice() == "0");
}

void Testing::test_case1()
{
    QVERIFY(true);
}

void Testing::test_setItemPrice()
{
    Item item1;
    QString test_price = "3.50";
    item1.setItemPrice(test_price);
    QString result = item1.getPrice();
    QCOMPARE(result, test_price);
}

void Testing::test_setItemType(){
    Item item1;
    item1.setItemType("Clothing");
    QCOMPARE(item1.itemType, "Clothing");
}

void Testing::test_setStoreName() {
    store testStore;
    testStore.setStoreName("WooConnect");
    QCOMPARE(testStore.getStoreName(), "WooConnect");
}


void Testing::test_setStoreType() {
    store testStore;
    testStore.setStoreType("Restaurant");
    QCOMPARE(testStore.getStoreType(), "Restaurant");
}


QTEST_APPLESS_MAIN(Testing)

#include "tst_testing.moc"
