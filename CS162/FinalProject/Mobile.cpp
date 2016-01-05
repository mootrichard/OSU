/**
*  Author: Richard Moot
*  Date: Decemeber 8, 2015
*  Description: Mobile is where our two-key factor code is located for getting into the server. It inherits
 *    directly from Machine
*/

#include "Mobile.hpp"

// Contructor for initializing Mobile variables
Mobile::Mobile(){
	type = "Mobile";
	greeting = "You're connected to the Mobile phone.\n";
}

// Displays our selection menu for Mobile
void Mobile::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Search photos" << std::endl;
	std::cout << "\t2. Search text messages" << std::endl;
	std::cout << "\t3. Open Google Authenticator" << std::endl;
	std::cout << "\t4. Move to another machine" << std::endl;
	std::cout << "Enter number of your selection: ";
}

// First action for Mobile, just displays a funny message
void Mobile::actionOne(Player* hacker){
	std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
	std::cout << "This is just a bunch of pictures of cats..." << std::endl;
	std::cout << "==============================================================================\n" << std::endl;
	return;
}

/**
 * @brief Obtains our TwoFactor code
 * @details actionTwo checks if we have triggered the code to be generated, and either gives it to
 *   the player, or it will hint to the user to go trigger the code
 * 
 * @param hacker Our player
 */
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

/**
 * @brief Triggers TwoFactor to be generated
 * @details This will trigger the TwoFactor to be generated, but will warn the user if they had already
 *   generated the code
 */
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
