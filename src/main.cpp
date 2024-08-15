#include "storage.h"
#include <iostream>

using std::cout;
using std::vector;
using std::string;

int main() {
    Storage storage("data.db");

    // Insert a couple of rows
    storage.insertRow({"John", "Doe", "30"});
    storage.insertRow({"Jane", "Smith", "25"});

    return 0;
}
