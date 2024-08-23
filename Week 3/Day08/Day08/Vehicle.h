#pragma once
#include <string>

class Vehicle
{
public:
	//a pure virtual function to make this class an ABSTRACT class
	virtual std::string vehicleInformation() = 0;//make it pure virtual
};

