// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"
#include <iomanip>

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

int main()
{
    //_stricmp(char* s1,char* s2) - char* means a string
    //std::string != char*. 
    //.c_str() returns the std::string's char*
    // _stricmp returns an int
    //      < 0 means s1 less than s2
    //      == 0 means s1 equals s2
    //      > 0 means s1 greater than s2
    std::string s1 = "Batman", s2 = "Aquaman";
    int comparisonResult = _stricmp(s1.c_str(), s2.c_str());
    if (comparisonResult < 0)
        std::cout << s1 << " is LESS THAN " << s2 << "\n";
    else if (comparisonResult == 0)
        std::cout << s1 << " EQUALS " << s2 << "\n";
    else //if(comparisonResult > 0)
        std::cout << s1 << " is GREATER THAN " << s2 << "\n";
    std::cin.get();


    FullSailCourse pg2;
    FullSailCourse pg1;
    std::string courseName = "PG2 2408";
    pg2.SetName(courseName);//copying the courseName to the methods parameter
    pg1.SetName("PG1 2408");
    std::string myCourse = pg2.GetName();
    std::cout << "My course this month: " << myCourse << "\n";
    std::cin.get();
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    {
        std::string spider = "Spiderman";
        bool isEven = postFix(spider);
        std::string evenResult = (isEven) ? "TRUE" : "FALSE";
        std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";
    }

    /*
        CHALLENGE 1:

            Write a method to FullSailCourse to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector
            3) after calling the method, loop and print the vector in main

    */
    std::vector<float> grades;
    pg2.GetGrades(grades);//passed by reference so pg2 will fill our vector
    pg2.PrintGrades(grades);
    std::cin.get();



    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    for (int i = 0; i < 10; ++i)
        highScores.push_back(rand());
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    for (size_t i = 0; i < highScores.size();)
    {
        if (highScores[i] < 2500)
            highScores.erase(highScores.begin() + i);
        else
            ++i;
    }


    /*
        INTERMEDIATE LEVEL...
        a way using std::remove_if and a lambda
    highScores.erase(
        std::remove_if(highScores.begin(),
            highScores.end(),
            [](int score) { return score < 2500; }),
        highScores.end());
    */


    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}