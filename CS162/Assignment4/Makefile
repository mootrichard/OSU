CXX = g++

all: fight

fight: main.o combat.o creature.o
	$(CXX) main.o combat.o creature.o -o fight

main.o: main.cpp
	$(CXX) -c main.cpp

combat.o: combat.cpp
	$(CXX) -c combat.cpp

creature.o: creature.cpp
	$(CXX) -c creature.cpp

clean:
	rm *.o fight