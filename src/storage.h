#ifndef STORAGE_H
#define STORAGE_H

#include <string>

class Storage {
public:
    Storage(const std::string& filename);
    void insertRow(const std::string& data);
    std::string readRow(int rowId);

private:
    std::string filename;
};

#endif
