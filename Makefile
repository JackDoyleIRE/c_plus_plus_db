# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests

# Output binary
TARGET = $(BIN_DIR)/c_plus_plus_db

# Source and object files
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/storage.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Build the final executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build and run tests
test: $(TEST_DIR)/test_storage.cpp $(OBJ_DIR)/storage.o
	$(CXX) $(CXXFLAGS) -o $(TEST_DIR)/test_storage $(TEST_DIR)/test_storage.cpp $(OBJ_DIR)/storage.o
	$(TEST_DIR)/test_storage

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(TEST_DIR)/test_storage

# Rebuild everything
rebuild: clean all

