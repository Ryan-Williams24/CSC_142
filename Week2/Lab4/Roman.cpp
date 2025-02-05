/*

    Your task:
        - Rename this file to Roman.cpp

        In this file create a single main() method, that will perform the following algorithm:

            - Use a do-while loop to prompt the user for an integer input in the range 1
            through 10, inclusive. If the input is not in range let them try again. Repeat until
            the user successfully enters a correct value.

            - Once a valid value is entered, print a descriptive message that reports the
            roman numeral that is equal to the value given.

        Specifications:

            For full credit, your program must meet the following specifications:
                1. Your method of converting the number to a Roman numeral must use only one
                multi-branch if statement. You must not use the Boolean operators && (and),
                || (or), and ! (not) when performing the conversion.

                2. Use meaningful variable names and follow all naming conventions.
                
                3. Use meaningful prompts and output messages.

                4. User input that is invalid must be handled sensibly, as described above. Invalid
                input in this case would be a number that is not in the range [1, 10], inclusive.
                (You may assume that only integers will be input.) Your program must print an
                appropriate message if the user input is outside the range [1, 10] and allow the
                user to re-enter their number.

            Extra-credit opportunity:
                For up to 3 additional points, extend your program so that it generates the correct
                response for any integer value in the range [1, 100], inclusive.
                If you choose to do the extra credit, to achieve the maximum extra credit you may use
                at most two multi-branch if statements to generate the Roman numeral.
                (Hint: Don’t use a 100-branch if statement! Instead, find a creative way to separate the
                tens from the ones...)

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

    int number;

    std::cout<<"Please enter a number between 1 and 10: ";
    std::cin>>number;

    while(number < 1 || number > 10){
        
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
        
        std::cout<<"Invalid input. Please enter a number between 1 and 10: ";
        std::cin>>number;
        
    }

    if(number > 0 || number < 11){
        if(number == 1){
            std::cout<<"The Roman numeral for 1 is I."<<std::endl;
        }else if(number == 2){
            std::cout<<"The Roman numeral for 2 is II."<<std::endl;
        }else if(number == 3){
            std::cout<<"The Roman numeral for 3 is III."<<std::endl;
        }else if(number == 4){
            std::cout<<"The Roman numeral for 4 is IV."<<std::endl;
        }else if(number == 5){
            std::cout<<"The Roman numeral for 5 is V."<<std::endl;
        }else if(number == 6){
            std::cout<<"The Roman numeral for 6 is VI."<<std::endl;
        }else if(number == 7){
            std::cout<<"The Roman numeral for 7 is VII."<<std::endl;
        }else if(number == 8){
            std::cout<<"The Roman numeral for 8 is VIII."<<std::endl;
        }else if(number == 9){
            std::cout<<"The Roman numeral for 9 is IX."<<std::endl;
        }else if(number == 10){
            std::cout<<"The Roman numeral for 10 is X."<<std::endl;
        }
    }
     
}
