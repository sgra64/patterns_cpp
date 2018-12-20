#include <iostream>
#include "Singleton.h"
#include "Factory.h"
using namespace std;

extern void singletonPlayground();
extern void factoryPlayground();

int main( int /*argc*/, char* /*argv*/[] ) {
    cout << "------------------" << " Hello Patterns!" << "----------" << endl;
    singletonPlayground();
    //factoryPlayground();

    cout << "------------------" << " Leaving main(), bye." << "-----" << endl;
}


void singletonPlayground() {
    Singleton& singleton = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    singleton.getName();
    s2.getName();

    // the following are not allowed:
    //Singleton& s3 = *new Singleton();
    //Singleton s4;

    // destructor needs to be called for Variation(C)
    //delete &singleton;
}


void factoryPlayground() {
    FoodFactory& foodFactory = FoodFactory::getInstance();
    //Pizza *p0 = new Pizza( "Margarita", 30 );   // not allowed

    Pizza& p1 = foodFactory.getPizza( "Margarita", 30 );
    Pizza& p2 = foodFactory.getPizza( "Hawaii", 60 );
    Hamburger& h1 = foodFactory.getHamburger( "BicMac", false, 1800 );

    Eatable& e1 = foodFactory.getHamburger( "Whopper", false, 1300 );
    Eatable& e2 = foodFactory.getEatable( "Pizza Four Seasons" );
    Eatable& e3 = foodFactory.getEatable( "CheeseBurger" );
    Hamburger& h2 = (Hamburger&)foodFactory.getEatable( "CheeseBurger" );
    Hamburger& h3 = static_cast<Hamburger&>( foodFactory.getEatable( "Pizza Nutella" ) );
    Hamburger& h4 = dynamic_cast<Hamburger&>( foodFactory.getEatable( "Hamburger Nutella" ) );
    //Hamburger& h5 = dynamic_cast<Hamburger&>( foodFactory.getEatable( "Pizza Nutella" ) );
    cout << endl;
    cout << "p1: " << p1.toJSON() << endl;
    cout << "p2: " << p2.toJSON() << endl;
    cout << "h1: " << h1.toJSON() << endl;
    cout << "e1: " << e1.toJSON() << endl;
    cout << "e2: " << e2.toJSON() << endl;
    cout << "e3: " << e3.toJSON() << endl;
    cout << "h2: " << h2.toJSON() << endl;
    cout << "h3: " << h3.toJSON() << endl;
    cout << "h4: " << h4.toJSON() << endl << endl;
}
