#include "Singleton.h"


Singleton::Singleton( string name ) : name( name ) {
    cout << "Constructor: " << this->name << "(" << this << ")" << endl;
}

Singleton::~Singleton() {
    cout << "Destructor: " << name << "(" << this << ")" << endl;
}

/*
 * Variation(A): static creation program start BEFORE entering main();
 * destructor is called AFTER leaving main().
 */
//Singleton Singleton::_singletonInstance;
//Singleton *Singleton::ptr = nullptr;      // used for Variation(C)


Singleton& Singleton::getInstance() {
    /*
     * Variation(B): lazy creation on first invocation of getInstance()
     * AFTER entering main(); destructor is called AFTER leaving main().
     */
    static Singleton _singletonInstance;

    /*
     * Variation(C): lazy creation on the heap with new(); destructor is
     * NOT called and must explicitly be invoked with delete BEFORE
     * leaving main().
     */
    //if( ptr==nullptr ) {
    //    ptr = new Singleton();
    //}

    cout << "getInstance() --> (" << &_singletonInstance << ")" << endl;
    return _singletonInstance;
    //return *ptr;      // used for Variation(C)
}

string Singleton::getName() {
    return name;
}
