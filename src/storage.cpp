#include "storage.h"
#include <fstream>
#include <iostream>

using std::ofstream;
using std::ios;

Storage::Storage(const std::string& filename) : filename(filename) {
    // Optionally load existing data from the file here
}

void Storage::insertRow(const std::vector<std::string>& rowData) {
    table.push_back(rowData);  // Add the row to the table

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

    std::cout << "1 row inserted\n";  // Output success message
}

