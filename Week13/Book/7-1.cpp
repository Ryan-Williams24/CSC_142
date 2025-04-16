#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>

class UnsignedBigInteger {
private:
    std::vector<uint8_t> digits;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

public:
    UnsignedBigInteger() : digits(1, 0) {}

    UnsignedBigInteger(const std::string& number) {
        for (auto it = number.rbegin(); it != number.rend(); ++it) {
            if (!isdigit(*it)) {
                throw std::invalid_argument("Invalid character in number");
            }
            digits.push_back(*it - '0');
        }
    }

    UnsignedBigInteger(const int number) {
        if (number < 0) {
            throw std::invalid_argument("UnsignedBigInteger cannot represent negative numbers");
        }
        int temp = number;
        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        if (digits.empty()) {
            digits.push_back(0);
        }
    }

    UnsignedBigInteger operator+(const UnsignedBigInteger& other) const {
        UnsignedBigInteger result;
        result.digits.clear();

        size_t maxSize = std::max(digits.size(), other.digits.size());
        uint8_t carry = 0;

        for (size_t i = 0; i < maxSize || carry; ++i) {
            uint8_t digit1 = (i < digits.size()) ? digits[i] : 0;
            uint8_t digit2 = (i < other.digits.size()) ? other.digits[i] : 0;

            uint8_t sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.digits.push_back(sum % 10);
        }

        return result;
    }

    UnsignedBigInteger operator-(const UnsignedBigInteger& other) const {
        if (*this < other) {
            throw std::underflow_error("Result would be negative");
        }

        UnsignedBigInteger result;
        result.digits.clear();

        uint8_t borrow = 0;

        for (size_t i = 0; i < digits.size(); ++i) {
            uint8_t digit1 = digits[i];
            uint8_t digit2 = (i < other.digits.size()) ? other.digits[i] : 0;

            int diff = digit1 - digit2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result.digits.push_back(diff);
        }

        result.removeLeadingZeros();
        return result;
    }

    bool operator<(const UnsignedBigInteger& other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() < other.digits.size();
        }
        for (auto it1 = digits.rbegin(), it2 = other.digits.rbegin(); it1 != digits.rend(); ++it1, ++it2) {
            if (*it1 != *it2) {
                return *it1 < *it2;
            }
        }
        return false;
    }

    explicit operator int() const {
        int result = 0;
        int multiplier = 1;

        for (size_t i = 0; i < digits.size(); ++i) {
            if (result > (INT_MAX - digits[i]) / multiplier) {
                throw std::overflow_error("Narrowing conversion would occur");
            }
            result += digits[i] * multiplier;
            multiplier *= 10;
        }

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const UnsignedBigInteger& number) {
        for (auto it = number.digits.rbegin(); it != number.digits.rend(); ++it) {
            os << static_cast<int>(*it);
        }
        return os;
    }
};

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    UnsignedBigInteger num1("12345678901234567890");
    UnsignedBigInteger num2("98765432109876543210");

    UnsignedBigInteger sum = num1 + num2;
    UnsignedBigInteger diff = num2 - num1;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;

    try {
        int narrowed = static_cast<int>(num1);
        std::cout << "Narrowed to int: " << narrowed << std::endl;
    } catch (const std::overflow_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}