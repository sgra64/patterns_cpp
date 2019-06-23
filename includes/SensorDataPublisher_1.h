#ifndef SENSORDATAPUBLISHER_H
#define SENSORDATAPUBLISHER_H
#include "PublisherIntf.h"
#include <iostream>
#include <map>
#include <set>
using namespace std;


class SensorDataPublisher : public PublisherIntf {

  public:
    SensorDataPublisher( const string name ) : name( name ) {}

    void subscribe( SubscriberIntf& subscriber, const string topic ) override;
    void unsubscribe( SubscriberIntf& subscr, const string topic ) override;

    void publish( const string topic, const string msg ) override;
    string getName() override { return name; }

    void shutdown() {
        if( opSt==NORMAL ) {
            opSt = COOLOFF;
        }
    }

  private:
    map<string, set<SubscriberIntf *>> subscribers_;
    const string name;
    enum { OFF, AUTOTEST, WARMUP, NORMAL, COOLOFF } opSt;
};


class SensorDataReceiver : public SubscriberIntf {

  public:
    SensorDataReceiver( const string name ) : name( name ) {}

    void notify( PublisherIntf &source, const string topic, const string msg ) override;

    string getName() override { return name; }

  private:
    const string name;
};

#endif // SENSORDATAPUBLISHER_H
