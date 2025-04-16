#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>

class Bucket {
public:
    virtual ~Bucket() = default;
};

class SmallBucket : public Bucket {
private:
    std::vector<char> data;

public:
    explicit SmallBucket(size_t size) : data(size) {}
};

class LargeBucket : public Bucket {
private:
    std::unique_ptr<char[]> data;

public:
    explicit LargeBucket(size_t size) {
        if (size > 1024 * 1024) { // 1MB limit
            throw std::bad_alloc();
        }
        data = std::make_unique<char[]>(size);
    }
};

class Heap {
public:
    std::unique_ptr<Bucket> allocate(size_t size) {
        if (size > 1024 * 1024) { // 1MB limit
            throw std::bad_alloc();
        } else if (size > 4096) {
            return std::make_unique<LargeBucket>(size);
        } else {
            return std::make_unique<SmallBucket>(size);
        }
    }
};

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    Heap heap;

    try {
        auto smallBucket = heap.allocate(1024);
        std::cout << "Small bucket allocated successfully.\n";

        auto largeBucket = heap.allocate(8192);
        std::cout << "Large bucket allocated successfully.\n";

        auto tooLargeBucket = heap.allocate(2 * 1024 * 1024); // 2MB
        std::cout << "This should not print.\n";
    } catch (const std::bad_alloc& e) {
        std::cout << "Allocation failed: " << e.what() << "\n";
    }

    return 0;
}