/**
 *  Author: Richard Moot
 *  Date: Decemeber 7, 2015
 *  Description: 
 */
#ifndef MACHINE_HPP
#define MACHINE_HPP
#include <string>
#include <iostream>

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
	virtual void displayMenu() = 0;
	virtual void playerSelect(unsigned int choice) = 0;
	void setNodes(Machine *one, Machine *two, Machine *three, Machine *four);

};

#endif // MACHINE_HPP
