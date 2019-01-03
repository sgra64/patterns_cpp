#ifndef OBSERVER_H
#define OBSERVER_H

#include <set>
#include <iostream>
using namespace std;


/**
 * @brief Instances of the Observer class subscribe to Observables in
 * order to receive notifications by invocing the update() method.
 */
class Observer {
  public:
    Observer( const string name ) : name( name ) {}

    void update();

    const string name;
};


/**
 * @brief Instances of the Observable class distribute notifications
 * to all subscribed Observables by invoking their update() methods
 * in an undefined order.
 */
class Observable {

  public:
    Observable( const string name ) : name( name ) {}

    void addObserver( Observer &observer );
    void removeObserver( Observer &observer );
    void notify();                  // notify all subscribed Observers

    void printObservers();

  private:
    set<Observer*> observers_;      // internal Observer list
    const string name;
};

#endif // OBSERVER_H
