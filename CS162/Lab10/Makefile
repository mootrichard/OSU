CXX = g++

all: timer

timer: main.o
	$(CXX) main.o -o timer

main.o: main.cpp
	$(CXX) -c main.cpp

clean:
	rm *.o timer