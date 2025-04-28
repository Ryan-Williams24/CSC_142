#include <iostream>
#include <string>
#include <utility>

void showGadgets(std::string g1, std::string g2) {
    
    std::cout << "Gadget 1: " << g1 << ", Gadget 2: " << g2 << "\n";

}

int main() {

    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
    
    std::string gadget1 = "Batarang";
    std::string gadget2 = "Grappling Hook";

    showGadgets(gadget1, gadget2);
    std::swap(gadget1, gadget2);
    showGadgets(gadget1, gadget2);

    return 0;

}
