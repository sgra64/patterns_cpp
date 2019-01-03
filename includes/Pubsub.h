#ifndef PUBSUB_H
#define PUBSUB_H

#include "PublisherIntf.h"
#include <map>
#include <set>
#include <iostream>
using namespace std;


class NewsPublisher : public PublisherIntf {
  public:
    NewsPublisher( const string name ) : name( name ) {}

    void subscribe( SubscriberIntf& subscriber, const string topic ) override;
    void unsubscribe( SubscriberIntf& subscriber, const string topic = "" ) override;

    void publish( const string topic, const string msg ) override;

    string getName() override { return name; }

  private:
    const string name;
    map< string, set< SubscriberIntf *> > subscribers_;
};


class NewsReader : public SubscriberIntf {
  public:
    NewsReader( const string name ) : name( name ) {}

    void notify( PublisherIntf &source, const string topic, const string msg ) override;

    string getName() override { return name; }

  private:
    const string name;
};


#endif // PUBSUB_H
