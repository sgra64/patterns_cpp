#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include <iostream>
using namespace std;

class Pizza;
class Hamburger;
class Eatable;

/**
 * @brief The Factory class
 */
class FoodFactory {

  public:
    static FoodFactory& getInstance() { return _singletonFactoryInstance; }
    string getName() { return name; }

    /*
     * Concrete factory methods:
     */
    Pizza& getPizza( string name, int diameter );
    Hamburger& getHamburger( string name, bool vegan, int calories );

    /*
     * Abstract Factory methods:
     */
    Eatable& getEatable( string name );

  private:
    FoodFactory() : FoodFactory( "Factory" ) {}
    FoodFactory( string name ) : name( name ) {}
    ~FoodFactory() {}

    FoodFactory( const FoodFactory& orig );                     //disallow copy constructor
    const FoodFactory &operator = ( const FoodFactory& orig );  //disallow assignment operator

    string name;
    static FoodFactory _singletonFactoryInstance;
};


/**
 * @brief Abstract class Eatable represents eatable items.
 */
class Eatable {
  public:
    string getName() { return name; }
    string getType() { return type; }

    virtual string toJSON() = 0;

  protected:
    Eatable( string name, string type ) : name( name ), type( type ) {}
    virtual ~Eatable();

  private:
    string name;
    string type;
};


class Pizza : public Eatable {
    friend FoodFactory;
  public:
    virtual string toJSON();

  private:
    Pizza( string name ) : Pizza( name, 30 /*default*/ ) {}
    Pizza( string name, int diameter ) : Eatable( name, "Pizza    " ),
        diameter( diameter ) {}

    int diameter;
};


class Hamburger : public Eatable {
    friend FoodFactory;
  public:
    virtual string toJSON();

  private:
    Hamburger( string name ) : Hamburger( name, false, 1200 /*defaults*/ ) {}
    Hamburger( string name, bool vegan, int calories ) : Eatable( name, "Hamburger" ),
        vegan( vegan ), calories( calories ) {}

    bool vegan;
    int calories;
};


#endif // FACTORY_H
