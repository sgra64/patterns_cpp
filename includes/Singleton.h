#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>
#include <iostream>
using namespace std;

/**
 * @brief The Singleton pattern ensures that a class has only
 * one instance and provides a global point of access to that
 * instance. It is named after the singleton set, which is
 * defined to be a set containing one element. This is useful
 * when exactly one object is needed to coordinate actions
 * across the system.
 *
 * Check list
 *  - define a private static attribute in the "single instance" class.
 *  - define a public static accessor getInstance()-function as only way
 *    to access the instance.
 *  - define all constructors to be protected or private.
 *  - define a lifecycle
 *      - creation:
 *          - static (creation at program start)
 *          - "lazy" (creation on first call by getInstance function).
 *      - initialization:
 *          - use explicit start() method
 *      - destruction:
 *          - use stop method
 *          - invoke destructor.
 *
 */
class Singleton {

  public:
    static Singleton& getInstance();
    string getName();

  private:
    Singleton() : Singleton( "Singleton" ) {}
    Singleton( string name );
    ~Singleton();

    /*
     * Note that the next two functions are not given bodies, thus any attempt
     * to call them implicitly will return as compiler errors. This prevents
     * accidental copying of the only instance of the class.
     */
    Singleton( const Singleton& orig );                     //disallow copy constructor
    const Singleton &operator = ( const Singleton& orig );  //disallow assignment operator

    string name;
    static Singleton _singletonInstance;
    //static Singleton *ptr;        // used for Variation(C)
};

#endif // SINGLETON_H
