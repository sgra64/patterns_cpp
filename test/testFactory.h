#ifndef TESTESTFACTORY_H
#define TESTESTFACTORY_H

#include <QtTest/QtTest>
#include "Factory.h"


class TestFactory : public QObject {
    Q_OBJECT

  public:
    TestFactory();

  private:
    FoodFactory& foodFactory;

  private slots:

    void initTestCase();

    void pizzaFactoryTest();

    void hamburgerFactoryTest();

    void hamburgerFactoryCastTest();

    void cleanupTestCase();

};

#endif // TESTESTFACTORY_H
