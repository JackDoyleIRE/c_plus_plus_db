#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

using std::string;
using std::vector;
using std::map;

// Define a Column structure to represent a column in the schema
struct Column {
    std::string name;  // Column name
    std::string type;  // Data type (e.g., STRING, INTEGER)
};

// Define a Table class to represent a table with a schema and data
class Table {
public:

    Table() = default;
    
    Table(const std::string& name, const std::vector<Column>& columns)
        : tableName(name), schema(columns) {}

    void insertRow(const std::vector<std::string>& rowData);  // Insert a row following the schema
    void showAllRows() const;  // Display all rows with the column names
    int getTotalRows() const { return rows.size(); }  // Return total rows in the table

    void clearTable();

private:
    std::string tableName;
    std::vector<Column> schema;  // Column definitions
    std::vector<std::vector<std::string>> rows;  // Data storage (each row is a vector of strings)
};


// Update the Storage class to manage multiple tables
class Storage {
public:
    Storage(const std::string& filename);

    // DDL commands
    void createTable(const std::string& tableName, const std::vector<Column>& columns);  // Create a table
    void dropTable(const std::string& tableName);  // Drop a specific table
    void createDatabase(const std::string& databaseName);  // Create a database
    void dropDatabase(const std::string& databaseName);  // Drop a database

    // DML commands
    void insertRow(const std::string& tableName, const std::vector<std::string>& rowData);  // Insert a row into a specific table
    void showTable(const std::string& tableName) const;  // Display all rows from a specific table
    int getTotalRows(const std::string& tableName) const;  // Get total rows from a specific table
    void clearTable(const std::string& tableName);  // Clear data from a specific table

private:
    std::string filename;
    std::map<std::string, Table> tables;  // A map to hold multiple tables (key: table name, value: Table object)
};

#endif
