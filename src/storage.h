#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Storage {
public:
    Storage(const string& filename);

    int insertRow(const vector<string>& rowData);  // Return number of rows inserted
    vector<string> readRow(int rowId) const;
    void showAllRows() const;  // New method to show all rows
    int getTotalRows() const;  // Add method to return total row count
    void clearTable(); 

private:
    string filename;
    vector<vector<string>> table;
};

#endif
