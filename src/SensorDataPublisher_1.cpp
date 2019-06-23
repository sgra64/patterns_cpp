#include "SensorDataPublisher_1.h"


void SensorDataPublisher::subscribe( SubscriberIntf& subscr, const string topic ) {
    if( ! topic.empty() ) {
        subscribers_[ topic ].insert( &subscr );
    }
}

void SensorDataPublisher::unsubscribe( SubscriberIntf& subscr, const string topic ) {
    if( ! topic.empty() ) {
        subscribers_[ topic ].erase( &subscr );
    }
}

void SensorDataPublisher::publish( const string topic, string msg ) {
    if( ! topic.empty() ) {
        for( auto *s : subscribers_[ topic ] ) {
            s->notify( *this, topic, msg );
        }
    }
}

void SensorDataReceiver::notify( PublisherIntf &source, const string topic, const string msg ) {
    cout << "\"" << this->getName() << "\" received from \"" << source.getName()
         << "\" on topic: \"" << topic << "\" value: \"" << msg << "\"" << endl;
}

void sensorDataPublisherPlayground() {
    cout << "====> sensorDataPublisherPlayground(); started." << endl;

    SensorDataPublisher *p1 = new SensorDataPublisher( "sensor_1" );
    SensorDataReceiver r1( "r1" );
    SensorDataReceiver r2( "r2" );

    p1->subscribe( r1, "air-temp" );
    p1->subscribe( r2, "air-temp" );
    p1->subscribe( r2, "air-temp" );
    p1->subscribe( r1, "water-temp" );
    p1->subscribe( r2, "water-temp" );

    p1->publish( "air-temp", "20.8C" );
    p1->publish( "air-temp", "22.4C" );
    p1->publish( "water-temp", "2.4C" );
    p1->publish( "XXX-temp", "22.4C" );
}
