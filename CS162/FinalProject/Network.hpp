/**
 *  Author: Richard Moot
 *  Date: Decemeber 7, 2015
 *  Description: 
 */
#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "Player.hpp"
#include "Machine.hpp"
#include "Server.hpp"
#include "Computer.hpp"
#include "Mobile.hpp"

#include <iostream>
#include <limits>
#include <ctime>
#include <cstdio>

class Network {
  private:
    Player *hacker;
	Server *mainframe;
	Laptop *laptop;
	Desktop *desktop;
	Work *work;
	Mobile *mobile;
	std::string username;
	std::string password;
    unsigned int detectionLevel;
	bool serverAccessed;
  public:
    Network();
	void start();
	void preGame();
    void greeting();
    void instruct();
	void pauseText(time_t sec);
	void play();
    Player* getHacker();
};

#endif // NETWORK_HPP
