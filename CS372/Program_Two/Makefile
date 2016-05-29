CXX = g++

all: ftpserver

server.o: server.cpp
	$(CXX) -c server.cpp

ftpserver: server.o
	$(CXX) server.o -o ftpserver

clean:
	rm *.o ftpserver
