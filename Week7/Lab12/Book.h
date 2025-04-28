// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <iomanip>

class Book {
public:
    // Task 0: zero-arg constructor
    Book()
      : isbn_(""), author_(""), title_(""), edition_(0), publisher_(""), price_(0.0)
    {}

    // full constructor
    Book(const std::string& isbn,
         const std::string& author,
         const std::string& title,
         int edition,
         const std::string& publisher,
         double price)
      : isbn_(isbn),
        author_(author),
        title_(title),
        edition_(edition),
        publisher_(publisher),
        price_(price)
    {}

    const std::string& getIsbn() const { return isbn_; }
    void setPrice(double p)             { price_ = p;   }

    // Task 1: operator== (compare ISBNs)
    bool operator==(const Book& other) const {
        return isbn_ == other.isbn_;
    }

    // Task 1: operator<<
    friend std::ostream& operator<<(std::ostream& os, const Book& b) {
        // field widths chosen so columns line up
        os << std::left
           << std::setw(13) << b.isbn_  << ' '
           << std::setw(15) << b.author_ << ' '
           << std::setw(40) << b.title_  << ' '
           << std::right
           << std::setw(2)  << b.edition_ << "   "
           << std::left
           << std::setw(3)  << b.publisher_ << ' '
           << '$'
           << std::right
           << std::setw(7)
           << std::fixed << std::setprecision(2)
           << b.price_;
        return os;
    }

private:
    std::string isbn_, author_, title_, publisher_;
    int         edition_;
    double      price_;
};

#endif // BOOK_H