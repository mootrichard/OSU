/**
*  Author: Richard Moot
*  Date: Decemeber 8, 2015
*  Description: Network is our controller class that manages initialization of the _h@ckerLank game.
*		Everything is managed here, which cleans up our main and allows control of machines and the player to
*	be managed by Network. Main functions are start() and play() which manage the gameplay.
*/
#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "Player.hpp"
#include "Machine.hpp"
#include "Server.hpp"
#include "Computer.hpp"
#include "Mobile.hpp"

#include <iostream>
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
