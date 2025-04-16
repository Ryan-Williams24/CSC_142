#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    for (auto& num : numbers) {  // Use auto instead of explicit type
        std::cout << num << std::endl;
    }

    return 0;
}