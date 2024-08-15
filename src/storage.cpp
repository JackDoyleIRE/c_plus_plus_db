#include "storage.h"
#include <fstream>
#include <iostream>

using std::ofstream;
using std::ios;

Storage::Storage(const std::string& filename) : filename(filename) {
    // Optionally load existing data from the file here
}

int Storage::insertRow(const std::vector<std::string>& rowData) {
    table.push_back(rowData);  // Add the row to the table

    // Debug print to check rowData
    std::cout << "Inserting row: ";
    for (const auto& data : rowData) {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    // Optionally write to the file to persist the new row
    ofstream file(filename, ios::app);  // Open the file in append mode
    if (file.is_open()) {
        for (const auto& data : rowData) {
            file << data << " ";  // Write row data to the file
        }
        file << "\n";  // Newline after each row
        file.close();
    } else {
        std::cerr << "Error opening file for writing\n";
    }

    return 1;  // Return 1 row inserted for row count
}

// New function to show all rows from the database
void Storage::showAllRows() const {
    std::ifstream file(filename);
    string line;

    std::cout << "Rows in the database:\n";
    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << "\n";  // Output each line in the file
        }
        file.close();
    } else {
        std::cerr << "Error opening file for reading\n";
    }
}

