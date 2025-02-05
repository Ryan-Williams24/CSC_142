/*
    0. Rename this file to Exams.cpp

    1. In this file, and every file created for this class, add comments at the top of the file that include:
        - The name of the file: Exams.cpp
        - A brief description of the program (or class) that’s in the file: This program calculates the average of three exam scores.
        - Your name: Ryan Williams
        - Today’s date: 1-29-25
    
    2. In this file, create a single function called main() that performs the following steps 
    (if you are unsure how to do any of these things, consult with last weeks lab to find suggestions):

        - Prompt the user to input a String that is their name.

        - Prompt the user to input three integers, representing exam scores. Each
        integer should be stored in a separate variable of type int.

        - Calculate the average of the three exam scores and store the result in a
        variable of type double. Note: be careful about integer division! For full
        credit the average you calculate must be numerically correct.

        - Display the input data (the user’s name and three exam scores). Also
        display the calculated result (the exam average), formatted to two digits
        to the right of the decimal point.

        - For full credit, your program must print all the input data as well as the
        results, in a clearly understandable manner, with appropriate descriptive
        labels and formatting.

    4. A successful run should have output that looks something like the output that is provided in the Lab3 folder:

*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main(){
    
     #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
    
    std::string name;
    int exam1;
    float exam2;
    double exam3;
    double average;
    
    
    std::cout<<"Please enter your name: ";
    std::getline(std::cin, name);

    std::cout<<"Please enter your first exam score: ";    
    std::cin>>exam1;
    std::cout<<"Please enter your second exam score: ";
    std::cin>>exam2;
    std::cout<<"Please enter your third exam score: ";
    std::cin>>exam3;

    average = (exam1 + exam2 + exam3);
    average = average / 3;

    std::cout<<std::endl;
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Exam 1: "<<exam1<<std::endl;
    std::cout<<"Exam 2: "<<exam2<<std::endl;
    std::cout<<"Exam 3: "<<exam3<<std::endl;
    std::cout<<"Average: "<<std::fixed<<std::setprecision(2)<<average<<std::endl;

    return 0;
}