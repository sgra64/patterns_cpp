#include "PublisherIntf.h"
#include "Pubsub.h"


PublisherIntf::~PublisherIntf() {}

SubscriberIntf::~SubscriberIntf() {}

void NewsPublisher::subscribe( SubscriberIntf& subscriber, const string topic ) {
    cout << subscriber.getName() << " SUBSCRIBED on '" << name << "' to [" << topic << "]" << endl;
    subscribers_[ topic ].insert( &subscriber );
}

void NewsPublisher::unsubscribe( SubscriberIntf& subscriber, const string topic ) {
    if( ! topic.empty() ) {
        subscribers_[ topic ].erase( &subscriber );
        cout << subscriber.getName() << " UNSUBSCRIBED on '" << name << "' from [" << topic << "]" << endl;
    } else {
        for( const auto &kvPair : subscribers_ ) {      // iterate through all topics in map
            //(static_cast<set< SubscriberIntf *>>(kvPair.second)).erase( &subscriber );
            unsubscribe( subscriber, kvPair.first );    // unsubscribe from any topic
        }
    }
}

void NewsPublisher::publish( const string topic, const string msg ) {
    for( auto *s : subscribers_[ topic ] ) {
        s->notify( *this, topic, msg );
    }
}

void NewsReader::notify( PublisherIntf &source, const string topic, const string msg ) {
    cout << name << " received from '" << source.getName()
         << "' on topic[" << topic << "]: \"" << msg << "\"." << endl;
}
