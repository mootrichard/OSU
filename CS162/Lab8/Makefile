CXX = g++

all: circlequeue

circlequeue: queue.o main.o
  $(CXX) queue.o main.o -o circlequeue

queue.o: queue.cpp
  $(CXX) -c queue.cpp

main.o: main.cpp
  $(CXX) -c main.cpp

clean:
  rm *.o circlequeue