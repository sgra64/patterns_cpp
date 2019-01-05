#include "testFactory.h"


TestFactory::TestFactory() :
    foodFactory( FoodFactory::getInstance() ) {}

void TestFactory::initTestCase() {
    qDebug( "Called before everything else." );

    FoodFactory *fp1 = &foodFactory;
    QVERIFY( fp1 != NULL );

    FoodFactory *fp2 = &FoodFactory::getInstance();
    QVERIFY( fp1 == fp2 );     // singleton getInstance always return same address
    QCOMPARE( fp1, fp2 );
}

void TestFactory::pizzaFactoryTest() {
    Pizza& p1 = foodFactory.createPizza( "Margarita", 30 );
    Pizza& p2 = foodFactory.createPizza( "Hawaii", 60 );
    //QCOMPARE( &p1, &p2 );     // must fail
    QVERIFY( &p1 != &p2 );

    QCOMPARE( p1.getName(), "Margarita" );
    QCOMPARE( p1.getDiameter(), 30 );
    QCOMPARE( p1.getType(), "Pizza    " );

    QCOMPARE( p2.getName(), "Hawaii" );
    QCOMPARE( p2.getDiameter(), 60 );
    QCOMPARE( p2.getType(), "Pizza    " );

    //Eatable& e2 = foodFactory.createEatable( "Pizza Four Seasons" );
}

void TestFactory::hamburgerFactoryTest() {
    Hamburger& h1 = foodFactory.createHamburger( "BicMac", false, 1800 );
    Hamburger& h2 = static_cast<Hamburger&>( foodFactory.createEatable( "CheeseBurger" ) );
    QVERIFY( &h1 != &h2 );
}

void TestFactory::hamburgerFactoryCastTest() {
    Hamburger& h3 = dynamic_cast<Hamburger&>( foodFactory.createEatable( "Hamburger Nutella" ) );
    Hamburger& h4 = dynamic_cast<Hamburger&>( foodFactory.createEatable( "Cheese Burger" ) );
    QVERIFY( &h3 != &h4 );

    QVERIFY_EXCEPTION_THROWN(   // must throw std::bad_cast exception.
        dynamic_cast<Hamburger&>( foodFactory.createEatable( "Pizza Nutella" ) ), std::bad_cast
    );

    int i = 0;
    try {
        dynamic_cast<Hamburger&>( foodFactory.createEatable( "Pizza Nutella" ) );
        i = 1;

    } catch( ... ) {
        i = 2;
    }
    QCOMPARE( i, 2 );
}

void TestFactory::cleanupTestCase() {
    //QVERIFY( false );   // fails test
    QVERIFY( true ); // check that a condition is satisfied
    QCOMPARE( 1, 1 ); // compare two values
    qDebug( "Called after myFirstTest and mySecondTest." );
}
