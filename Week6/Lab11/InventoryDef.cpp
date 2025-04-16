#include "Inventory.h"
#include <iostream>
#include <iomanip>

Inventory::Inventory(int size) : nextEntry(0), length(size) {
    books = new Book[size];
}

Inventory::~Inventory() {
    delete[] books;
}

bool Inventory::addBook(const Book& theBook) {
    if (nextEntry >= length) {
        return false;
    }
    books[nextEntry++] = theBook;
    return true;
}

void Inventory::changePrice(const std::string& isbn, double newPrice) {
    for (int i = 0; i < nextEntry; ++i) {
        if (books[i].getISBN() == isbn) {
            books[i].setPrice(newPrice);
            return;
        }
    }
}

void Inventory::printInventory() const {
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::cout << "ISBN        AUTHOR          TITLE                                    ED  PUB      PRICE\n";
    std::cout << "---------------------------------------------------------------------------------------\n";
    for (int i = 0; i < nextEntry; ++i) {
        std::cout << books[i].toString() << "\n";
    }
    std::cout << "---------------------------------------------------------------------------------------\n";
}