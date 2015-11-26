#ifndef LINECHECKER_HPP
#define LINECHECKER_HPP
#include <vector>
#include <queue>
#include <list>
#include <iostream>
#include <stdlib>

class LineChecker {
  public:
    LineChecker();
    void displayQueue();
    void createQueues(unsigned int numOfQueues);
  private:
    unsigned int numOfQueues;
    std::vector<std::queue<int>*> vectorOfQueues;
    std::queue<int> singleQueue;
};

#endif // LINECHECKER_HPP
