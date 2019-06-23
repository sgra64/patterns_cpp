#ifndef SENSORDATAPROVIDERINTF_H
#define SENSORDATAPROVIDERINTF_H


struct SensorData {
    double temp_water_inflow;
    double temp_water_outflow;
    double water_flow_rate;
};

class SensorDataProviderIntf {

  public:
    virtual ~SensorDataProviderIntf();

    virtual void setInterval( long msec ) = 0;
    virtual SensorData& getData() = 0;

};

#endif // SENSORDATAPROVIDERINTF_H
