// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items


    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));


    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

        Lecture Code: serialize the vector of Cars to a file.
            Data Format:
                separates cars. EX: car1|car2|car3
                separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

    */
    Car myRide(2025, "Tesla", "X-Plane");
    //save this car to a file
    //we want the Car class to save (or serialize) its data to a file
    //1. OPEN the file
    std::string filePath = "car.csv";
    std::ofstream outputFile(filePath);//WHERE will it create the file?
    //in the working directory of the app
    // MOST OF THE TIME, the debugger will change where this goes
    //check if it is open
    if (outputFile.is_open())
    {
        //2. call SERIALIZE on the object
        myRide.serialize(outputFile, '*');
    }
    else
    {
        std::cout << filePath << " could not be opened.\n";
    }
    //3. CLOSE the file
    outputFile.close();


    std::cout << "\nMonday's Ride\n";
    //myRide.serialize(std::cout, '\t');


    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

        Lecture Code:
            Open the file
            Read in each line
            split each line to get each car
            split each car to get the car details

    */

    //1. OPEN the file
    std::ifstream inputFile(filePath);
    if (inputFile.is_open())
    {
        //2. READ the line
        std::string line;
        std::getline(inputFile, line);

        //create a Car using the line
        Car todaysRide(line, '*');

        std::cout << "\nToday's Ride\n";
        std::cout << todaysRide.ModelYear() 
            << " " << todaysRide.Make() 
            << " " << todaysRide.Model() << "\n";
    }
    else
    {
        std::cout << filePath << " could not be opened.\n";
    }
    //3. CLOSE the file
    inputFile.close();
}