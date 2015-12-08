#include "Computer.hpp"

Computer::Computer(){
}

bool Computer::getHdd(){
	return this->hdd;
}

bool Computer::getPassword(){
	return this->password;
}

Laptop::Laptop(){
	this->type = "Laptop";
	this->greeting = "You've connected to the laptop computer";
}

void Laptop::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search harddrive" << std::endl;
	std::cout << "\t2. Search email" << std::endl;
	std::cout << "\t3. Open Internet Explorer" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
}


Desktop::Desktop(){
	type = "Desktop";
	this->greeting = "You've connected to the desktop computer.";
}


void Desktop::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search harddrive" << std::endl;
	std::cout << "\t2. Search email" << std::endl;
	std::cout << "\t3. Open Internet Explorer" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
}


Work::Work(){
	type = "Work";
	this->greeting = "You've connected to the work computer.";
}


void Work::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search harddrive" << std::endl;
	std::cout << "\t2. Search email" << std::endl;
	std::cout << "\t3. Open Internet Explorer" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
}
