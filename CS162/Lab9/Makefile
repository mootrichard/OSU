CXX = g++

all: linechecker

linechecker: linechecker.o main.o
	$(CXX) linechecker.o main.o -o linechecker

main.o: main.cpp
	$(CXX) -c main.cpp

linechecker.o: linechecker.cpp
	$(CXX) -c linechecker.cpp

clean:
	rm *.o linechecker
