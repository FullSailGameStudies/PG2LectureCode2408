#include "FullSailCourse.h"
#include <time.h>
#include <iostream>
#include <iomanip>

std::string FullSailCourse::GetName()
{
	return name_;
}
void FullSailCourse::SetName(std::string& name)//name is a reference to a variable in a different scope
{
	//name is an ALIAS to the courseName variable
	if (!name.empty() && name.size() < 256)
		name_ = name;
}

void FullSailCourse::GetGrades(std::vector<float>& grades)
{
	srand(time(NULL));//seeds the random # generator
	//fill the vector with 10 grades
	for (int i = 0; i < 10; i++)
	{
		//rand() - random # generator. 0 - 32767
		float grade = (rand() % 10001)/100.0f;//limits the # to 0 - 100.00
		grades.push_back(grade);
	}
}

void FullSailCourse::PrintGrades(const std::vector<float>& grades)//const prevents the method from modifying the parameter
{
	std::cout << "\nGrades for " << name_ << "\n"; //" " is a string
	for (int i = 0; i < grades.size(); i++)
	{
		std::cout << std::setw(10) << std::right << grades[i] << '\n'; // ' ' is a char
	}
	//grades.clear();//this MODIFIES the vector
}
