#include <iostream>
#include <cstdlib>
#include <ctime>

int rollDice(int sides) {
    return (std::rand() % sides) + 1;
}

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    std::srand(std::time(0));

    int heroHP = 20, heroAC = 15;
    int goblinHP = 10, goblinAC = 12;

    while (heroHP > 0 && goblinHP > 0) {
        int heroAttackRoll = rollDice(20);
        int goblinAttackRoll = rollDice(20);

        std::cout << "Hero rolls a d20: " << heroAttackRoll << "\n";
        if (heroAttackRoll >= goblinAC) {
            int heroDamage = rollDice(8);
            goblinHP -= heroDamage;
            std::cout << "Hero hits Goblin for " << heroDamage << " damage. Goblin HP: " << goblinHP << "\n";
        } else {
            std::cout << "Hero misses the Goblin.\n";
        }

        if (goblinHP <= 0) break;

        std::cout << "Goblin rolls a d20: " << goblinAttackRoll << "\n";
        if (goblinAttackRoll >= heroAC) {
            int goblinDamage = rollDice(6);
            heroHP -= goblinDamage;
            std::cout << "Goblin hits Hero for " << goblinDamage << " damage. Hero HP: " << heroHP << "\n";
        } else {
            std::cout << "Goblin misses the Hero.\n";
        }
    }

    if (heroHP > 0) {
        std::cout << "The Hero is victorious!\n";
    } else {
        std::cout << "The Goblin has defeated the Hero.\n";
    }

    return 0;
}