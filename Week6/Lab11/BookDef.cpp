#include "Book.h" // Ensure this file contains the declaration of the Book class
// Ensure the Book class is declared properly in Book.h
#include "Inventory.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

Book::Book() : isbn(""), author(""), title(""), edition(0), publisher(""), price(0.0) {}

Book::Book(const std::string& isbn, const std::string& author, const std::string& title, int edition, const std::string& publisher, double price)
    : isbn(isbn), author(author), title(title), edition(edition), publisher(publisher), price(price) {}

std::string Book::getISBN() const {
    return isbn;
}

void Book::setPrice(double newPrice) {
    price = newPrice;
}

std::string Book::toString() const {
    std::ostringstream oss;
    oss << std::left << std::setw(12) << isbn
        << std::setw(15) << author
        << std::setw(40) << title
        << std::setw(4) << edition
        << std::setw(4) << publisher
        << "$" << std::fixed << std::setprecision(2) << std::setw(8) << price;
    return oss.str();
}