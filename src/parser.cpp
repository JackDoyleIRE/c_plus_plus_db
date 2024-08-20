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
void SQLParser::parseAndExecute(const std::string& sql) {
    std::vector<std::string> tokens = tokenize(sql);

    if (tokens.empty()) {
        std::cerr << "Error: Empty SQL command.\n";
        return;
    }

    // Handle CREATE DATABASE command
    if (tokens.size() >= 3 && tokens[0] == "CREATE" && tokens[1] == "DATABASE") {
        handleCreateDatabase(tokens);
    } else {
        std::cerr << "Error: Unsupported SQL command.\n";
    }
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