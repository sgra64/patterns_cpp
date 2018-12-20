#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include <iostream>
using namespace std;

class Pizza;
class Hamburger;
class Eatable;

/**
 * @brief The FoodFactory class implements the Factory Design Pattern, which
 * is useful for the creation of many different types of objects, all derived
 * from a common base type.
 * The Factory Method defines a method for creating the objects, which subclasses
 * can then override to specify the derived type that will be created. Thus, at
 * run time, the Factory Method can be passed a description of a desired object
 * (e.g., a string read from user input) and return a base class pointer to a new
 * instance of that object. The pattern works best when a well-designed interface
 * is used for the base class, so there is no need to cast the returned object.
 */
class FoodFactory {

  public:
    static FoodFactory& getInstance() { return _singletonFactoryInstance; }
    string getName() { return name; }

    /*
     * Concrete factory methods:
     */
    Pizza& createPizza( string name, int diameter );
    Hamburger& createHamburger( string name, bool vegan, int calories );

    /*
     * Abstract Factory methods:
     */
    Eatable& createEatable( string name );

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
