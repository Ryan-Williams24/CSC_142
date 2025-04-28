// InventoryTester.cpp
#include "Book.h"
#include "Inventory.h"
#include <iostream>
#include <iomanip>

int main() {
    Inventory inv(10);

    // (1) Add the six original books:
    Book originals[] = {
        {"013478796X","Tony Gaddis",  "Starting Out With Java: From Control Structures through Data Structures", 4,"PE",121.75},
        {"0321409493","John Lewis",   "Java Software Solutions: Foundations of Program Design",             5,"AW", 94.00},
        {"0134743350","Harvey Deitel","Java How to Program, Early Objects",                               12,"PE",134.84},
        {"002360692X","Richard Johnsonbaugh","Algorithms",                          1,"PH",109.00},
        {"1593276036","Eric Matthes", "Python Crash Course",                                           1,"NS", 39.95},
        {"0143067889","Ray Kurzweil","The Singularity is Near",                                        1,"PG", 17.70}
    };
    for (auto& b : originals) {
        if (!inv.addBook(b)) {
            std::cout << "ERROR adding this book: " << b.getIsbn() << "\n";
        }
    }

    // (3) Task 3: attempt to add the six new books
    Book extras[] = {
        {"0134444329","Tony Gaddis","Starting Out With Python",                         4,"PE", 99.95},
        {"0133582736","Tony Gaddis","Starting Out With Python",                         3,"PE", 19.95},
        {"013478796X","Tony Gaddis","Starting Out With Java: From Control Structures through Data Structures",4,"PE",145.38},
        {"1119056553","Cay Horstmann","Python for Everyone",                             2,"WI", 98.38},
        {"0134802217","Tony Gaddis","Starting Out With Java: From Control Structures through Objects",7,"PE",188.95},
        {"0134462017","Tony Gaddis","Starting Out With Java: Early Objects",             6,"PE", 58.50}
    };
    for (auto& b : extras) {
        if (!inv.addBook(b)) {
            std::cout << "ERROR adding this book: " << b.getIsbn() << "\n";
        }
    }

    // (3b) Initial report
    std::cout << "\nInitial Inventory Report:\n";
    inv.printInventory();

    // (4) Test changePrice
    struct { const char* isbn; double price; } changes[] = {
        {"013478796X", 50.00},
        {"0143067889",  9.95},
        {"0134743350",100.00}
    };
    for (auto& c : changes) {
        std::cout << "Changing price of " << c.isbn
                  << " to $ " << std::fixed << std::setprecision(2)
                  << c.price << "\n";
        inv.changePrice(c.isbn, c.price);
    }

    // (5) Final report
    std::cout << "\nFinal Inventory Report:\n";
    inv.printInventory();

    return 0;
}