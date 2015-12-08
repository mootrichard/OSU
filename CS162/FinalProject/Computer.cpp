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
	std::cout << "Enter number of your selection: " << std::flush;
}

void Laptop::special(){
	std::cout << "BSOD! Looks like Internet Explorer is corrupted on this machine... that should teach you a lesson for trying to open that" << std::endl;
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
	std::cout << "Enter number of your selection: " << std::flush;
}

void Desktop::special(){
	std::cout << "...I'm sorry, did you mean to open up Chrome?" << std::endl;
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
	std::cout << "Enter number of your selection: " << std::flush;
}

void Work::special(){
	std::cout << "Program not found, IT appears to have removed this from your system. Repeated attempts to open this program may result in being locked out." << std::endl;
}