// Inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <iostream>
#include <iomanip>
#include <string>

class Inventory {
public:
    // ctor: allocate array of given size
    Inventory(int size)
      : books_(new Book[size]),
        nextEntry_(0),
        length_(size)
    {}

    // dtor: free array
    ~Inventory() {
        delete[] books_;
    }

    // Task 1.1: addBook
    // returns true if there was space; false if full
    bool addBook(const Book& b) {
        if (nextEntry_ >= length_) return false;
        books_[nextEntry_++] = b;
        return true;
    }

    // Task 1.2: changePrice
    void changePrice(const std::string& isbn, double newPrice) {
        for (int i = 0; i < nextEntry_; ++i) {
            if (books_[i].getIsbn() == isbn) {
                books_[i].setPrice(newPrice);
                return;
            }
        }
        // not found: silently do nothing (could print a warning)
    }

    // Task 1.3: printInventory
    void printInventory() const {
        // header
        std::cout
          << "ISBN          AUTHOR           TITLE                                   ED  PUB   PRICE\n"
          << "--------------------------------------------------------------------------------\n";

        for (int i = 0; i < nextEntry_; ++i) {
            const Book& b = books_[i];
            std::cout
              << std::left
              << std::setw(13) << b.getIsbn()  << ' '
              << std::setw(15) << b.getAuthor() << ' '
              << std::setw(40) << b.getTitle()  << ' '
              << std::right
              << std::setw(2)  << b.getEdition() << "   "
              << std::left
              << std::setw(3)  << b.getPublisher() << ' '
              << '$'
              << std::right
              << std::setw(7)  << std::fixed << std::setprecision(2) << b.getPrice()
              << "\n";
        }

        std::cout << "--------------------------------------------------------------------------------\n";
    }

private:
    Book* books_;
    int   nextEntry_;
    int   length_;
};

#endif // INVENTORY_H