// InventoryTester.cpp
#include "Book.h"
#include "Inventory.h"
#include <iostream>

int main() {
    Inventory inv(10);

    // 2. create & add each Book
    struct {
        const char* isbn;
        const char* author;
        const char* title;
        int edition;
        const char* pub;
        double price;
    } data[] = {
        {"013478796X", "Tony Gaddis",  "Starting Out With Java: From Control Structures through Data Structures", 4,  "PE", 121.75},
        {"0321409493", "John Lewis",   "Java Software Solutions: Foundations of Program Design",             5,  "AW",  94.00},
        {"0134743350", "Harvey Deitel","Java How to Program, Early Objects",                               12, "PE", 134.84},
        {"002360692X", "Richard Johnsonbaugh","Algorithms",                                1,  "PH", 109.00},
        {"1593276036", "Eric Matthes", "Python Crash Course",                                           1,  "NS",  39.95},
        {"0143067889", "Ray Kurzweil","The Singularity is Near",                                      1,  "PG",  17.70}
    };

    for (auto& d : data) {
        Book b{d.isbn, d.author, d.title, d.edition, d.pub, d.price};
        if (!inv.addBook(b)) {
            std::cerr << "Failed to add book ISBN=" << d.isbn << "\n";
        }
    }

    // 3. initial report
    std::cout << "\n--- Initial Inventory ---\n";
    inv.printInventory();

    // 4. test changePrice
    inv.changePrice("013478796X", 50.00);
    inv.changePrice("0143067889",  9.95);
    inv.changePrice("0134743350",100.00);

    // 5. final report
    std::cout << "\n--- After Price Changes ---\n";
    inv.printInventory();

    return 0;
}