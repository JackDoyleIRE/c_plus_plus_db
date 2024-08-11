#include "storage.h"
#include <iostream>

int main() {
    Storage storage("data.db");

    // Example: Insert a row
    storage.insertRow("This is a test row");

    // Example: Read a row
    std::string row = storage.readRow(0);
    std::cout << "Read row: " << row << std::endl;

    return 0;
}

