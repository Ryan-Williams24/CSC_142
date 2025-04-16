#include <iostream>
#include <iomanip>
#include "Book.h"

void printBooks(const Book &b1, const Book &b2, const Book &b3) {
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(12) << "ISBN" 
              << std::setw(15) << "AUTHOR" 
              << std::setw(45) << "TITLE" 
              << std::right << std::setw(4) << "ED" 
              << std::setw(6) << "PUB" 
              << std::setw(10) << "PRICE" 
              << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(12) << b1.getISBN()
              << std::setw(15) << b1.getAuthor()
              << std::setw(45) << b1.getTitle().substr(0, 40)
              << std::right << std::setw(4) << b1.getEdition()
              << std::setw(6) << b1.getPubCode()
              << std::setw(10) << std::fixed << std::setprecision(2) << b1.getPrice() 
              << std::endl;

    std::cout << std::left << std::setw(12) << b2.getISBN()
              << std::setw(15) << b2.getAuthor()
              << std::setw(45) << b2.getTitle().substr(0, 40)
              << std::right << std::setw(4) << b2.getEdition()
              << std::setw(6) << b2.getPubCode()
              << std::setw(10) << std::fixed << std::setprecision(2) << b2.getPrice() 
              << std::endl;

    std::cout << std::left << std::setw(12) << b3.getISBN()
              << std::setw(15) << b3.getAuthor()
              << std::setw(45) << b3.getTitle().substr(0, 40)
              << std::right << std::setw(4) << b3.getEdition()
              << std::setw(6) << b3.getPubCode()
              << std::setw(10) << std::fixed << std::setprecision(2) << b3.getPrice() 
              << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
}

int main() {
    Book book1("013478796X", "Tony Gaddis", 
               "Starting Out With Java: From Control Structures through Data Structures", 
               4, "PE", 118.30);
    Book book2("0321409493", "John Lewis", 
               "Java Software Solutions: Foundations of Program Design", 
               5, "AW", 94.05);
    Book book3("0134743350", "Harvey Deitel", 
               "Java How to Program, Early Objects", 
               12, "PE", 134.84);

    printBooks(book1, book2, book3);

    std::cout << "Changing book1 price from $ 118.30 to $ 145.68" << std::endl;
    book1.changePrice(145.68);
    std::cout << "Changing book2 price from $ 94.05 to $ 117.79" << std::endl;
    book2.changePrice(117.79);
    std::cout << "Changing book3 price from $ 134.84 to $ 59.99" << std::endl;
    book3.changePrice(59.99);

    printBooks(book1, book2, book3);

    return 0;
}