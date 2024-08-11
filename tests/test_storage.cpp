#include "../src/storage.h"
#include <iostream>
#include <cassert>

void test_insert_and_read() {
    Storage storage("test.db");

    // Clean up the test file before running the test
    std::remove("test.db");

    // Insert rows
    storage.insertRow("Test row 1");
    storage.insertRow("Test row 2");

    // Read and verify rows
    std::string row1 = storage.readRow(0);
    std::string row2 = storage.readRow(1);

    assert(row1 == "Test row 1");
    assert(row2 == "Test row 2");

    std::cout << "test_insert_and_read passed!" << std::endl;
}

int main() {
    test_insert_and_read();

    // Add more test functions as needed

    return 0;
}
