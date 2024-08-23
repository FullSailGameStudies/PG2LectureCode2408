#include "Car.h"


int Car::numberOfCarsMade = 0;

//non-static methods have a "hidden" parameter
std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}
