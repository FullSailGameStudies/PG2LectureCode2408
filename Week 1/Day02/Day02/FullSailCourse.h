#pragma once
#include <string>
#include <vector>
class FullSailCourse
{
public:
	std::string GetName() const;
	void SetName(const std::string& name);//passing BY REFERENCE. making an alias. PREVENTS a copy and is more efficient.

	void GetGrades(std::vector<float>& grades) const;
	void PrintGrades(const std::vector<float>& grades) const;//pass by ref to prevent a copy
private:
	std::string name_;
};

