#ifndef MOBILE_HPP
#define MOBILE_HPP
#include "Machine.hpp"

class Mobile : public Machine{
private:
	bool twoFactorAcquired;
	std::string twoFactor;
public:
	Mobile();
	Mobile(Machine* one, Machine* two, Machine* three, Machine* four);
	void loginAttempt();
	void displayMenu();
	void playerSelect(unsigned int choice);
};


#endif // MOBILE_HPP
