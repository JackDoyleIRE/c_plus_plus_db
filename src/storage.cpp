#include "storage.h"
#include <fstream>
#include <iostream>
#include <sstream>  // For splitting strings

using std::ofstream;
using std::ifstream;
using std::ios;
using std::vector;
using std::string;
using std::cout;
using std::cerr;

// Storage constructor
Storage::Storage(const std::string& filename) : filename(filename) {}

// Create a new table with columns (schema)
void Storage::createTable(const std::string& tableName, const vector<Column>& columns) {
    if (tables.find(tableName) == tables.end()) {
        tables[tableName] = Table(tableName, columns);  // Create a new table if not exists
        cout << "Table \"" << tableName << "\" created.\n";
    } else {
        cout << "Table \"" << tableName << "\" already exists.\n";
    }
}

// Insert a row into a specific table
void Storage::insertRow(const std::string& tableName, const vector<string>& rowData) {
    if (tables.find(tableName) != tables.end()) {
        tables[tableName].insertRow(rowData);  // Insert row into the specified table
        // Optionally, persist the new row to the file
        ofstream file(filename, ios::app);  // Append mode
        if (file.is_open()) {
            for (const auto& data : rowData) {
                file << data << " ";  // Write row data to the file
            }
            file << "\n";
            file.close();
        } else {
            cerr << "Error opening file for writing\n";
        }
    } else {
        cerr << "Table \"" << tableName << "\" not found.\n";
    }
}

// Show all rows from a specific table
void Storage::showTable(const std::string& tableName) const {
    if (tables.find(tableName) != tables.end()) {
        tables.at(tableName).showAllRows();  // Show rows of the specified table
    } else {
        cerr << "Table \"" << tableName << "\" not found.\n";
    }
}

// Get the total number of rows in a specific table
int Storage::getTotalRows(const std::string& tableName) const {
    if (tables.find(tableName) != tables.end()) {
        return tables.at(tableName).getTotalRows();  // Return total rows in the specified table
    } else {
        cerr << "Table \"" << tableName << "\" not found.\n";
        return 0;
    }
}

// Clear the data of a specific table
void Storage::clearTable(const std::string& tableName) {
    if (tables.find(tableName) != tables.end()) {
        tables[tableName].clearTable();  // Clear rows in the specified table
        ofstream file(filename, ios::trunc);  // Clear the file
        file.close();
        cout << "Table \"" << tableName << "\" cleared.\n";
    } else {
        cerr << "Table \"" << tableName << "\" not found.\n";
    }
}

// Table methods

// Insert a row into the table
void Table::insertRow(const vector<string>& rowData) {
    if (rowData.size() == schema.size()) {
        rows.push_back(rowData);
        // Output for debugging
        cout << "Inserted row into " << tableName << ": ";
        for (const auto& data : rowData) {
            cout << data << " ";
        }
        cout << "\n";
    } else {
        cerr << "Row does not match the table schema.\n";
    }
}

// Show all rows in the table with the column names
void Table::showAllRows() const {
    cout << "Table \"" << tableName << "\":\n";
    // Print column names
    for (const auto& col : schema) {
        cout << col.name << " ";
    }
    cout << "\n";

    // Print all rows
    for (const auto& row : rows) {
        for (const auto& data : row) {
            cout << data << " ";
        }
        cout << "\n";
    }
}

// Clear all rows in the table
void Table::clearTable() {
    rows.clear();
}


