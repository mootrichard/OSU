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
#include <list>
#include <iostream>
#include <cstdlib>

class LineChecker {
  public:
    LineChecker();
    void displayMultiQueue();
    void displaySingleQueue();
    void createQueues(unsigned int numOfQueues);
    void addToMultiQueues(int person);
    void addToSingleQueue(int person);
  private:
    unsigned int numOfQueues;
    std::vector<std::queue<int>*> vectorOfQueues;
    std::queue<int> singleQueue;
};

#endif // LINECHECKER_HPP
