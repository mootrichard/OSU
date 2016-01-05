/**
*  Author: Richard Moot
*  Date: Decemeber 8, 2015
*  Description: Player class that all of our spaces/room will inherit from, so the implementations
 *  here are intentionally generalized since they will all be inherited
*/

#include "Player.hpp"
#include "Machine.hpp"

// Basic Player constructor that initializes our variables
Player::Player(){
  twoKeyAuth = false;
  serverPass = false;
  mobileCode = false;
}

// Getter for Player's name
std::string Player::getName(){
	return this->name;
}

// Setter for which room the player is currently inside of, also ensures the proper keys are obtained before entering the server
void Player::setCurrentMachine(Machine* m){
	if (m->getType() == "Server" && (!twoKeyAuth && !serverPass)){
		std::cout << "Unautorized access!" << std::endl;
		return;
	}
	this->currentMachine = m;
}

// Getter for the machine they are currently inside
Machine* Player::getCurrentMachine(){
	return this->currentMachine;
}

// Checks if the Player has the keys for the server
bool Player::hasServerKeys(){
	if (twoKeyAuth && serverPass){
		return true;
	}
	else {
		return false;
	}
}

// Sets serverPass key to true
void Player::foundServerPass(){
	this->serverPass = true;
}

// Sets twoKeyAuth key to true
void Player::foundTwoKeyAuth(){
	this->twoKeyAuth = true;
}