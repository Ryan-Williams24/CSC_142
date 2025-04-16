#include <iostream>
#include <cstdlib>
#include <ctime>

int roll_attack() {
    return (std::rand() % 20) + 1;
}

int roll_defense() {
    return (std::rand() % 20) + 1;
}

bool is_hit(int attack, int defense) {
    return attack > defense;
}

void duel() {
    int obiWanWins = 0, darthMaulWins = 0;

    for (int round = 1; round <= 5; ++round) {
        int obiWanAttack = roll_attack();
        int darthMaulDefense = roll_defense();
        int darthMaulAttack = roll_attack();
        int obiWanDefense = roll_defense();

        std::cout << "Round " << round << ":\n";

        if (is_hit(obiWanAttack, darthMaulDefense)) {
            std::cout << "Obi-Wan hits Darth Maul!\n";
            obiWanWins++;
        } else {
            std::cout << "Darth Maul deflects Obi-Wan's attack!\n";
        }

        if (is_hit(darthMaulAttack, obiWanDefense)) {
            std::cout << "Darth Maul hits Obi-Wan!\n";
            darthMaulWins++;
        } else {
            std::cout << "Obi-Wan deflects Darth Maul's attack!\n";
        }

        std::cout << "Score: Obi-Wan " << obiWanWins << " - Darth Maul " << darthMaulWins << "\n\n";
    }

    std::cout << "Final Score: Obi-Wan " << obiWanWins << " - Darth Maul " << darthMaulWins << "\n";
    if (obiWanWins > darthMaulWins) {
        std::cout << "Obi-Wan wins the duel!\n";
    } else if (darthMaulWins > obiWanWins) {
        std::cout << "Darth Maul wins the duel!\n";
    } else {
        std::cout << "The duel ends in a draw!\n";
    }
}

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    std::srand(std::time(0));
    duel();

    return 0;
}