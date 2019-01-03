#include "Observer.h"


void Observer::update() {
    cout << "Observer: " << name << ".update() called." << endl;
}


void Observable::addObserver( Observer &observer ) {
    observers_.insert( &observer );
}

void Observable::removeObserver( Observer &observer ) {
    observers_.erase( &observer );
}

void Observable::notify() {
    for( auto *ob : observers_ ) {
        ob->update();
    }
}

void Observable::printObservers() {
    cout << name << ": [";
    string sep = "";
    for( auto *ob : observers_ ) {
        cout << sep << ob->name;
        sep = ", ";
    }
    cout << "]" << endl;
}
