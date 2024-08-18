<a name="readme-top"></a>

<!-- PROJECT LOGO -->
<br />
<div align="center">
<a href="https://github.com/JackDoyleIRE/c_plus_plus_db">
  <img src="/images/db_logo.png" alt="Logo" width="80" height="80">
</a>
<h3 align="center">C++ Database Engine</h3>
  <p align="center">
    A simple database engine built in C++ to explore modern database architectures and deepen understanding of the language.
    <br />
    <a href="https://github.com/JackDoyleIRE/c_plus_plus_db"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/JackDoyleIRE/c_plus_plus_db">View Demo</a>
    ·
    <a href="https://github.com/JackDoyleIRE/c_plus_plus_db/issues">Report Bug</a>
    ·
    <a href="https://github.com/JackDoyleIRE/c_plus_plus_db/issues">Request Feature</a>
  </p>
</div>
<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
  </ol>
</details>
<!-- ABOUT THE PROJECT -->
About The Project
This project is a basic database engine implemented in C++ with the goal of learning the language while diving into modern data system architectures. The engine allows for table creation, row insertion, data storage in a file, and other database operations. It demonstrates how data can be stored in memory and persisted to a file (e.g., data.db). This project is a stepping stone to understanding database internals such as schema storage, indexing, and query processing.

Project Structure
python
Copy code
.
├── Makefile             # Instructions for compiling the project
├── bin/                 # Contains the compiled binary
├── data.db              # Data file where table schema and rows are stored
├── input.txt            # Input file for inserting rows into the database
├── obj/                 # Directory for compiled object files
│   ├── main.o
│   └── storage.o
├── src/                 # Source files for the database engine
│   ├── main.cpp         # Entry point for the program
│   ├── storage.cpp      # Implementation of the Storage class
│   └── storage.h        # Header file for the Storage class
├── test.db              # Test database file
└── tests/               # Directory for tests
    └── test_storage.cpp # Unit tests for the Storage class
<p align="right">(<a href="#readme-top">back to top</a>)</p>
Built With
<p align="right">(<a href="#readme-top">back to top</a>)</p>
<!-- GETTING STARTED -->
Getting Started
To set up the project locally, follow these steps.

Prerequisites
Make sure you have the following installed on your machine:

C++17 or later
GNU Make
Installation
Clone the repo
sh
Copy code
git clone https://github.com/JackDoyleIRE/c_plus_plus_db.git
Navigate to the project directory
sh
Copy code
cd c_plus_plus_db
Compile the project using Make
sh
Copy code
make
Run the compiled binary
sh
Copy code
./bin/c_plus_plus_db
<p align="right">(<a href="#readme-top">back to top</a>)</p>
<!-- USAGE EXAMPLES -->
Usage
Once the project is compiled and running, you can use commands like:

db show: Display all rows in the People table.
db total: Show the total number of rows in the People table.
db insert: Insert rows into the People table from input.txt.
db delete: Clear all data from the People table.
Example of inserting rows from input.txt:

sql
Copy code
$ ./bin/c_plus_plus_db
Welcome to c++ db!
What would you like to do? (db show, db total, db insert, db delete, quit)
> db insert
3 row(s) inserted from input.txt into table People
<p align="right">(<a href="#readme-top">back to top</a>)</p>
<!-- ROADMAP -->
Roadmap
 Basic table creation and row insertion
 Persistent data storage in a file
 Add indexing support
 Add query processing functionality (e.g., SELECT, WHERE clauses)
 Implement transaction support
See the open issues for a full list of proposed features and known issues.

<p align="right">(<a href="#readme-top">back to top</a>)</p>
<!-- LICENSE -->
License
Distributed under the MIT License.

<p align="right">(<a href="#readme-top">back to top</a>)</p>