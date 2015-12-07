CXX = g++

all: hackerLand

hackerLand: main.o Machine.o Network.o Player.o Computer.o
	$(CXX) main.o Machine.o Network.o Player.o -o hackerLand

main.o: main.cpp
	$(CXX) -c main.cpp

Machine.o: Machine.cpp Machine.hpp
	$(CXX) -c Machine.cpp

Network.o: Network.cpp Network.hpp
	$(CXX) -c Network.cpp

Player.o: Player.cpp Player.hpp
	$(CXX) -c Player.cpp

Computer.0: Computer.cpp Computer.hpp
	$(CXX) -c Computer.cpp

clean:
	rm *.o hackerLand