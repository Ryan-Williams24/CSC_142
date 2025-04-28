#include <iostream>
#include <string>


int main() {

    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    std::string name;
    int age;

    std::cout << "What is your name: ";
    std::cin >> name;

    std::cout << "How old are you: ";
    std::cin >> age;

    int days = age * 365;

    std::cout << "\nHello, " << name << "! You are approximately " << days << " days old." << std::endl;

    return 0; 
}
