#include "storage.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

void insertRowsFromFile(Storage& storage, const string& filename) {
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

            // Insert the row using insertRow function
            if (!rowData.empty()) {
                totalRowsInserted += storage.insertRow(rowData);
            }
        }
        file.close();
    } else {
        cout << "Error opening input file.\n";
    }

    cout << totalRowsInserted << " row(s) inserted from " << filename << "\n";
}

void deleteAllData(Storage& storage, const std::string& filename) {
    // Count the rows in the file before deleting
    int rowsBeforeDelete = storage.getTotalRows();

    // Open the file in truncate mode to clear its content
    ofstream file(filename, std::ios::trunc);  // Truncate the file to clear its content
    if (file.is_open()) {
        file.close();

        // Clear the in-memory table
        storage.clearTable();

        cout << "All data has been deleted from " << filename << "\n";
        cout << rowsBeforeDelete << " row(s) were deleted.\n";
    } else {
        cout << "Error deleting data from " << filename << "\n";
    }
}

int main() {
    Storage storage("data.db");

    // Welcome message
    cout << "Welcome to c++ db!\n";

    while (true) {
        cout << "What would you like to do? (db show, db total, db insert, db delete, quit)\n";

        // Command input
        string command;
        getline(cin, command);

        if (command == "db show") {
            storage.showAllRows();  // Show all rows if user inputs "db show"
        } 
        else if (command == "db total") {
            int totalRows = storage.getTotalRows();
            cout << "Total rows: " << totalRows << "\n";  // Show total rows if user inputs "db total"
        } 
        else if (command == "db insert") {
            insertRowsFromFile(storage, "input.txt");  // Insert rows from input.txt
        } 
        else if (command == "db delete") {
            cout << "This will delete all data, are you sure you want to continue? Type 'yes' if you want to continue: ";
            string confirmation;
            getline(cin, confirmation);

            if (confirmation == "yes") {
                deleteAllData(storage, "data.db");  // Pass the storage object and filename
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
