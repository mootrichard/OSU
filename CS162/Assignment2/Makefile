# Author:			Richard Moot
# Date: 			10-25-2015
# Description:	This is the Makefile for our Shopping List Application
CXX		= g++

all: shoppingList

shoppingList: item.o list.o main.o
	$(CXX) -o shoppingList item.o list.o main.o

item.o: item.cpp
	$(CXX) -c item.cpp

list.o: list.cpp
	$(CXX) -c list.cpp

main.o: main.cpp
	$(CXX) -c main.cpp

clean:
	rm *.o shoppingList