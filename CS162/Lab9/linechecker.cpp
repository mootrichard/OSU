/**
 * Author: Richard Moot
 * Date: 11-25-2015
 * Description: A class for simulating two different line structures. 
 *  A single line queue and a multi-queue structure for handling incoming
 *  customers. Ultimately it will help simluate which is more efficient.
 */
#include "linechecker.hpp"

LineChecker::LineChecker(){
  nextQueue = 0;
  clicks = 0;
  std::cout << "Enter number of servers: ";
  std::cin >> this->numOfQueues;
  std::cout << std::endl;
  std::cout << "Enter number of cycles: ";
  std::cin >> this->simLength;
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
        std::cout << vectorOfQueues[i]->size() << " ";
        std::cout << std::endl;
      }else{
      std::cout << std::endl;
    }
  }
}

void LineChecker::displaySingleQueue(){
  std::cout << "\t1 Queue with " << numOfQueues << " servers" <<  std::endl;
  std::cout << "Line\t    # of People in Line" << std::endl;
  std::cout << "1\t||  ";
  if(singleQueue.size() != 0){
    std::cout << singleQueue.size() << std::endl;
  }else{
    std::cout << std::endl;
  }
}

void LineChecker::addToMultiQueues(int person){
  if(nextQueue == numOfQueues){
    nextQueue = 0;
    vectorOfQueues[nextQueue]->push(person);
    nextQueue++;
  }else{
    vectorOfQueues[nextQueue]->push(person);
    nextQueue++;
  }
}

void LineChecker::addToSingleQueue(int person){
  singleQueue.push(person);
}

void LineChecker::queuePeople(){
  unsigned int random = rand()% numOfQueues;
  unsigned int newPeople = 0;
  if(clicks < (simLength/2)){
    newPeople = random + (numOfQueues * clicks);
  }else{
    newPeople = random + (simLength - clicks);
  }
  std::cout << "\n" << newPeople << " have arrived" << std::endl;
  for(unsigned int i = 0; i < newPeople; i++){
    addToMultiQueues(1);
    addToSingleQueue(1);
  }
}

void LineChecker::removePeople(){
  for(unsigned int i = 0; i < vectorOfQueues.size(); i++){
    if(!vectorOfQueues[i]->empty()){
      vectorOfQueues[i]->pop();
    }
    if(!singleQueue.empty()){
      singleQueue.pop();
    }
  }
}

void LineChecker::simulate(){
  bool firstRun = true;
  for(unsigned int i = 0; i < simLength; i++){
    clicks++;
    queuePeople();
    removePeople();
    displaySingleQueue();
    displayMultiQueue();
    std::cout << "Press enter to continue..." << std::endl;
    if(firstRun){
      std::cin.ignore();
      firstRun = false;
    }
    std::cin.get();
  }
  while(singleQueue.size() > 0){
    removePeople();
    displaySingleQueue();
    displayMultiQueue();
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.get();
  }
}