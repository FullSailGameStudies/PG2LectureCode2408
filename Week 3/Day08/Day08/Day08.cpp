// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "FlyingCar.h"
#include <vector>


//static variables never get removed from memory while the app is running

void PrintMe()
{
	static int i = 0;//only creates i once when it is first called
	//section of memory for static objects
	std::cout << i << " ";
	i++;
}
int main()
{
	for (int i = 0; i < 10; i++)
		PrintMe();

	std::cin.get();

	//Vehicle myCurrentRide;//cannot create an instance of an Abstract class
	std::vector<Vehicle> myGarage;

	int year = 1988;
	std::string make = "Ford", model = "Mustang GT 5.0";
	Car mustangGT(year, make, model);
	mustangGT.refuel();//compile-time polymorphism
	mustangGT.refuel(5);//compile-time polymorphism
	int altitude = 1000;
	float speed = 150;
	FlyingCar DeLorean(altitude, speed, 1985, "DeLorean", "DMC-15");//when we create a flyingcar, we have to also create the Car parts

	std::cout << mustangGT.vehicleInformation() << "\n";
	std::cout << DeLorean.vehicleInformation() << "\n";
	Car::CarReport();


	//STACK objects
	Car myCar(2024, "Tesla", "Cybertruck");//car is on the stack
	Car& todaysRide = myCar;//todaysRide is the SAME OBJECT as myCar.
	Car* pCar = &myCar;//pCar points to myCar. the SAME object

	//HEAP objects.  (dynamic memory)
	//  use the 'new' keyword
	//	heap memory needs to be cleaned up
	//	for every 'new', we need to call 'delete' on the object when it's no longer needed
	Car* heapCar = new Car(2024, "Tesla", "Cybertruck");

	//use the ->  (pointer notation) to access the members
	heapCar->refuel();

	Car* currentCar = heapCar;//copy the POINTER (memory address). points to the same car as heapCar
	delete heapCar;//clean up the memory. release the memory to be used for something else
	heapCar = nullptr;//so we don't accidentally try to use the memory
	if (heapCar != nullptr)
	{//check if nullptr before trying to use
	}

	//use unique_ptr<type> to create and manage the dynamic memory for us
	// unique_ptrs are possessive -- they won't allow another variable to point to the same object
	// std::make_unique<type>(ctor parameters here)
	//		type is what class you want to create
	//		parameters are what the class' constructor needs
	//std::unique_ptr<Car>  instead of Car*
	//std::make_unique<Car>(2024, "Tesla", "Cybertruck")  instead of new Car(2024, "Tesla", "Cybertruck")

	//STEP 1: create the unique_ptr
	std::unique_ptr<Car> uptrCar = std::make_unique<Car>(1992, "Hummer", "H-1");
	uptrCar->refuel();
	//std::unique_ptr<Car> myHummer = uptrCar;

	//STEP 2: add the unique_ptrs to a vector
	std::vector<Car> GsGarage;//will only store Car objects
	std::vector<std::unique_ptr<Car>> jaysGarage;
	jaysGarage.push_back(std::move(uptrCar));//move reassigns ownership of the unique_ptr


	//will UPCAST the FlyingCar * to a Car *.
	//NO information from the flyingcar is lost
	jaysGarage.push_back(std::make_unique<FlyingCar>(altitude, speed, 1985, "DeLorean", "DMC-15"));

	//whenever unique_ptrs variables go out of scope, the ptr is deleted

	std::cout << "\n\nJay's Garage\n";
	for (std::unique_ptr<Car>& garageCar : jaysGarage)
	{
		//the method that is called is dependent on the object
		//if the object was created as a Car, then the Car's method
		//if the object was created as a FlyingCar, then the FlyingCar's method
		//happens at RUNTIME
		//	there is a slight performance hit for this
		std::cout << garageCar->vehicleInformation() << "\n";
	}



	std::cin.get();
	/*
        ╔═══════════════╗
        ║  Inheritance  ║
        ╚═══════════════╝

								╔═════════╗     ╔══════════╗
				         class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)
	


				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car
             
    */

	Account savings1, savings2;
	savings1.mBalance = 10;
	savings2.mBalance = 20;
	Account savings3 = savings1 + savings2;



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

            add a new class, Pistol, that derives from Weapon.
            Pistol should have fields with getters/setters for rounds and magCapacity.
            Add a constructor that calls the base constructor
	
	*/






	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/






	/*
        ╔════════════════════════╗
        ║  RUNTIME Polymorphism  ║
        ╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/



}

