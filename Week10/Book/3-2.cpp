#include <cstdio>

void read_from(char* buffer, size_t size, char* dest, size_t dest_size) {
    if (size > dest_size) {
        printf("Error: Attempt to read beyond buffer size.\n");
        return;
    }
    for (size_t i = 0; i < size; i++) {
        dest[i] = buffer[i];
    }
    dest[size] = '\0'; // Null-terminate
}

void write_to(char* buffer, size_t buffer_size, const char* data, size_t data_size) {
    if (data_size > buffer_size) {
        printf("Error: Attempt to write beyond buffer size.\n");
        return;
    }
    for (size_t i = 0; i < data_size; i++) {
        buffer[i] = data[i];
    }
    buffer[data_size] = '\0'; // Null-terminate
}

int main() {
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char temp[6];

    // Read from lower
    read_from(lower, 5, temp, sizeof(temp));  // Read 5 characters from lower
    printf("Temp after read_from: %s\n", temp);

    // Write to upper
    write_to(upper, 5, "ABCDE", 5); // Write new data to upper
    printf("Upper after write_to: %s\n", upper);

    return 0;
}