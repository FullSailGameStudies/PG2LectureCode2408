#include "Car.h"
#include <sstream>

void Car::deserialize(std::string& csvData, char delimiter)
{
	std::stringstream carStream(csvData);
	std::string data;
	std::getline(carStream, data, delimiter);
	mModelYear = std::stoi(data);
	std::getline(carStream, mMake, delimiter);
	std::getline(carStream, mModel, delimiter);
}

void Car::serialize(std::ofstream& outputFile, char delimiter)
{
	//write out the fields to the file separated by the delimiter
	//does NOT open the file. it assumes it is already open.
	outputFile << mModelYear << delimiter <<
		mMake << delimiter << mModel;
}

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}