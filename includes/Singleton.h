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
     * The following two functions prevent accidental copying of the
     * singleton instance of the class, disabling the copy constructor and
     * the assignment operator '='.
     */
    Singleton( const Singleton& orig ) = delete;   // disable copy constructor
    const Singleton &operator = ( const Singleton& orig ) = delete;  //disable assignment '='

    string name;
    static Singleton _singletonInstance;
    //static Singleton *ptr;        // used for Variation(C)
};

#endif // SINGLETON_H
