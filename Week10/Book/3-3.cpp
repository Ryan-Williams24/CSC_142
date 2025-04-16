#include <iostream>

struct Element {
    int operating_number;
    Element* next;
    Element* previous; // Adding the previous pointer for doubly linked list

    Element(int num) : operating_number(num), next(nullptr), previous(nullptr) {}

    void insert_before(int new_value) {
        Element* new_elem = new Element(new_value);
        new_elem->next = this;
        new_elem->previous = this->previous;

        if (this->previous) {
            this->previous->next = new_elem;
        }
        this->previous = new_elem;
    }
};

void traverse_list(Element* head) {
    Element* current = head;
    while (current != nullptr) {
        std::cout << current->operating_number << std::endl;
        current = current->next;
    }
    std::cout << "Back to front traversal:\n";
    current = head;
    while (current != nullptr) {
        std::cout << current->operating_number << std::endl;
        current = current->previous;
    }
}

int main() {
    Element* head = new Element(1);
    head->next = new Element(2);
    head->next->previous = head;

    head->next->insert_before(3);  // Insert 3 before 2

    traverse_list(head);

    return 0;
}