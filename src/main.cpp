#include "storage.h"
#include <iostream>

using std::cout;
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

    return 0;
}
