#pragma once
#include "Car.h"
class FlyingCar : public Car
{
	//are there any constructors in flyingcar??
	//NO! b/c Car does not have a default, the compiler cannot create a default ctor for flyingcar

public:

	//our derived ctor MUST call a base ctor
	//add the ctor call to the front of the member initialization list
	FlyingCar(int maxAltitude, float maxAirspeed, int yr, std::string mk, std::string mdl)
		: Car(yr, mk, mdl), maxAltitude_(maxAltitude), maxAirspeed_(maxAirspeed)
	{
		//DO NOT duplicate what the base ctor does. that's the base ctor's job!
		//mModelYear = yr;
		//mMake = mk;
		//mModel = mdl;

		//mFuelLevel = 10;//cannot access the private members of Car
	}

	float MaxAirspeed() const { return maxAirspeed_; }
	void MaxAirspeed(float newAirspeed) {
		if (newAirspeed > 0 && newAirspeed < 1000)
			maxAirspeed_ = newAirspeed;
	}

private:
	int maxAltitude_;
	float maxAirspeed_;
};

