#include "Player.hpp"
#include "Machine.hpp"

Player::Player(){
  twoKeyAuth = false;
  serverPass = false;
  mobileCode = false;
}

unsigned int Player::getDetectionLevel(){
	return this->detectionLevel;
}

std::string Player::getName(){
	return this->name;
}

void Player::setCurrentMachine(Machine* m){
	if (m->getType() == "Server" && (!twoKeyAuth && !serverPass)){
		std::cout << "Unautorized access!" << std::endl;
		return;
	}
	this->currentMachine = m;
}

Machine* Player::getCurrentMachine(){
	return this->currentMachine;
}

bool Player::hasServerKeys(){
	if (twoKeyAuth && serverPass){
		return true;
	}
	else {
		return false;
	}
}

void Player::foundServerPass(){
	this->serverPass = true;
}

void Player::foundTwoKeyAuth(){
	this->twoKeyAuth = true;
}