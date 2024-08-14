// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

//name of the method? LinearSearch
//return type? index of the item IF found. int
//parameters? what are we searching in? what are we searching for?
//  how should we pass them? by value or by refence?
//  is the parameter changing in the method? const or no const?

int LinearSearch(const std::vector<int>& searchVector, int searchNumber)
{
    int foundIndex = -1;
    for (int i = 0; i < searchVector.size(); i++)
    {
        if (searchNumber == searchVector[i])
        {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}

int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE 1:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 6;
    int index = LinearSearch(numbers, searchNumber);
    if (index == -1) //not found
        std::cout << searchNumber << " was NOT found.\n";
    else
        std::cout << searchNumber << " was found at index " << index << "\n";


    std::cin.get();



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<std::string, double> menu;
    menu["Falafels"] = 4.99;
    menu["Italian Panini"] = 8.99;
    menu["Chicken Curry"] = 13.99;
    menu["California Roll"] = 15.99;
    menu["California Roll"] = 18.99;//will OVERWRITE an existing value

    //std::pair have 2 parts: first and second
    std::pair<std::string, double> menuItemToInsert("Tortilla Soup", 8.99);
    auto wasInserted = menu.insert(menuItemToInsert); //will NOT overwrite an existing key-value
    if (wasInserted.second != true)
    {
        std::cout << "The item was already in the map. It was NOT inserted.\n";
    }
    else
        std::cout << "The item was inserted.\n";


    //maps are storing pair objects

    std::cout << "\nIterator while Loop:\n";
    auto iterator = menu.begin();
    while (iterator != menu.end())
    {
        //pair: first (key) and second (value)
        std::cout << std::setw(20) << std::left << iterator->first;//key
        std::cout << std::setw(7) << std::right << iterator->second;//value
        std::cout << "\n";

        iterator++;
    }
    std::cout << "\nIterator for Loop:\n";
    for (auto iter = menu.begin(); iter != menu.end(); iter++)
    {
        std::cout << std::setw(20) << std::left << iter->first;//key
        std::cout << std::setw(7) << std::right << iter->second;//value
        std::cout << "\n";
    }

    std::cout << "\nrange-based for Loop:\n";
    for (const auto& [itemName,itemPrice] : menu)
    {
        std::cout << std::setw(20) << std::left << itemName;//key
        std::cout << std::setw(7) << std::right << itemPrice;//value
        std::cout << "\n";
    }

    std::cout << "\n";
    //find a menu item
    //the find(key) method returns an iterator
    // if the iterator == end(), key was NOT found
    // else we found the key
    std::string keyToFind = "California Roll";

    //to update...
    // 1) use the [ ] = newValue
    // 2) change the second value of the iterator
    menu["California Roll"] = 10.99;

    //double price = menu[keyToFind];//if not found, will add the key with a 0 value
    auto menuFindIterator = menu.find(keyToFind);
    if (menuFindIterator == menu.end())
        std::cout << keyToFind << " is not on the menu.\n";
    else //the key was found
    {
        //std::cout << keyToFind << " costs " << menu[keyToFind] << "\n";
        double oldPrice = menuFindIterator->second;
        menuFindIterator->second *= 1.05;
        double newPrice = menu[keyToFind];//to prove that line 159 updated the map
        std::cout << keyToFind << " used to costs " << oldPrice << "\n";
        std::cout << "Now it costs " << newPrice << ". THANKS PUTIN!!!\n";
    }

    std::cin.get();

    /*
        CHALLENGE 2:

            Create a map that stores names (string) and numeric grades. Call the variable grades.
            Add students and grades to your map.

    */
    srand(time(NULL));
    std::vector<std::string> students{ "Austin","Damaris","Franck","Jason","Jeffrey","Keith","Krystal","Orlinda","Travis","Stephan" };
    std::map<std::string, double> grades;
    for (std::string& student : students)
    {
        grades[student] = rand() % 10001 / 100.0;
    }

    /*
        CHALLENGE 3:

            Loop over your grades map and print each student name and grade.

    */
    std::cout << "\nPG2 Grades for 2408:\n";
    for (const auto& [studentName, studentGrade] : grades)
    {
        std::cout << std::setw(10) << std::left << studentName;//key
        std::cout << std::setw(7) << std::right << studentGrade;//value
        std::cout << "\n";
    }

    /*
        CHALLENGE 5:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */
    std::cout << "\n";
    while (true)
    {
        std::cout << "Name of student to find and curve: ";
        std::string nameToFind;
        std::getline(std::cin, nameToFind);
        if (nameToFind.empty()) break;

        auto gradesIterator = grades.find(nameToFind);
        if (gradesIterator == grades.end())
            std::cout << nameToFind << " is not in PG2 this month.\n";
        else
        {
            gradesIterator->second *= 1.10;
            std::cout << nameToFind << " has a grade of " << gradesIterator->second << ".\n";
        }

    }    
    std::cin.get();




    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map







    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }







    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE 6:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}