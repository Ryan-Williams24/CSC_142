// Inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <iostream>

class Inventory {
public:
    Inventory(int size)
      : books_(new Book[size]),
        nextEntry_(0),
        length_(size)
    {}

    ~Inventory() {
        delete[] books_;
    }

    // Task 2: addBook — check capacity and duplicates
    bool addBook(const Book& b) {
        if (nextEntry_ >= length_) return false;
        for (int i = 0; i < nextEntry_; ++i) {
            if (books_[i] == b) return false;
        }
        books_[nextEntry_++] = b;
        return true;
    }

    // changePrice unchanged (no printing here)
    void changePrice(const std::string& isbn, double newPrice) {
        for (int i = 0; i < nextEntry_; ++i) {
            if (books_[i].getIsbn() == isbn) {
                books_[i].setPrice(newPrice);
                return;
            }
        }
    }

    // Task 2: printInventory uses operator<< on each Book
    void printInventory() const {
        std::cout
          << "-----------------------------------------------------------------------------------------\n"
          << "ISBN          AUTHOR          TITLE                                       ED  PUB     PRICE\n";
        for (int i = 0; i < nextEntry_; ++i) {
            std::cout << books_[i] << "\n";
        }
        std::cout
          << "-----------------------------------------------------------------------------------------\n";
    }

private:
    Book* books_;
    int   nextEntry_;
    int   length_;
};

#endif // INVENTORY_H