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

    // Ask the user what they want to do next
    cout << "What do you want to do? Type 'db show' to show all rows or 'exit' to quit: ";
    string command;
    while (true) {
        getline(cin, command);

        if (command == "db show") {
            storage.showAllRows();  // Show all rows in the database
        } else if (command == "exit") {
            break;  // Exit the program
        } else {
            cout << "Unknown command. Type 'db show' to show all rows or 'exit' to quit: ";
        }
    }

    return 0;
}
