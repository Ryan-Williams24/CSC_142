#include <iostream>

void drinkPotion(int& heroHP, int healAmount) {
    heroHP += healAmount;
}

void damageHero(int* heroHP, int damageAmount) {
    if (heroHP) {
        *heroHP -= damageAmount;
    }
}

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    int heroHP = 10;

    std::cout << "Initial Hero HP: " << heroHP << "\n";

    drinkPotion(heroHP, 5);
    std::cout << "Hero HP after drinking potion: " << heroHP << "\n";

    damageHero(&heroHP, 3);
    std::cout << "Hero HP after taking damage: " << heroHP << "\n";

    return 0;
}