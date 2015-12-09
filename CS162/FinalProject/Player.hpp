/**
 *  Author: Richard Moot
 *  Date: Decemeber 7, 2015
 *  Description: 
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
    unsigned int detectionLevel;
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
