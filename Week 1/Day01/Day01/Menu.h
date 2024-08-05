#pragma once
#include <vector>
#include <string>

class Menu
{
public:
	//a DECLARATION
	//what is the name?
	//does it return data?
	//does it need data passed to it?
	void AddMenuItem(std::string itemToAdd, float price);//NO CODE!
	void ShowMenu();
	float FindPrice(std::string itemToFind);
	bool RemoveMenuItem(std::string itemToRemove);

private:
	std::vector<std::string> menuItems;
	std::vector<float> prices;
};

