CXX = g++

all: algorithms

algorithms: FileTest.o main.o
	$(CXX) FileTest.o main.o -o algorithms

FileTest.o: FileTest.cpp
	$(CXX) -c FileTest.cpp

main.o: main.cpp
	$(CXX) -c Main.cpp

clean:
	rm *.o algorithms