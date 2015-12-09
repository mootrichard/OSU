#ifndef MOBILE_HPP
#define MOBILE_HPP
#include "Machine.hpp"

class Mobile : public Machine{
private:
	bool twoFactorAcquired;
	bool triggerText;
public:
	Mobile();
	Mobile(Machine* one, Machine* two, Machine* three, Machine* four);
	void displayMenu();
	void special();
	void actionOne(Player* hacker);
	void actionTwo(Player* hacker);
};


#endif // MOBILE_HPP
