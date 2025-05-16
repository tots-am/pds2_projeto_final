# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++11
# Source files
SRCS = main.cpp
# Executable name
EXEC = flappyBird

# Default target
all: $(EXEC)

# Compile the source files
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

# Clean build files
clean:
	rm -f $(EXEC)