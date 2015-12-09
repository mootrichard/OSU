/**
*  Author: Richard Moot
*  Date: Decemeber 8, 2015
*  Description: Player class that all of our spaces/room will inherit from, so the implementations
 *  here are intentionally generalized since they will all be inherited
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include <ctime>
#include <iostream>

class Machine;

class Player {
  private:
    std::string name;
    Machine *currentMachine;
    bool twoKeyAuth;
    bool serverPass;
    bool workCompPass;
    bool mobileCode;

  public:
    Player();
    unsigned int getDetectionLevel();
    std::string getName();
    std::string getPassword(unsigned int select);
	void setCurrentMachine(Machine* m);
	Machine* getCurrentMachine();
	void foundServerPass();
	void foundTwoKeyAuth();
	bool hasServerKeys();
};

#endif // PLAYER_HPP
