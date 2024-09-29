#ifndef SQL_PARSER_H
#define SQL_PARSER_H

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include "storage.h"

class SQLParser {
public:
    SQLParser(Storage& storage) : storage(storage) {}

    // Parse an SQL command and execute it
    bool parseAndExecute(const std::string& sql);

private:
    Storage& storage;

    // Helper function to trim whitespace
    std::string trim(const std::string& str);

    // Tokenize the SQL string
    std::vector<std::string> tokenize(const std::string& sql);

    // Parse and execute the CREATE DATABASE command
    void handleCreateDatabase(const std::vector<std::string>& tokens);
};

#endif