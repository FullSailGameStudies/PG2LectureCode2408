// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */

    std::string path = "C:\\temp\\2408\\";
    std::string fileName = "pg2_2408.csv";
    std::string fullPath = path + fileName;//C:\\temp\\2408\\pg2_2408.csv
    //1. OPEN the file
    std::ofstream outputFile(fullPath);//ATTEMPT to open the file
    //check if the file is open
    char delimiter = '$';
    if (outputFile.is_open())
    {
        //if open, write out to the file
        //2. WRITE to the file
        outputFile << "Batman rules.";
        outputFile 
            << delimiter << 5 
            << delimiter << 13.7
            << delimiter <<true 
            << delimiter << "Is aquaman ok in the head?";
    }
    else
    {
        std::cout << fullPath << " could not be found.\n";
    }
    //3. CLOSE the file
    outputFile.close();
    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */

    std::cout << "Enter something please: ";
    std::string input;
    std::getline(std::cin, input);//gets a line of data from the cin stream. stops when a newline (enter) is encountered
    std::cout << input << "\n";

    //1. OPEN the file
    std::ifstream inputFile(fullPath);
    //check if the file is open before reading it
    if (inputFile.is_open())
    {
        //2. READ the file
        //get a line from the file
        std::string line;
        std::getline(inputFile, line, '\n');//gets a line of data from the cin stream. stops when a newline (enter) is encountered
        std::cout << line << "\n";

        //use a stringstream to get the data from the string
        //line is just a string. it is NOT a stream.
        std::stringstream lineStream(line);//create a stream on the line
        std::string data;
        //reads "Batman rules."
        std::getline(lineStream, data, delimiter);//stop when it hits the delimiter
        std::cout << data << "\n";

        //reads "5"
        std::getline(lineStream, data, delimiter);//stop when it hits the delimiter
        int intData = std::stoi(data);
        std::cout << intData << "\n";
        
        //reads "13.7"
        std::getline(lineStream, data, delimiter);//stop when it hits the delimiter
        double dblData = std::stod(data);
        std::cout << dblData << "\n";

        //reads "1"
        std::getline(lineStream, data, delimiter);//stop when it hits the delimiter
        bool boolData = data == "1";
        std::cout << boolData << "\n";

        //reads "Is aquaman ok in the head"
        std::getline(lineStream, data, delimiter);//stop when it hits the delimiter
        std::cout << data << "\n";
    }
    else {
        std::cout << fullPath << " could not be opened.\n";
    }
    //3. CLOSE the file
    inputFile.close();
    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}