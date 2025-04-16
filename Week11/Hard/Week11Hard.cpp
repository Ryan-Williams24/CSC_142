#include <iostream>
#include <string>

class Inventory {
private:
    std::string* items;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        std::string* newItems = new std::string[capacity];
        for (int i = 0; i < size; ++i) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }

public:
    Inventory() : capacity(10), size(0) {
        items = new std::string[capacity];
    }

    ~Inventory() {
        delete[] items;
    }

    Inventory(const Inventory& other) : capacity(other.capacity), size(other.size) {
        items = new std::string[capacity];
        for (int i = 0; i < size; ++i) {
            items[i] = other.items[i];
        }
    }

    void addItem(const std::string& item) {
        if (size == capacity) {
            resize();
        }
        items[size++] = item;
    }

    void showInventory() const {
        for (int i = 0; i < size; ++i) {
            std::cout << items[i] << std::endl;
        }
    }
};

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    Inventory inventory1;
    inventory1.addItem("Magic Sword");
    inventory1.addItem("Potion of Healing");

    Inventory inventory2 = inventory1;
    inventory2.addItem("Bag of Holding");

    std::cout << "Inventory 1:" << std::endl;
    inventory1.showInventory();

    std::cout << "\nInventory 2:" << std::endl;
    inventory2.showInventory();

    return 0;
}