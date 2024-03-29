/**
 * Author: Richard Moot
 * Date: 11-25-2015
 * Description: A class for simulating two different line structures. 
 *  A single line queue and a multi-queue structure for handling incoming
 *  customers. Ultimately it will help simluate which is more efficient.
 */
#ifndef LINECHECKER_HPP
#define LINECHECKER_HPP
#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <cmath>

class LineChecker {
  public:
    LineChecker();
    void displayMultiQueue();
    void displaySingleQueue();
    void createQueues(unsigned int numOfQueues);
    void addToMultiQueues(int person);
    void addToSingleQueue(int person);
    void queuePeople();
    void removePeople();
    void simulate();
    void waitTime();
  private:
    unsigned int numOfQueues;
    unsigned int nextQueue;
    unsigned int simLength;
    unsigned int clicks;
    unsigned int multiQueueTotal;
    unsigned int singleQueueTotal;
    std::vector<std::queue<int>*> vectorOfQueues;
    std::queue<int> singleQueue;
};

#endif // LINECHECKER_HPP
