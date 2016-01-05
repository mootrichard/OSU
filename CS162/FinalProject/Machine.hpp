/**
*  Author: Richard Moot
*  Date: Decemeber 8, 2015
*  Description: Machine is our class that all of our spaces/room will inherit from, so the implementations
 *  here are intentionally generalized since they will all be inherited
*/
#ifndef MACHINE_HPP
#define MACHINE_HPP
#include <string>
#include <iostream>
#include "Player.hpp"

class Machine {
  protected:
    std::string type;
    Machine *nodeOne;
    Machine *nodeTwo;
    Machine *nodeThree;
    Machine *nodeFour;
    std::string greeting;
    
  public:
    Machine();
    virtual std::string getType();
    virtual std::string getGreeting();
  	virtual void special() = 0;
  	virtual void displayMenu() = 0;
  	void showNodes();
  	void playerSelect(unsigned int choice, Player* hacker);
  	virtual void actionOne(Player* hacker) = 0;
  	virtual void actionTwo(Player* hacker) = 0;
  	void setNodes(Machine *one, Machine *two, Machine *three, Machine *four);
  	Machine* nodeSelect(unsigned int choice);
};

#endif // MACHINE_HPP
