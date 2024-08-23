#pragma once
#include <string>
#include "Vehicle.h"
#include <iostream>


//our base class
class Car : public Vehicle
{
public:
	//Car() : mMake("Ford"), mModel("A"), mModelYear(1908), mFuelLevel(0), mMaxFuelLevel(15)
	//{   }

	Car(int year, std::string make, std::string model)
		: mModelYear(year), mMake(make), mModel(model), mFuelLevel(0), mMaxFuelLevel(15)
	{	
		numberOfCarsMade++;
	}
	virtual std::string vehicleInformation();

	//non-static data member
	//non-static means each instance has its own variable
	//non-static methods can access BOTH non-static AND static members

	//static data member
	//static means each instance SHARES the 1 variable
	static int numberOfCarsMade;

	//static methods do NOT have a 'this' pointer
	//since they do not have 'this', 
	// you can ONLY access static members inside a static method
	static void CarReport()
	{
		std::cout << "Cars made: " << numberOfCarsMade << "\n";
	}

	void refuel()
	{
		mFuelLevel = mMaxFuelLevel;
	}
	void refuel(int fuelToAdd)
	{
		mFuelLevel = std::min(mMaxFuelLevel, mFuelLevel + fuelToAdd);
	}
	void refuel(short fuelToAdd)
	{
		mFuelLevel = std::min(mMaxFuelLevel, mFuelLevel + fuelToAdd);
	}

	//getter (accessor)
	int modelYear() const
	{
		return mModelYear;
	}

	//setter (mutator)
	void modelYear(int newModelYear)
	{
		if (newModelYear > 1908 && newModelYear < 2100)
		{
			mModelYear = newModelYear;
		}
	}

protected:
	int mModelYear;
	std::string mModel;
	std::string mMake;

private:

	int mFuelLevel;
	int mMaxFuelLevel;
};


