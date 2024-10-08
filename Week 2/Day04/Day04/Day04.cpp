﻿// Day04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <string_view>


std::string toUpper(const std::string& original)
{
	std::string copy = original;
	for (auto& c : copy)
		c = toupper(c);
	return copy;
}

void recursiveLoop(int N)
{
	recursiveLoop(N + 1);
}

unsigned long factorial(unsigned int N)
{
	if (N <= 1) return 1; //here's the exit condition!
	return N * factorial(N - 1);
}

/*
			procedure bubbleSort(A : list of sortable items)
			  n := length(A)
			  repeat
				  swapped := false
				  for i := 1 to n - 1 inclusive do
					  if A[i - 1] > A[i] then
						  swap(A, i - 1, i)
						  swapped = true
					  end if
				  end for
				  n := n - 1
			  while swapped
			end procedure
*/

// procedure bubbleSort(A : list of sortable items)
void bubbleSort(std::vector<std::string>& A)
{
	//n := length(A)
	int n = A.size();

	bool swapped = false;
	do //repeat
	{
		//swapped: = false
		swapped = false;
		//for i := 1 to n - 1 inclusive do
		for (int i = 1; i <= n-1; i++)
		{
			//if A[i - 1] > A[i] then
			//_stricmp case insensitive
			//returns an int...
			//   if < 0  means less than
			//   if == 0 means equal
			//   if > 0 greater than
			if (_stricmp(A[i - 1].c_str(), A[i].c_str()) > 0)//case insensitive
			{
				//swap(A, i - 1, i)????
				//OG swap
				//std::string temp = A[i - 1];
				//A[i - 1] = A[i];
				//A[i] = temp;

				//modern swap...
				std::swap(A[i - 1], A[i]);
				
				//swapped = true
				swapped = true;
			}//end if
		}//end for
		//n := n - 1
		--n;
	} while (swapped);//while swapped
}//end procedure... return? break?  }

void SayHi(int i = 0)
{
	//recursion causes a stack overflow if it loops too many times
	//we need an exit condition to prevent a stack overflow AND to end our recursive loop
	//int i = 0;
	if (i >= 20) return;

	//if (i < 20)//loops when this is true
	{
		std::cout << i << ": Hello Gotham!\n";
		i++;
		SayHi(i);//calling itself causes a recursive LOOP b/c it executes the block of code again
		
	}
}//return statement jumps to this }

int main()
{
	std::vector<std::string> names = { "Wonder Woman", "Superman", "Batman", "Flash", "Aquaman" };
	//print the unsorted vector.
	std::cout << "\nUNSORTED...\n";
	for (auto& name : names)
		std::cout << name << "\n";

	//call your BubbleSort on the names vector.
	bubbleSort(names);

	//print the sorted vector.
	std::cout << "\nSORTED...\n";
	for (auto& name : names)
		std::cout << name << "\n";

	std::cin.get();


	/*
	//Working with a vector...
	//create a vector
	std::vector<int> nums;

	//add to a vector
	nums.push_back(5);

	//get # of items
	int numberOfItems = nums.size();

	//get the first item in a vector
	int number = nums[0];
	number = nums.at(0);
	number = nums.front();
	number = *(nums.begin());

	//get the item using an index
	int index = 0;
	int number = nums[index];
	number = nums.at(index);

	//erase from a vector
	nums.erase(nums.begin());//to erase the first item

	//check if a vector is empty
	bool isEmpty = nums.empty();
	isEmpty = nums.size() == 0;

	//check if a vector is NOT empty
	bool notEmpty = !nums.empty();
	notEmpty = nums.size() != 0;
	*/

	/*
		╔═════════╗
		║Recursion║
		╚═════════╝

		Recursion happens when a method calls itself. This creates a recursive loop.

		All recursive methods need an exit condition, something that prevents the loop from continuing.

	*/

	int random = 20;
	for (size_t i = 0; i < random; i++)
	{
	}

	SayHi();
	int N = 0;
	//recursiveLoop(N);



	/*
		CHALLENGE 1:

			convert this for loop to a recursive method called Bats.
			Call Bats here in Main.

			for(int i = 0;i < 100;i++)
			{
				std::cout << (char)78 << (char)65 << ' ';
			}
	*/
	//call Bats here.

	char c[] = { '\n', 66, 65, 84, 77, 65, 78, 33, 33 };
	for (auto ch : c) std::cout << ch;



	/*
		╔═════════════════╗
		║  Swapping Items ║
		╚═════════════════╝

		add #include <string_view>
		make sure the project is using C++17 or greater.

	*/
	std::cout << "\n\n---SWAPPING ITEMS---\n";
	std::vector<int> nums = { 1,2,3,4,5 };
	for (auto i : nums)
		std::cout << i << " ";
	std::cout << " (original)\n";

	//write code to swap 2 items in the vector

	std::cout << " (after swapping)\n";
	for (auto i : nums)
		std::cout << i << " ";

	/*
		╔═════════════════╗
		║Comparing Strings║
		╚═════════════════╝

		the compare functions return an int that will tell you
		how the strings compare to each other.
		< 0 means s1 is LESS THAN (or comes before) s2
		  0 means s1 is EQUAL TO s2
		> 0 means s1 is GREATER THAN (or comes after) s2

		_stricmp: case-insensitive string comparison.
			The methods needs pointers to char arrays therefore
			you need to call c_str on the std::string

		std::string::compare:  case-sensitive string comparison
			If you want to ignore case, you can convert the strings
			to all uppercase/lowercase

	*/
	std::string s1 = "Batman", s2 = "Aquaman";
	int compResult = _stricmp(s1.c_str(), s2.c_str());
	//OR...
	int compareResult = toUpper(s1).compare(toUpper(s2));






	/*
		╔═══════╗
		║Sorting║
		╚═══════╝

		Sorting is used to order the items in a vector/array is a specific way

		CHALLENGE 2:

			Convert this BubbleSort pseudo-code into a method

			procedure bubbleSort(A : list of sortable items)
			  n := length(A)
			  repeat
				  swapped := false
				  for i := 1 to n - 1 inclusive do
					  if A[i - 1] > A[i] then
						  swap(A, i - 1, i)
						  swapped = true
					  end if
				  end for
				  n := n - 1
			  while swapped
			end procedure

	*/
}