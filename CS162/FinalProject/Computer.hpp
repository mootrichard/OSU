/**
 *  Author: Richard Moot
 *  Date: Decemeber 7, 2015
 *  Description: 
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
};

class Desktop : public Computer{
	protected:

	public:
		Desktop();
		void displayMenu();
		void special();
};

class Work : public Computer{
	protected:

	public:
		Work();
		void displayMenu();
		void special();
};

#endif // COMPUTER_HPP
