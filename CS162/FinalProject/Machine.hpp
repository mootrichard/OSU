/**
 *  Author: Richard Moot
 *  Date: Decemeber 7, 2015
 *  Description: 
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
