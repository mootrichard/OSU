#include "Player.hpp"

Player::Player(){
  std::cout << "Enter Username: ";
  std::getline(std::cin,name);
  std::cout << "Enter Password: ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');

  twoKeyAuth = false;
  serverPass = false;
  workComp = false;
  mobileCode = false;
}

unsigned int Player::getDetectionLevel(){
	return this->detectionLevel;
}

std::string Player::getName(){
	return this->name;
}