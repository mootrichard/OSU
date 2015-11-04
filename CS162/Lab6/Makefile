CXX = g++

all:testing

testing: main.o linkedlist.o
	$(CXX) main.o linkedlist.o -o testing

main.o: main.cpp
	$(CXX) -c main.cpp

linkedlist.o: linkedlist.cpp
	$(CXX) -c linkedlist.cpp

clean:
	rm *.o testing