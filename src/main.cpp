#include "storage.h"
#include <iostream>
#include <fstream>
#include "parser.h"

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
    // Initialize storage and SQL parser
    Storage storage("data.db");
    SQLParser sqlParser(storage);  // Pass the storage to the SQL parser

    // Welcome message and initial instructions
    cout << "Welcome to the C++ DB!\n";
    cout << "You can run SQL commands such as:\n";
    cout << "  - SHOW DATABASES\n";
    cout << "  - USE DATABASE your_database_name\n";
    cout << "  - SHOW TABLES\n";
    cout << "Type 'quit' to exit.\n\n";

    // Main loop to process user commands
    while (true) {
        cout << "> ";
        string command;
        getline(cin, command);

        // Check for quit command
        if (command == "quit") {
            cout << "Exiting the program...\n";
            break;
        }

        // Pass the command to the SQL parser for execution
        if (!sqlParser.parseAndExecute(command)) {
            cout << "Invalid or unsupported SQL command.\n";
        }
    }

    return 0;
}

