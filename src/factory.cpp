#include "Factory.h"


Eatable::~Eatable() {}

FoodFactory FoodFactory::_singletonFactoryInstance;

Pizza& FoodFactory::getPizza( string name, int diameter ) {
    return *new Pizza( name, diameter );
}

Hamburger& FoodFactory::getHamburger( string name, bool vegan, int calories ) {
    return *new Hamburger( name, vegan, calories );
}

Eatable& FoodFactory::getEatable( string name ) {
    if( name.find( "izza" ) != string::npos ) {
        return *new Pizza( name );
    }
    if( name.find( "urger" ) != string::npos ) {
        return *new Hamburger( name );
    }
    return *new Hamburger( "SomeDefaultBurger." );
}

string Pizza::toJSON() {
    string res = "{ ";
    res += "type: \"" + getType() + "\"";
    res += ", name: \"" + getName() + "\"";
    res += ", diameter: " + to_string( diameter ) + "";
    return res + " }";
}

string Hamburger::toJSON() {
    string res = "{ ";
    res += "type: \"" + getType() + "\"";
    res += ", name: \"" + getName() + "\"";
    res += ", vegan: " + to_string( vegan );
    res += ", calories: " + to_string( calories );
    return res + " }";
}
