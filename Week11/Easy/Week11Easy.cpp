#include <iostream>

class Goblin {
public:
    Goblin() {
        std::cout << "A Goblin has been summoned!" << std::endl;
    }
    ~Goblin() {
        std::cout << "The Goblin has been vanquished!" << std::endl;
    }
};

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    Goblin goblin;

    return 0;
}