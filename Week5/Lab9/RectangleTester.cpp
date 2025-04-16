#include <iostream>
#include "Rectangle.h"

int main() {
    Rectangle kitchen, bedroom, livingRoom;
    double length, width;

    std::cout << "Enter the length and width of the kitchen: ";
    std::cin >> length >> width;
    kitchen.setLength(length);
    kitchen.setWidth(width);

    std::cout << "Enter the length and width of the bedroom: ";
    std::cin >> length >> width;
    bedroom.setLength(length);
    bedroom.setWidth(width);

    std::cout << "Enter the length and width of the living room: ";
    std::cin >> length >> width;
    livingRoom.setLength(length);
    livingRoom.setWidth(width);

    std::cout << "\nRoom Sizes and Areas:\n";
    std::cout << "Kitchen: " << kitchen.getLength() << " x " << kitchen.getWidth() 
              << " - Area: " << kitchen.getArea() << " sq units\n";
    std::cout << "Bedroom: " << bedroom.getLength() << " x " << bedroom.getWidth() 
              << " - Area: " << bedroom.getArea() << " sq units\n";
    std::cout << "Living Room: " << livingRoom.getLength() << " x " << livingRoom.getWidth() 
              << " - Area: " << livingRoom.getArea() << " sq units\n";

    double totalArea = kitchen.getArea() + bedroom.getArea() + livingRoom.getArea();
    std::cout << "Total Apartment Area: " << totalArea << " sq units\n";

    return 0;
}