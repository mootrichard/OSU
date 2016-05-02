CXX = g++

all: chatserve

chatserve.o: chatserve.cpp
	$(CXX) -c chatserve.cpp

chatserve: chatserve.o
	$(CXX) chatserve.o -o chatserve

clean:
	rm *.o chatserve
