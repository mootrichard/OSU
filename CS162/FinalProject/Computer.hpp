/**
*  Author: Richard Moot
*  Date: Decemeber 8, 2015
*  Description: Computer class where our Laptop, Desktop and Work machines inherit from. Computer inherits
 *  from Machine.
*/
#ifndef COMPUTER_HPP
#define COMPUTER_HPP
#include "Machine.hpp"

class Computer: public Machine{
	protected:
		bool hdd;
		bool password;
	public:
		Computer();
		bool getHdd();
		bool getPassword();
};

class Laptop : public Computer{
	protected:
	
	public:
		Laptop();
		void displayMenu();
		void special();
		void actionOne(Player* hacker);
		void actionTwo(Player* hacker);
};

class Desktop : public Computer{
	protected:

	public:
		Desktop();
		void displayMenu();
		void special();
		void actionOne(Player* hacker);
		void actionTwo(Player* hacker);
};

class Work : public Computer{
	protected:

	public:
		Work();
		void displayMenu();
		void special();
		void actionOne(Player* hacker);
		void actionTwo(Player* hacker);
};

#endif // COMPUTER_HPP
