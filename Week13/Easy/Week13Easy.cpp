#include <iostream>

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    for (int i = 10; i > 0; i--) {
        std::cout << i << "\n";
    }

    std::cout << "Liftoff!\n";

    return 0;
}