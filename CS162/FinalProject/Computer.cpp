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
	this->greeting = "You're connected to the laptop computer";
}

void Laptop::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search harddrive" << std::endl;
	std::cout << "\t2. Turn on Bluetooth" << std::endl;
	std::cout << "\t3. Open Internet Explorer" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
	std::cout << "Enter number of your selection: ";
}

void Laptop::special(){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "BSOD! Looks like Internet Explorer is corrupted on this machine... that should teach you a lesson for trying to open that" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

void Laptop::actionOne(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "Looks like there are a bunch of OSU Assignment files on here... No password though" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

void Laptop::actionTwo(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "Okay, bluetooth is on! I don't really see how that helps anything though" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}


Desktop::Desktop(){
	type = "Desktop";
	this->greeting = "You're connected to the desktop computer.";
}

void Desktop::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search harddrive" << std::endl;
	std::cout << "\t2. Play video games" << std::endl;
	std::cout << "\t3. Open Internet Explorer" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
	std::cout << "Enter number of your selection: ";
}

void Desktop::special(){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "...I'm sorry, did you mean to open up Chrome?\n" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

void Desktop::actionOne(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "It just look like they have a bunch of video games on this machine." << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

void Desktop::actionTwo(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "We don't have time for that!" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}


Work::Work(){
	type = "Work";
	this->greeting = "You're connected to the work computer.\n";
}

void Work::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search harddrive" << std::endl;
	std::cout << "\t2. Search email" << std::endl;
	std::cout << "\t3. Open Internet Explorer" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
	std::cout << "Enter number of your selection: ";
}

void Work::special(){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "Program not found, IT appears to have removed this from your system. Repeated attempts to open this program may result in being locked out." << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

void Work::actionOne(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "Nothing but excel documents, and none of them appear to have passwords in them" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

void Work::actionTwo(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "Hey, it looks like they recently reset their password to the server! Lets try using that!" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	hacker->foundServerPass();
	return;
}