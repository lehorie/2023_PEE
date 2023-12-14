#include <iostream>
#include <fstream>
#include <string>
#include<map>

void teste() {
    std::fstream usersByMemory;
    std::map<std::string, long> userMemoryMap;

    //usersByMemory.open("users.txt", std::ios::out);  // open a file to perform write operation using file object
   // if (usersByMemory.is_open())     //checking whether the file is open
    //{
    //    usersByMemory << "Tutorials point what \n"; //inserting text
     //   usersByMemory.close(); //close the file object
    //}


    usersByMemory.open("users.txt", std::ios::in); //open a file to perform read operation using file object
    if (!usersByMemory) {   //checking whether the file is open
        std::cout << "fail to get txt";
    }
    else {  
        std::string fileString;
        while (std::getline(usersByMemory, fileString)) {  //read data from file object and put it into string.
            std::cout << fileString << "\n";   //print the data of the string
            userMemoryMap[fileString];
        }
        usersByMemory.close();   //close the file object.
    }
}