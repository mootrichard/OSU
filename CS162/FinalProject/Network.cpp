#include "Network.hpp"

Network::Network(){
	preGame();
    hacker = new Player();
    greeting();
    instruct();
    detectionLevel = 0;
}

void Network::preGame(){
	std::cout << "\nAnon has connected to chat with you" << std::endl;
	std::cout << "\nAnon: Hey, I was able to set you up with the backdoor to their network, so use any credentials to login\n" << std::endl;
}


void Network::greeting(){
    std::cout << "\n*************** Access Granted ***************" << std::endl;
	std::cout << "\nAnon: Great, you made it into the network! Why would they have such easy way to backdoor into the system?" << std::endl;
	std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50);
    std::cout << "\nAnon: We don't have much time, you need to find a way into their server before they run their backup and wipe it." << std::endl;
	std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50);
    std::cout << "\nAnon: They are monitoring the network and know that an unauthorized user has breached the network. The more you swtich between machines the easier it is for them to catch you." << std::endl;
	std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50);
    std::cout << "\nAnon: You'll need to get the server password and likely a 2-factor authentication code. Hopefully someone is dumb enough to have their phone connected to the wifi for you to get it." << std::endl;
	std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); pauseText(50);
    std::cout << "\nAnon: If you get caught they'll terminate your connection. They can see failed login attempts on the server so make sure you have the password before trying to get in, otherwise you might trigger a lockdown." << std::endl;
	std::cout << "."; pauseText(50); std::cout << "."; pauseText(50); std::cout << "."; pauseText(50);
	std::cout << "\nAnon: I don't have much time, just make sure you get what you need, I would help but they are tracking my" << std::endl;
	std::cout << "."; pauseText(50); std::cout << "."; pauseText(50);
	std::cout << "\n\tAnon has disconnected...\n" << std::endl;
	pauseText(200);
}

void Network::instruct(){
    std::cout << "\n*************** Instructions ***************" << std::endl;
    std::cout << "\nYour goal is to access the server so you can recover evidence of your true identity." << std::endl;
    std::cout << "\nAs Anon mentioned, when you move around the network or fail login attempts you raise awareness and they get closer to tracking where you are." << std::endl;
    std::cout << "\nFailed logins will raise more awareness than moving around, so make sure you have the right password and verification code before trying to get into the server." << std::endl;
    std::cout << "\n**Each machine might have something useful to gain access to another, so keep your eyes out for anything that might clue you into what a password might be.\n" << std::endl;
}

Player* Network::getHacker(){
    return this->hacker;
}

void Network::pauseText(clock_t sec){
	//std::cout << "Press enter to continue...\n" << std::flush;
	//std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
	clock_t start_time = clock();
	clock_t end_time = sec * 10 + start_time;
	while (clock() != end_time);
}