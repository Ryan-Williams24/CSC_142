#ifndef INVENTORY_H
#define INVENTORY_H
#endif  INVENTORY_H

#include <string>
#include <vector>
#include "Book.h"

class Inventory {
private:
    std::vector<Book> books;
    int capacity;

public:
    Inventory(int capacity);
    void addBook(const Book& book);
    void changePrice(const std::string& isbn, double newPrice);
    void printInventory() const;
};

#include <iostream>
#include <iomanip>

Inventory::Inventory(int capacity) : capacity(capacity) {}

void Inventory::addBook(const Book& book) {
    if (books.size() < capacity) {
        books.push_back(book);
    } else {
        std::cerr << "Inventory is full. Cannot add more books.\n";
    }
}

void Inventory::changePrice(const std::string& isbn, double newPrice) {
    for (auto& book : books) {
        if (book.getISBN() == isbn) {
            book.setPrice(newPrice);
            return;
        }
    }
    std::cerr << "Book with ISBN " << isbn << " not found.\n";
}

void Inventory::printInventory() const {
    for (const auto& book : books) {
        std::cout << std::fixed << std::setprecision(2)
                  << "ISBN: " << book.getISBN()
                  << ", Author: " << book.getAuthor()
                  << ", Title: " << book.getTitle()
                  << ", Edition: " << book.getEdition()
                  << ", Publisher: " << book.getPublisher()
                  << ", Price: $" << book.getPrice() << '\n';
    }
}