#include "SensorDataProvider_2.h"


SensorDataProvider SensorDataProvider::_singleton;  // instance definition.

SensorDataProviderIntf::~SensorDataProviderIntf() { }

void SensorDataProvider::setInterval ( long msec ) {

}

SensorData& SensorDataProvider::getData() {
    SensorData *sd = new SensorData();
    sd->temp_water_inflow = 0.0;
    sd->temp_water_outflow = 0.0;
    sd->water_flow_rate = 0.0;
    return *sd;
}
