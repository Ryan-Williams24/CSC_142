#include <iostream>

void countdown_to_lightspeed(int seconds) {
    while (seconds > 0) {
        std::cout << "Jumping in " << seconds << "...\n";
        seconds--;
    }
    std::cout << "Punch it, Chewie!\n";
}

int main() {

    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
    
    countdown_to_lightspeed(5);
    return 0;
}