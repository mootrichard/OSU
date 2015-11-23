CXX = g++

all: fight

debug: main.o combat.o creature.o tournament.o
	$(CXX) -ggdb main.o combat.o creature.o tournament.o -o debug

combat.o: combat.cpp
	$(CXX) -c combat.cpp

creature.o: creature.cpp
	$(CXX) -c creature.cpp

tournament.o: tournament.cpp
	$(CXX) -c tournament.cpp
	
main.o: main.cpp
	$(CXX) -c main.cpp

fight: main.o combat.o creature.o tournament.o
	$(CXX) main.o combat.o creature.o tournament.o -o fight
	
clean:
	rm *.o fight debug