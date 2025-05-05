CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGETS = ex1 ex2 ex3

all: $(TARGETS)

ex1: ex1.cpp
	$(CXX) $(CXXFLAGS) -o ex1 ex1.cpp

ex2: ex2.cpp
	$(CXX) $(CXXFLAGS) -o ex2 ex2.cpp

ex3: ex3.cpp
	$(CXX) $(CXXFLAGS) -o ex3 ex3.cpp

clean:
	rm -f $(TARGETS) *.o output.txt report.txt
