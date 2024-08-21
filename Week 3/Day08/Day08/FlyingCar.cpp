#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //base + derived info
    //return a string with the year, make, model, airspeed, altitude

    //if we DO NOT call the base method, we are FULLY OVERRIDING the base method
    // 
    //calling the base means we are EXTENDING the base method
    //call the base by adding "Car::" to the method call
    std::string baseInfo = Car::vehicleInformation();
    std::string derivedInfo = " Airspeed: " + std::to_string(maxAirspeed_) + " Altitude: " + std::to_string(maxAltitude_);
    return baseInfo + derivedInfo;
}
