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
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/storage.cpp $(SRC_DIR)/parser.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Build the final executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	@echo "Linking objects to create the executable: $(TARGET)"
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $< to $@"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Add dependencies for header files
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/storage.h $(SRC_DIR)/parser.h
$(OBJ_DIR)/storage.o: $(SRC_DIR)/storage.cpp $(SRC_DIR)/storage.h
$(OBJ_DIR)/parser.o: $(SRC_DIR)/parser.cpp $(SRC_DIR)/parser.h

# Build and run tests
test: $(TEST_DIR)/test_storage.cpp $(OBJ_DIR)/storage.o
	$(CXX) $(CXXFLAGS) -o $(TEST_DIR)/test_storage $(TEST_DIR)/test_storage.cpp $(OBJ_DIR)/storage.o
	$(TEST_DIR)/test_storage

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(TEST_DIR)/test_storage

# Rebuild everything
rebuild: clean all


