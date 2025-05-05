CXX = g++
CXXFLAGS = -std=c++17 -Wall
OBJS = main.o additionneur.o livre.o

all: tp13

tp13: $(OBJS)
	$(CXX) $(CXXFLAGS) -o tp13 $(OBJS)

main.o: main.cpp additionneur.hpp livre.hpp
additionneur.o: additionneur.cpp additionneur.hpp
livre.o: livre.cpp livre.hpp

clean:
	rm -f *.o tp13
