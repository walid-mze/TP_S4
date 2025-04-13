all: main  

main: movie.o movies.o main.o
	g++ -std=c++17 movie.o movies.o main.o -o main

movie.o: movie.cpp
	g++ -std=c++17 -c movie.cpp -o movie.o

movies.o: movies.cpp
	g++ -std=c++17 -c movies.cpp -o movies.o

main.o: main.cpp
	g++ -std=c++17 -c main.cpp -o main.o

clean:
	rm -f *.o main.exe