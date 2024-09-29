#include "parser.h"

using std::string;

// Trim whitespace from a string
std::string SQLParser::trim(const std::string& str) {
    std::string result = str;
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), result.end());
    return result;
}

// Tokenize the SQL string
std::vector<std::string> SQLParser::tokenize(const std::string& sql) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(sql);
    while (tokenStream >> token) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

// Parse and execute the SQL command
bool SQLParser::parseAndExecute(const std::string& sql) {
    if (sql.find("CREATE DATABASE") == 0) {
        std::string dbName = sql.substr(16);  // Extract the database name
        if (!dbName.empty()) {
            storage.createDatabase(dbName);
            return true;
        }
        return false;
    } else if (sql == "SHOW DATABASES") {
        storage.showDatabases();
        return true;
    } else if (sql.find("USE DATABASE") == 0) {
        std::string dbName = sql.substr(12);
        if (!dbName.empty()) {
            storage.useDatabase(dbName);
            return true;
        }
        return false;
    }

    // If the command is not recognized
    return false;
}

// Handle the CREATE DATABASE command
void SQLParser::handleCreateDatabase(const std::vector<std::string>& tokens) {
    if (tokens.size() == 3) {
        std::string databaseName = tokens[2];
        storage.createDatabase(databaseName);
    } else {
        std::cerr << "Error: Invalid CREATE DATABASE syntax.\n";
    }
}