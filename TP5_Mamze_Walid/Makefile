# Compiler
CXX = g++

# Compiler flags
CXXFLAGS =  -std=c++17

# Source files
SRCS = exo1.cpp exo2.cpp exo3.cpp exo4.cpp exo5.cpp exo6.cpp

# Executables (removes .cpp and replaces with no extension)
EXECS = $(SRCS:.cpp=)

# Default target (compiles all executables)
all: $(EXECS)

# Rule to compile each .cpp into an executable
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean up compiled files
clean:
	rm -f $(EXECS)
