#include <iostream>
#include "Singleton.h"
#include "Factory.h"
#include "Observer.h"
#include "Pubsub.h"
using namespace std;

extern void singletonPlayground();
extern void factoryPlayground();
extern void observerPlayground();
extern void pubsubPlayground();


int main( int /*argc*/, char* /*argv*/[] ) {
    cout << "------------------" << " Hello Patterns!" << "----------" << endl;
    //singletonPlayground();
    //factoryPlayground();
    //observerPlayground();
    pubsubPlayground();

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

    Pizza& p1 = foodFactory.createPizza( "Margarita", 30 );
    Pizza& p2 = foodFactory.createPizza( "Hawaii", 60 );
    Hamburger& h1 = foodFactory.createHamburger( "BicMac", false, 1800 );

    Eatable& e1 = foodFactory.createHamburger( "Whopper", false, 1300 );
    Eatable& e2 = foodFactory.createEatable( "Pizza Four Seasons" );
    Eatable& e3 = foodFactory.createEatable( "CheeseBurger" );
    Hamburger& h2 = (Hamburger&)foodFactory.createEatable( "CheeseBurger" );
    Hamburger& h3 = static_cast<Hamburger&>( foodFactory.createEatable( "Pizza Nutella" ) );
    Hamburger& h4 = dynamic_cast<Hamburger&>( foodFactory.createEatable( "Hamburger Nutella" ) );
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


static Observable oble1( "Observable_1" );
static Observer obA( "Obs_A" );
static Observer obB( "Obs_B" );
static Observer obC( "Obs_C" );

void observerPlayground() {
    cout << endl;
    //oble1.addObserver( obA );
    //oble1.addObserver( obA );   // repeated insert (ignored)
    //oble1.addObserver( obB );
    //oble1.removeObserver( obA );
    //oble1.removeObserver( obB );
    //oble1.removeObserver( obB );    // repeated remove (ignored)
    //oble1.removeObserver( obC );    // remove element that has not been added before (ignored)

    //oble1.addObserver( obA );
    //oble1.addObserver( obC );
    //oble1.addObserver( obB );
    oble1.printObservers();

    //oble1.notify();

    cout << endl;
}

static NewsPublisher sportsNews( "SportsNews" );
static NewsPublisher stockTicker( "StockTicker" );
static NewsReader joe( "Joe" );
static NewsReader moritz( "Moritz" );
static NewsReader ines( "Ines" );
static NewsReader marc( "Marc" );

static const string T_Bundesliga = "Bundesliga";
static const string T_HerthaNews = "HerthaNews";
static const string T_UnionNews = "UnionNews";
static const string T_AppleCrash = "AppleCrash";
static const string T_BitcoinCrash = "BitcoinCrash";

void pubsubPlayground() {
    sportsNews.subscribe( joe, T_Bundesliga );
    sportsNews.subscribe( joe, T_HerthaNews );
    sportsNews.subscribe( joe, T_UnionNews );
    sportsNews.subscribe( moritz, T_HerthaNews );
    stockTicker.subscribe( moritz, T_BitcoinCrash );
    stockTicker.subscribe( marc, T_BitcoinCrash );
    stockTicker.subscribe( moritz, T_AppleCrash );

    sportsNews.publish( T_Bundesliga, "Hertha auf Platz 8 der Bundesliga." );
    sportsNews.publish( T_HerthaNews, "Hertha auf Platz 8 der Bundesliga." );

    //stockTicker.unsubscribe( moritz, T_AppleCrash );
    stockTicker.unsubscribe( moritz );

    stockTicker.publish( T_AppleCrash, "AAPL: 142.86" );
    stockTicker.publish( T_BitcoinCrash, "BTCUSD: 3932" );

    // https://www.dfb.de/bundesliga/spieltagtabelle
    // https://www.dfb.de/2-bundesliga/spieltagtabelle
    // https://www.bundesliga.at/de/tabelle
    // https://www.tradingview.com/symbols/NASDAQ-AAPL
    // https://www.tradingview.com/symbols/BTCUSD
}
