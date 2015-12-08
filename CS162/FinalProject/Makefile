CXX = g++

all: hackerLand

hackerLand: main.o Machine.o Network.o Player.o Computer.o Server.o Mobile.o
	$(CXX) main.o Machine.o Network.o Player.o -o hackerLand

main.o: main.cpp
	$(CXX) -c main.cpp

Machine.o: Machine.cpp Machine.hpp
	$(CXX) -c Machine.cpp

Network.o: Network.cpp Network.hpp
	$(CXX) -c Network.cpp

Player.o: Player.cpp Player.hpp
	$(CXX) -c Player.cpp

Computer.o: Computer.cpp Computer.hpp
	$(CXX) -c Computer.cpp

Server.o: Server.cpp Server.hpp
	$(CXX) -c Server.cpp

Mobile.o: Mobile.cpp Mobile.hpp
	$(CXX) -c Mobile.cpp

clean:
	rm *.o hackerLand