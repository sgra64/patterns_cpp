#include <QtTest>
#include "testMyFirstTest.h"
#include "testQString.h"
#include "testFactory.h"

#define T_MYFIRSTTEST   0x01
#define T_QSTRINGTEST   0x02
#define T_FACTORYTEST   0x04


int main( int argc, char **argv ) {

    const int testSuite = 0
        | T_MYFIRSTTEST
        | T_QSTRINGTEST
        | T_FACTORYTEST
    ;
    int status = 0;

   /*
    * This example shows how to run test cases within one executable rather than as
    * separate executables using the QTEST_MAIN( TestQString ) macro.
    * Source:
    *   https://stackoverflow.com/questions/46367557/using-qexec-to-create-qt-test-suite
    */
    if( testSuite & T_MYFIRSTTEST ) {
        TestMyFirstTest tc;
        status |= QTest::qExec( &tc, argc, argv );
    }

    if( testSuite & T_QSTRINGTEST ) {
        TestQString tc;
        status |= QTest::qExec( &tc, argc, argv );
    }

    if( testSuite & T_FACTORYTEST ) {
        TestFactory tc;
        status |= QTest::qExec( &tc, argc, argv );
    }

   return status;
}
