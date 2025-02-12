/*

This program will make use of randomly generated integers. The way to use random
    numbers in C++ was shown in today's class, and is summarized here:

    0. Rename this file to Even.cpp
    
    - Detecting Odd and Even Numbers
        Remember: any number 𝑛 is an even number if 𝑛 is evenly divisible by two. In other
        words, integer division of 𝑛 by 2 will leave a remainder of 0 if 𝑛 is even, and 1 if 𝑛 is odd.
        You can test for this by using the modulus operator, as shown in this pseudocode:
        If ( (𝑛 % 2) is 0 ) :
            𝑛 is even;
        otherwise:
            𝑛 is odd
        For this lab you must create a separate method named isEven() as described here:
            isEven():
                This method takes one integer argument as input
                This method returns the Boolean value true if the number is even,
                otherwise it returns false.

Your Task
    Your program will consist of two methods: the main()
    method, and the isEven() method described above.
    The main() method will use a for loop to generate 1,000 random integers in the range
    [0,100] inclusive. It should use the isEven() method to determine whether each random number
    is even or odd.
    When the loop is finished, the program should display, in a "creative" format, the number of
    random numbers, even numbers, and odd numbers that were generated.
    (your exact numbers will be different, and you may use your own specific wording):

*/

#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

bool isEven(int number){
    if(number % 2 == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    srand(time(0));
    int evenCount = 0;
    int oddCount = 0;

    for(int i = 0; i < 1000; i++){
        int number = rand() % 101;
        if(isEven(number)){
            evenCount++;
        }else{
            oddCount++;
        }
    }

    std::cout<<"Number of random numbers: 1000"<<std::endl;
    std::cout<<"Number of even numbers: "<<evenCount<<std::endl;
    std::cout<<"Number of odd numbers: "<<oddCount<<std::endl;

    return 0;
}

