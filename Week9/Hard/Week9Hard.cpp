#include <iostream>
#include <string>
#include <cstdlib> 

enum class CharacterType { Warrior, Archer, Mage, Rogue };

std::string typeToString(CharacterType type) {
    switch (type) {
        case CharacterType::Warrior: return "Warrior";
        case CharacterType::Archer:  return "Archer";
        case CharacterType::Mage:    return "Mage";
        case CharacterType::Rogue:   return "Rogue";
        default:                     return "Unknown";
    }
}

struct Character {
    std::string name;       
    CharacterType type;     
    int health;             
    float strength;         
};

int main() {

    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    Character characters[4] = {
        { "Ryan",  CharacterType::Warrior, 200, 90.5f },
        { "Jacob", CharacterType::Archer, 125, 80.0f },
        { "Tyler", CharacterType::Mage, 75, 75.0f },
        { "Mason", CharacterType::Rogue, 100, 60.5f }
    };

    int totalHealth = 0;
    std::cout << "Characters:\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "Name: " << characters[i].name << ", Type: " << typeToString(characters[i].type) << ", Health: " << characters[i].health << "\n";
        totalHealth += characters[i].health;
    }

    float averageHealth = static_cast<float>(totalHealth) / 4.0f;
    std::cout << "\nAverage Health: " << averageHealth;

    return 0;
}