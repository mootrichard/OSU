/**
 * Author: Richard Moot
 * Date: 11-25-2015
 * Description: A class for simulating two different line structures. 
 *  A single line queue and a multi-queue structure for handling incoming
 *  customers. Ultimately it will help simluate which is more efficient.
 */
#include "linechecker.hpp"

/**
 * @brief Constructor for Queue Line Simluator
 * @details Initializes private variables and prompts for user entered variables for the length
 *  of the simluation along with the number of servers
 */
LineChecker::LineChecker(){
  nextQueue = 0;
  clicks = 0;
  multiQueueTotal = 0;
  singleQueueTotal = 0;
  std::cout << "Enter number of servers: ";
  std::cin >> this->numOfQueues;
  std::cout << std::endl;
  std::cout << "Enter number of cycles: ";
  std::cin >> this->simLength;
  std::cout << std::endl;
  createQueues(numOfQueues);
}

/**
 * @brief Creates the multi-line queues
 * @details Pushes pointers to queues into a vector to manage all of the lines for incoming patrons
 * 
 * @param int numOfQueues: Number of queues/servers to be generated
 */
void LineChecker::createQueues(unsigned int numOfQueues){
  for(int i = 0; i < numOfQueues; i++){
    std::queue<int> *temp = new std::queue<int>;
    vectorOfQueues.push_back(temp);
  }
}

/**
 * @brief Displays the Multi-Queue line #'s'
 * @details Displays the amount of people that are waiting in each line of the multiple line simulation
 */
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

/**
 * @brief Shows total patrons waiting in single line
 */
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

/**
 * @brief Adds people into each line in succession
 * @details Inserts incoming patrons into each line and makes sure they are going 
 *   going into the shortest line available
 * 
 * @param person The person that is being inserted to the line (can be any number since it is irrelevant)
 */
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

/**
 * @brief Pushes person into the single queue
 * 
 * @param person The person that is being inserted to the line (can be any number since it is irrelevant)
 */
void LineChecker::addToSingleQueue(int person){
  singleQueue.push(person);
}

/**
 * @brief Queues arriving people into each line
 * @details Generates the number of people that are arriving based on number of queues to simluate
 *   a busy morning then tapering off half-way through the simulation
 */
void LineChecker::queuePeople(){
  unsigned int newPeople = 0;
  if(clicks < (simLength/2)){
    unsigned int random = rand()% numOfQueues + clicks;
    newPeople =  numOfQueues + random;
  }else{
    unsigned int random = rand()% (numOfQueues - 1);
    newPeople = random;
  }
  std::cout << "\n" << newPeople << " have arrived" << std::endl;
  for(unsigned int i = 0; i < newPeople; i++){
    addToMultiQueues(1);
    multiQueueTotal++;
    addToSingleQueue(1);
  }
}

/**
 * @brief Removes people from both lines
 * @details Removes people from both lines based on the number of server there are
 */
void LineChecker::removePeople(){
  for(unsigned int i = 0; i < vectorOfQueues.size(); i++){
    if(!vectorOfQueues[i]->empty()){
      vectorOfQueues[i]->pop();
      multiQueueTotal--;
    }
    if(!singleQueue.empty()){
      singleQueue.pop();
    }
  }
}

/**
 * @brief Runs simluation for both Queues simultaneously
 * @details Runs a simlation for both queues based on the user defined inputs.
 *   This will continue to run until the single queue is empty (which happens to be both queues)
 *   Otherwise it will terminate once the single queues is completely empty.
 */
void LineChecker::simulate(){
  bool firstRun = true;
  for(unsigned int i = 0; i < simLength; i++){
    clicks++;
    queuePeople();
    removePeople();
    displaySingleQueue();
    displayMultiQueue();
    waitTime();
    if(singleQueue.size() == 0){break;}
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
/**
 * @brief Outputs the wait time for both lines
 */
void LineChecker::waitTime(){
  std::cout << "Single Queue wait time = " << singleQueue.size() * 5 << " minutes" << std::endl;
  std::cout << "Multi Queue wait time = " << multiQueueTotal*5 << " minutes" << std::endl;
}
