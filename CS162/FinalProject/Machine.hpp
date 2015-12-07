/**
 *  Author: Richard Moot
 *  Date: Decemeber 7, 2015
 *  Description: 
 */
#ifndef MACHINE_HPP
#define MACHINE_HPP
#include <string>

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
	virtual void displayMove() = 0;
    virtual void setNodeOne(Machine *m) = 0;
    virtual void setNodeTwo(Machine *m) = 0;
    virtual void setNodeThree(Machine *m) = 0;
    virtual void setNodeFour(Machine *m) = 0;
	//virtual void menu();

};

#endif // MACHINE_HPP
