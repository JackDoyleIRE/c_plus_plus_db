#include "storage.h"
#include <fstream>
#include <iostream>

using std::ofstream;
using std::ios;

Storage::Storage(const std::string& filename) : filename(filename) {
    // Load existing rows from the file into the in-memory table
    // Load existing rows from the file into the in-memory table
    std::ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> rowData;
            string cell;
            // Split the line into columns (assuming space-separated values for simplicity)
            for (char c : line) {
                if (c == ' ') {
                    if (!cell.empty()) {
                        rowData.push_back(cell);
                        cell.clear();
                    }
                } else {
                    cell += c;
                }
            }
            if (!cell.empty()) {
                rowData.push_back(cell);
            }

            // Add row to the in-memory table
            if (!rowData.empty()) {
                table.push_back(rowData);
            }
        }
        file.close();
    }
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

// New method to get the total number of rows
int Storage::getTotalRows() const {
    return table.size();  // Return the number of rows in the in-memory table

}

void Storage::clearTable() {
    table.clear();  // Clear the in-memory table
}


