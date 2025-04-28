// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    // Task 0: default (zero-arg) constructor
    Book()
      : isbn_(), author_(), title_(), edition_(0), publisher_(), price_(0.0)
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

    // getters
    const std::string& getIsbn()    const { return isbn_; }
    const std::string& getAuthor()  const { return author_; }
    const std::string& getTitle()   const { return title_; }
    int               getEdition() const { return edition_; }
    const std::string& getPublisher() const { return publisher_; }
    double            getPrice()   const { return price_; }

    // setter for price (used by Inventory::changePrice)
    void setPrice(double p) { price_ = p; }

private:
    std::string isbn_;
    std::string author_;
    std::string title_;
    int         edition_;
    std::string publisher_;
    double      price_;
};

#endif // BOOK_H