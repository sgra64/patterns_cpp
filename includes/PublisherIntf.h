#ifndef PUBLISHERINTF_H
#define PUBLISHERINTF_H

#include <iostream>
using namespace std;
class SubscriberIntf;


class PublisherIntf {

  public:
    virtual ~PublisherIntf();

    virtual void subscribe( SubscriberIntf& subscriber, const string topic ) = 0;
    virtual void unsubscribe( SubscriberIntf& subscriber, const string topic = "" ) = 0;

    virtual void publish( const string topic, const string msg ) = 0;

    virtual string getName() = 0;
};


class SubscriberIntf {

  public:
    virtual ~SubscriberIntf();

    virtual void notify( PublisherIntf &source, const string topic, const string msg ) = 0;

    virtual string getName() = 0;
};

#endif // PUBLISHERINTF_H
