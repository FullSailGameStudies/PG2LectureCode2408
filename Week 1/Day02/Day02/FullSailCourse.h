#pragma once
#include <string>
#include <vector>
class FullSailCourse
{
public:
	std::string GetName();
	void SetName(std::string& name);//passing BY REFERENCE. making an alias. PREVENTS a copy and is more efficient.

	void GetGrades(std::vector<float>& grades);
private:
	std::string name_;
};

