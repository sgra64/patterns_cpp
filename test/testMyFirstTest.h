#ifndef TESTESTMYFIRSTTEST_H
#define TESTESTMYFIRSTTEST_H

#include <QtTest/QtTest>


/**
 * @brief testMyFirstTest class demonstrates the use of Qt Unit tests.
 * Source: http://doc.qt.io/qt-5/qtest-overview.html
 */
class TestMyFirstTest : public QObject {
    Q_OBJECT

  public:
    TestMyFirstTest();

  private:
    bool myCondition() {
        return true;
    }

  private slots:
    void initTestCase() {
      qDebug( "Called before everything else." );
    }

    void myFirstTest() {
        QVERIFY( true ); // check that a condition is satisfied
        QCOMPARE( 1, 1 ); // compare two values
    }

    void mySecondTest() {
        QVERIFY( myCondition() );
        QVERIFY( 1 != 2 );
    }

    void myFirstFailedTest() {
        //QVERIFY( false );   // fails test
        QVERIFY( 1 != 2 );
    }

    void cleanupTestCase() {
        qDebug( "Called after myFirstTest and mySecondTest." );
    }

};

#endif // TESTESTMYFIRSTTEST_H
