/**
 * Author: Richard Moot
 * Date: 11-25-2015
 * Description: A class for simulating two different line structures. 
 *  A single line queue and a multi-queue structure for handling incoming
 *  customers. Ultimately it will help simluate which is more efficient.
 */
#include "linechecker.hpp"

LineChecker::LineChecker(){
  srand(time(NULL));
  std::cout << "Enter number of servers: ";
  std::cin >> numOfQueues;
  std::cout << std::endl;
  createQueues(numOfQueues);
}

void LineChecker::createQueues(unsigned int numOfQueues){
  for(int i = 0; i < numOfQueues; i++){
    std::queue<int> *temp = new std::queue<int>;
    vectorOfQueues.push_back(temp);
  }
}

void LineChecker::displayMultiQueue(){
  std::cout << "\t" << numOfQueues << " Queues with 1 server each" <<  std::endl;
  std::cout << "Line\t    # of People in Line" << std::endl;
  for(int i = 0; i < vectorOfQueues.size(); i++){
    std::cout << i+1 << "\t||  ";
    if(vectorOfQueues[i]->size() != 0){
        std::cout << vectorOfQueues[i]->front() << " ";
        std::cout << std::endl;
      }else{
      std::cout << std::endl;
    }
  }
}

void LineChecker::displaySingleQueue(){
  std::cout << "\t1 Queue with " << numOfQueues << " servers" <<  std::endl;
  std::cout << "Line\t    # of People in Line" << std::endl;
  std::cout << "1\t||  " << singleQueue.size() << std::endl;
}

void LineChecker::addToMultiQueues(int person){

}

void LineChecker::addToSingleQueue(int person){
  singleQueue.push(person);
}