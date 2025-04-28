#include <iostream>
#include <stdexcept>

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Operation operation; 

    Calculator(Operation op) : operation(op) {}

    int calculate(int a, int b) {
        switch (operation) {
            case Operation::Add:
                return a + b;
            case Operation::Subtract:
                return a - b;
            case Operation::Multiply:
                return a * b;
            case Operation::Divide:
                if (b == 0) {
                    throw std::invalid_argument("Division by zero is not allowed.");
                }
                return a / b;
            default:
                throw std::invalid_argument("Invalid operation.");
        }
    }
};

int main() {
    
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
    
    Calculator addCalculator(Operation::Add);
    Calculator subtractCalculator(Operation::Subtract);
    Calculator multiplyCalculator(Operation::Multiply);
    Calculator divideCalculator(Operation::Divide);

    int a = 10, b = 5;

    std::cout << "Addition: " << addCalculator.calculate(a, b) << "\n";
    std::cout << "Subtraction: " << subtractCalculator.calculate(a, b) << "\n";
    std::cout << "Multiplication: " << multiplyCalculator.calculate(a, b) << "\n";
    try {
        std::cout << "Division: " << divideCalculator.calculate(a, b) << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}