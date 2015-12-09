#include "Mobile.hpp"

Mobile::Mobile(){
	type = "Mobile";
	greeting = "You're connected to the Mobile phone.\n";
}

Mobile::Mobile(Machine* one, Machine* two, Machine* three, Machine* four){
	this->nodeOne = one;
	this->nodeTwo = two;
	this->nodeThree = three;
	this->nodeFour = four;
}

void Mobile::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search photos" << std::endl;
	std::cout << "\t2. Search text messages" << std::endl;
	std::cout << "\t3. Open Google Authenticator" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
	std::cout << "Enter number of your selection: ";
}


void Mobile::actionOne(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "This is just a bunch of pictures of cats..." << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

void Mobile::actionTwo(Player* hacker){
	if (triggerText){
		std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
		std::cout << "Great! We got the 2-factor code!" << std::endl;
		std::cout << "==============================================================================\n" << std::endl;
		hacker->foundTwoKeyAuth();
		return;
	}
	else if (!triggerText){
		std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
		std::cout << "I can only see texts from their girlfriend, they must use an app to trigger the code to send." << std::endl;
		std::cout << "==============================================================================\n" << std::endl;
		return;
	}
	else {
		return;
	}
}

void Mobile::special(){
	if (!triggerText){
		std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
		std::cout << "You just triggered the two-factor authenticator, check the test messages!\n" << std::endl;
		std::cout << "==============================================================================\n" << std::endl;
		this->triggerText = true;
	}
	else if (triggerText){
		std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
		std::cout << "I don't think triggering another code to generate is helping..." << std::endl;
		std::cout << "==============================================================================\n" << std::endl;
		return;
	}
}
