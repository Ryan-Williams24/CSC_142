#include <iostream>
#include <utility>

int main() {
    
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
    
    std::pair<std::string, std::string> alert{"Joker", "Arkham Asylum"};
    std::cout << alert.first << " spotted at " << alert.second << "!\n";
    
    return 0;

}
