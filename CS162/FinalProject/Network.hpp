/**
 *  Author: Richard Moot
 *  Date: Decemeber 7, 2015
 *  Description: 
 */
#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "Player.hpp"
#include "Machine.hpp"
#include <iostream>
#include <limits>
#include <ctime>

class Network {
  private:
    Player *hacker;
    unsigned int detectionLevel;
  public:
    Network();
	void preGame();
    void greeting();
    void instruct();
	void pauseText(clock_t sec);
    Player* getHacker();
};

#endif // NETWORK_HPP
