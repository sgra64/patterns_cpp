#ifndef TESTQSTRING_H
#define TESTQSTRING_H

#include <QtTest/QtTest>


class TestQString : public QObject {
    Q_OBJECT

  private slots:
    void testToUpper() {
        QString str = "Hello";
        QVERIFY( str.toUpper() == "HELLO" );
    }

    void testToLower() {
        QString str = "Hello";
        QVERIFY( str.toLower() == "hello" );
    }

};

#endif // TESTQSTRING_H
