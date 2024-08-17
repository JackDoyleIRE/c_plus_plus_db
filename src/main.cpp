#include "storage.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

// Insert rows from a file into a specified table
void insertRowsFromFile(Storage& storage, const string& tableName, const string& filename) {
    ifstream file(filename);
    string line;
    int totalRowsInserted = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> rowData;
            string cell;
            // Split the line into columns (space-separated values)
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

            // Insert the row into the specified table
            if (!rowData.empty()) {
                storage.insertRow(tableName, rowData);
                totalRowsInserted++;
            }
        }
        file.close();
    } else {
        cout << "Error opening input file.\n";
    }

    cout << totalRowsInserted << " row(s) inserted from " << filename << " into table " << tableName << "\n";
}

// Delete all data from the table
void deleteAllData(Storage& storage, const string& tableName) {
    // Count the rows before deleting
    int rowsBeforeDelete = storage.getTotalRows(tableName);

    // Clear the table
    storage.clearTable(tableName);

    cout << "All data from table \"" << tableName << "\" has been deleted.\n";
    cout << rowsBeforeDelete << " row(s) were deleted.\n";
}

int main() {
    Storage storage("data.db");

    // Define a table schema
    vector<Column> columns = {
        {"FirstName", "TEXT"},
        {"LastName", "TEXT"},
        {"Age", "INTEGER"}
    };

    // Create a table
    string tableName = "People";
    storage.createTable(tableName, columns);

    // Welcome message
    cout << "Welcome to c++ db!\n";

    while (true) {
        cout << "What would you like to do? (db show, db total, db insert, db delete, quit)\n";
        cout << "> ";
        // Command input
        string command;
        getline(cin, command);

        if (command == "db show") {
            storage.showTable(tableName);  // Show all rows in the "People" table
        } 
        else if (command == "db total") {
            int totalRows = storage.getTotalRows(tableName);
            cout << "Total rows in table \"" << tableName << "\": " << totalRows << "\n";
        } 
        else if (command == "db insert") {
            insertRowsFromFile(storage, tableName, "input.txt");  // Insert rows into the "People" table from input.txt
        } 
        else if (command == "db delete") {
            cout << "This will delete all data from table \"" << tableName << "\", are you sure you want to continue? Type 'yes' if you want to continue: ";
            string confirmation;
            getline(cin, confirmation);

            if (confirmation == "yes") {
                deleteAllData(storage, tableName);  // Delete all data from the "People" table
            } else {
                cout << "Aborted deletion.\n";
            }
        }
        else if (command == "quit") {
            cout << "Exiting the program...\n";
            break;  // Exit the loop and end the program
        } 
        else {
            cout << "Unknown command\n";
        }
    }

    return 0;
}

