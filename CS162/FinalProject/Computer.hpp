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
		std::string hdd;
		std::string password;
	public:
		Computer();
		std::string getHdd();
		std::string getPassword();
};

class Laptop : public Computer{
	protected:
	
	public:
		Laptop();
		void Laptop::setNodeOne(Machine *m);
		void Laptop::setNodeTwo(Machine *m);
		void Laptop::setNodeThree(Machine *m);
		void Laptop::setNodeFour(Machine *m);
};

class Desktop : public Computer{
	protected:

	public:
		Desktop();
		void Desktop::setNodeOne(Machine *m);
		void Desktop::setNodeTwo(Machine *m);
		void Desktop::setNodeThree(Machine *m);
		void Desktop::setNodeFour(Machine *m);
};

class Work : public Computer{
	protected:

	public:
		Work();
		void Work::setNodeOne(Machine *m);
		void Work::setNodeTwo(Machine *m);
		void Work::setNodeThree(Machine *m);
		void Work::setNodeFour(Machine *m);
};

#endif // COMPUTER_HPP
