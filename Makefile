# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Executable targets
FUZZER_TARGET = fuzzer
MAIN_TARGET = main

# Source files
FUZZER_SRC = Fuzzer.cpp
MAIN_SRCS = main_ex1.cpp Lexer.cpp Parser.cpp

# Object files
FUZZER_OBJ = $(FUZZER_SRC:.cpp=.o)
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)

# Default target to build everything
all: $(FUZZER_TARGET) $(MAIN_TARGET)

# Build the Fuzzer executable
$(FUZZER_TARGET): $(FUZZER_OBJ)
	$(CXX) $(CXXFLAGS) -o $(FUZZER_TARGET) $(FUZZER_OBJ)

# Build the main executable (depends on Fuzzer)
$(MAIN_TARGET): $(MAIN_OBJS) $(FUZZER_TARGET)
	$(CXX) $(CXXFLAGS) -o $(MAIN_TARGET) $(MAIN_OBJS)

# Run the executables in order: first fuzzer, then main
run: all
	./$(FUZZER_TARGET) && ./$(MAIN_TARGET)

# Compile individual source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean generated files
clean:
	rm -f $(FUZZER_OBJ) $(MAIN_OBJS) $(FUZZER_TARGET) $(MAIN_TARGET)
