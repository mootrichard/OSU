CXX = g++

all:testing

warning: main.o linkedlist.o
	$(CXX) -pedantic -Wall -Wextra main.o linkedlist.o -o testing

testing: main.o linkedlist.o
	$(CXX) main.o linkedlist.o -o testing

main.o: main.cpp
	$(CXX) -c main.cpp

linkedlist.o: linkedlist.cpp
	$(CXX) -c linkedlist.cpp

clean:
	rm *.o testing