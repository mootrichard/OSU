/**
*  Author: Richard Moot
*  Date: Decemeber 8, 2015
*  Description: Computer class where our Laptop, Desktop and Work machines inherit from. Computer inherits
 *  from Machine.
*/
#include "Computer.hpp"

// Basic contructor
Computer::Computer(){
}

// Getter for HDD, but was not ultimately utilized
bool Computer::getHdd(){
	return this->hdd;
}

// Getter for password, later can be used for logins across machines
bool Computer::getPassword(){
	return this->password;
}

// Sets variables on construction
Laptop::Laptop(){
	this->type = "Laptop";
	this->greeting = "You're connected to the laptop computer";
}

// Displays Laptop menu options
void Laptop::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search harddrive" << std::endl;
	std::cout << "\t2. Turn on Bluetooth" << std::endl;
	std::cout << "\t3. Open Internet Explorer" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
	std::cout << "Enter number of your selection: ";
}

// Our Special action for the Laptop, just displays a funny message
void Laptop::special(){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "BSOD! Looks like Internet Explorer is corrupted on this machine... that should teach you a lesson for trying to open that" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

// Our first action for the Laptop, just displays a funny message
void Laptop::actionOne(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "Looks like there are a bunch of OSU Assignment files on here... No password though" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

// Our Third action for the Laptop, just displays a funny message
void Laptop::actionTwo(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "Okay, bluetooth is on! I don't really see how that helps anything though" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

// Desktop constructor, initalizes variables
Desktop::Desktop(){
	type = "Desktop";
	this->greeting = "You're connected to the desktop computer.";
}

// Displays Desktop menu options
void Desktop::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search harddrive" << std::endl;
	std::cout << "\t2. Play video games" << std::endl;
	std::cout << "\t3. Open Internet Explorer" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
	std::cout << "Enter number of your selection: ";
}

// Our Special action for Desktop, just displays a funny message
void Desktop::special(){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "...I'm sorry, did you mean to open up Chrome?\n" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

// Our First action for Desktop, just displays a funny message
void Desktop::actionOne(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "It just look like they have a bunch of video games on this machine." << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

// Our Second action for Desktop, just displays a funny message
void Desktop::actionTwo(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "We don't have time for that!" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

// Work constructor, initalizes variables
Work::Work(){
	type = "Work";
	this->greeting = "You're connected to the work computer.\n";
}

// Our Work display menu to show player options
void Work::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search harddrive" << std::endl;
	std::cout << "\t2. Search email" << std::endl;
	std::cout << "\t3. Open Internet Explorer" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
	std::cout << "Enter number of your selection: ";
}

// Our Special action for Work, just displays a funny message
void Work::special(){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "Program not found, IT appears to have removed this from your system. Repeated attempts to open this program may result in being locked out." << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

// Our First action for Work, just displays a funny message
void Work::actionOne(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "Nothing but excel documents, and none of them appear to have passwords in them" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

// Our Second action for Work, just displays a funny message
void Work::actionTwo(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "Hey, it looks like they recently reset their password to the server! Lets try using that!" << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	hacker->foundServerPass();
	return;
}