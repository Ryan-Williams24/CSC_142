#include <iostream>
#include <string>

class MagicItem {
private:
    std::string name;
    std::string powerType;
    int charges;

public:
    MagicItem(const std::string& itemName, const std::string& itemPowerType, int itemCharges)
        : name(itemName), powerType(itemPowerType), charges(itemCharges) {}

    void use() {
        if (charges > 0) {
            std::cout << name << " is used! Power: " << powerType << ". Remaining charges: " << --charges << "\n";
        } else {
            std::cout << name << " has no charges left and cannot be used.\n";
        }
    }

    void display() const {
        std::cout << "Magic Item: " << name << ", Power: " << powerType << ", Charges: " << charges << "\n";
    }
};

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    MagicItem fireWand("Fire Wand", "Fireball", 3);
    MagicItem iceAmulet("Ice Amulet", "Frost Shield", 2);
    MagicItem healingRing("Healing Ring", "Restore Health", 5);

    fireWand.display();
    iceAmulet.display();
    healingRing.display();

    std::cout << "\nUsing magic items:\n";
    fireWand.use();
    fireWand.use();
    fireWand.use();
    fireWand.use(); 

    iceAmulet.use();
    iceAmulet.use();
    iceAmulet.use(); 

    healingRing.use();
    healingRing.use();
    healingRing.use();
    healingRing.use();
    healingRing.use();
    healingRing.use(); 

    return 0;
}