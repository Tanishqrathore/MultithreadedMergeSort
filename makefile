# Compiler to use
CXX = g++

# Compiler flags:
# -Wall: Enable all common warnings
# -Wextra: Enable extra warnings
# -std=c++17: Use C++17 standard (adjust if you need a different standard)
# -pthread: Link with the POSIX threads library
# -g: Include debugging information (useful for debugging, can be removed for release)
CXXFLAGS = -Wall -Wextra -std=c++17 -pthread -g

# Name of the final executable
# We'll place the executable inside src/app/
TARGET_DIR = src/app
TARGET_NAME = run
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

# Source files (relative to the Makefile's location)
SRCS = $(TARGET_DIR)/main.cpp \
       sorting/mergeSort.cpp \
       sorting/parallelMergeSort.cpp

# Object files: These will be created in the same directory as their source files by default
# This means main.o will be in src/app/, and mergeSort.o/parallelMergeSort.o in sorting/
OBJS = $(SRCS:.cpp=.o)

# Default target: builds the executable
all: $(TARGET_DIR) $(TARGET)

# Ensure the target directory exists before compiling
$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Rule to compile .cpp files into .o files
# This pattern rule handles the relative paths correctly
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Phony targets: these are not actual files, but commands
.PHONY: all clean run

# Clean target: removes compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Run target: compiles (if necessary) and runs the executable
run: all
	./$(TARGET) $(ARGS)