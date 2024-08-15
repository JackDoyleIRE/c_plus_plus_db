#include "storage.h"
#include <iostream>

using std::cout;
using std::cin;
using std::vector;
using std::string;
 
int main() {
    Storage storage("data.db");

    int totalRowsInserted = 0;  // Initialize to 0

    // Insert a couple of rows and accumulate the total number of rows inserted
    totalRowsInserted += storage.insertRow({"John", "Doe", "30"});
    totalRowsInserted += storage.insertRow({"Jane", "Smith", "25"});
    totalRowsInserted += storage.insertRow({"Jim-bo", "Jones", "11"});

    // Print total number of rows inserted at the end
    cout << "Total rows inserted: " << totalRowsInserted << " row(s)\n";

    // Ask user for a command
    string command;
    cout << "What do you want to do? (db show, db total)\n";
    getline(cin, command);  // Use getline to read the entire input

    if (command == "db show") {
        storage.showAllRows();  // Show all rows if user inputs "db show"
    } 
    else if (command == "db total") {
        int totalRows = storage.getTotalRows();
        cout << "Total rows: " << totalRows << "\n";  // Show total rows if user inputs "db total"
    } 
    else {
        cout << "Unknown command\n";
    }

    return 0;
}
