#ifndef SENSORDATAPROVIDER_H
#define SENSORDATAPROVIDER_H
#include "SensorDataProviderIntf_2.h"
#include <iostream>
#include <set>
using namespace std;


class SensorDataProvider : public SensorDataProviderIntf {
  public:
    static SensorDataProvider& getInstance() {
        return _singleton;
    }

    virtual void setInterval ( long msec ) override;
    virtual SensorData& getData() override;

  private:
    SensorDataProvider() {}
    virtual ~SensorDataProvider() override {}

    SensorDataProvider( const SensorDataProvider& orig ) = delete;   // disable copy constructor
    const SensorDataProvider &operator = ( const SensorDataProvider& orig ) = delete;  //disable assignment '='

    static SensorDataProvider _singleton;   // var declaration

};

#endif // SENSORDATAPROVIDER_H
