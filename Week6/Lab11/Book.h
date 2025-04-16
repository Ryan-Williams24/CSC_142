#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book();
    Book(const std::string& isbn, const std::string& author, const std::string& title, int edition, const std::string& publisher, double price);

    std::string getISBN() const;
    void setPrice(double newPrice);
    std::string toString() const;

private:
    std::string isbn;
    std::string author;
    std::string title;
    int edition;
    std::string publisher;
    double price;
};

#endif // BOOK_H