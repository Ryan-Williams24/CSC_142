#include <iostream>

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    int gold = 100;
    int potionCost = 10;
    int potionsToBuy;

    std::cout << "Welcome to the Potion Shop! Healing potions cost 10 gold pieces each.\n";
    std::cout << "You have " << gold << " gold pieces.\n";
    std::cout << "How many potions would you like to buy? ";
    std::cin >> potionsToBuy;

    int totalCost = potionsToBuy * potionCost;

    if (totalCost <= gold) {
        gold -= totalCost;
        std::cout << "You bought " << potionsToBuy << " potions. You now have " << gold << " gold pieces left.\n";
    } else {
        std::cout << "You do not have enough gold to buy " << potionsToBuy << " potions.\n";
    }

    return 0;
}