#include "Menu.h"
#include <iostream>
#include <iomanip>

//a DEFINITION (the code for the methods)
//always add the class scoping to the method name
//	EXAMPLE: "Menu::"
void Menu::AddMenuItem(std::string itemToAdd, float price)
{
	menuItems.push_back(itemToAdd);
	prices.push_back(price);
}
void Menu::ShowMenu()
{
	//std::cout << menuItems << "\n";
	std::cout << "---for loop---\n";
	//first index: 0
	//last index: size()-1
	for (int i = 0; i < menuItems.size(); i++)
	{
		std::string menuItem = menuItems[i];//use [index] to access the item at that spot
		float price = prices[i];
		std::cout << std::setw(15) << std::left << menuItem << std::setw(7) << std::right << price << "\n";
	}

	std::cout << "---range-based for loop---\n";
	//& - creates a reference variable. PREVENTS a copy of each string
	int index = 0;
	for (std::string& menuItem : menuItems)
	{
		float price = prices[index++];
		std::cout << menuItem << "\t" << price << "\n";
	}

	std::cout << "---iterator for loop---\n";
	//vector.begin() - gives us an ITERATOR to the first item
	//vector.end() - gives us an ITERATOR to the item AFTER the last one????????
	std::vector<float>::iterator priceIterator = prices.begin();

	for (std::vector<std::string>::iterator iter = menuItems.begin(); iter != menuItems.end() ; iter++)
	{
		std::string menuItem = *iter;
		float price = *priceIterator;
		std::cout << menuItem << "\t" << price << "\n";

		priceIterator++;
	}
}

float Menu::FindPrice(std::string itemToFind)
{
	float price = -1;
	for (int i = 0; i < menuItems.size(); i++)
	{
		//_stricmp - C way to compare strings
		//	needs 2 C strings passed to it
		//	use c_str() to get the C string of each std::string
		//  returns < 0 (less than), == 0 (EQual to), > 0 (Greater than)
		// int result = _stricmp(string1.c_str(), string2.c_str())
		//if (itemToFind == menuItems[i])// == is case SENSITIVE
		int result = _stricmp(itemToFind.c_str(), menuItems[i].c_str());//case INSENSITIVE
		if(result == 0)
		{
			price = prices[i];
			break;
		}
	}
	return price;
}

bool Menu::RemoveMenuItem(std::string itemToRemove)
{
	bool wasRemoved = false;
	for (int i = 0; i < menuItems.size(); i++)
	{
		int result = _stricmp(itemToRemove.c_str(), menuItems[i].c_str());//case INSENSITIVE
		if (result == 0)
		{
			//1) remove the item from the vector. use the vector.erase(iterator)
			auto iterator = menuItems.begin() + i;//move to the iterator to the item at the i index
			menuItems.erase(iterator);

			auto pIterator = prices.begin() + i;
			prices.erase(pIterator);
			
			//2) set wasRemoved to true
			wasRemoved = true;

			//3) break out of the loop
			break;
		}
	}
	return wasRemoved;
}
