#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string codeNum;
    std::string author;
    std::string title;
    int edition;
    std::string pubCode;
    double price;

public:
    Book(std::string cn, std::string au, std::string ti, int ed, std::string pc, double pr) 
        : codeNum(cn), author(au), title(ti), edition(ed), pubCode(pc), price(pr) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    double getPrice() const { return price; }
    int getEdition() const { return edition; }
    std::string getISBN() const { return codeNum; }
    std::string getPubCode() const { return pubCode; }
    void changePrice(double newPrice) { price = newPrice; }
};

#endif