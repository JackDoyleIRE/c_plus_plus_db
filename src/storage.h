#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Storage {
public:
    Storage(const string& filename);

    void insertRow(const vector<string>& rowdata);
    vector<string> readRow(int rowId) const;

private:
    string filename;
    vector<vector<string>> table;
};

#endif
