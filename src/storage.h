#ifndef STORAGE_H
#define STORAGE_H

#include <string>

using std::string;

class Storage {
public:
    Storage(const string& filename);
    void insertRow(const string& data);
    string readRow(int rowId);

private:
    string filename;
};

#endif
