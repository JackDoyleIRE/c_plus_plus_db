#include "storage.h"
#include <fstream>
#include <iostream>

Storage::Storage(const std::string& filename) : filename(filename) {
    // Open the file to ensure it exists
    std::ofstream file(filename, std::ios::app);
}

void Storage::insertRow(const std::string& data) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << data << std::endl;
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }
}

std::string Storage::readRow(int rowId) {
    std::ifstream file(filename);
    std::string line;
    int currentId = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (currentId == rowId) {
                return line;
            }
            currentId++;
        }
    } else {
        std::cerr << "Unable to open file for reading" << std::endl;
    }

    return "";
}
