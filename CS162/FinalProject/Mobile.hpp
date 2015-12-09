/**
*  Author: Richard Moot
*  Date: Decemeber 8, 2015
*  Description: Mobile is where our two-key factor code is located for getting into the server
*/
#ifndef MOBILE_HPP
#define MOBILE_HPP
#include "Machine.hpp"

class Mobile : public Machine{
private:
	bool twoFactorAcquired;
	bool triggerText;
public:
	Mobile();
	void displayMenu();
	void special();
	void actionOne(Player* hacker);
	void actionTwo(Player* hacker);
};


#endif // MOBILE_HPP
