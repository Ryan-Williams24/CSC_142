#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    
    #ifdef _WIN32
    std::system("cls");
    #else
    std::system("clear");
    #endif
    
    std::srand(std::time(0));
    int charisma = (std::rand() % 20) + 1;

    std::cout << "Charisma Roll: " << charisma << std::endl;
    
    if (charisma >= 10) {
        std::cout << "You may enter the castle!" << std::endl;
    } else {
        std::cout << "You shall not pass!" << std::endl;
    }
    
    return 0;
}
