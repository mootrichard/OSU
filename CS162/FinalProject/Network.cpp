#include "Network.hpp"

Network::Network(){
    hacker = new Player();
	mainframe = new Server();
	laptop = new Laptop();
	desktop = new Desktop();
	work = new Work();
	mobile = new Mobile();

	serverAccessed = false;
    detectionLevel = 0;
}

void Network::preGame(){
	std::cout << "\nAnon has connected to chat with you" << std::endl;
	std::cout << "\nAnon: Hey, welcome to Hacker Land! I setup a backdoor for you so you can use any info to log in\n" << std::endl;
}


void Network::greeting(){
    std::cout << "\n\t*************** Access Granted ***************" << std::endl;
	std::cout << "\nAnon: Great, you made it into the network! Why would they have such easy way to backdoor into the system?" << std::endl;
	std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush;
    std::cout << "\nAnon: We don't have much time, you need to find a way into their server before they run their backup and wipe it." << std::endl;
	std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush;
    std::cout << "\nAnon: They are monitoring the network and know that an unauthorized user has breached the network. The more you swtich between machines the easier it is for them to catch you." << std::endl;
	std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush;
    std::cout << "\nAnon: You'll need to get the server password and likely a 2-factor authentication code. Hopefully someone is dumb enough to have their phone connected to the wifi for you to get it." << std::endl;
	std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; 
    std::cout << "\nAnon: If you get caught they'll terminate your connection. They can track you down the more you move around, so try to be as quick as possible." << std::endl;
	std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1);
	std::cout << "\nAnon: I don't have much time, just make sure you get what you need, I would help but they are tracking my" << std::endl;
	std::cout << "." << std::flush; pauseText(1);
	std::cout << "\n\tAnon has disconnected...\n" << std::endl;
	pauseText(3);
}

void Network::instruct(){
    std::cout << "\n*************** Instructions ***************" << std::endl;
    std::cout << "\nYour goal is to access the server so you can recover evidence of your true identity." << std::endl;
    std::cout << "\nAs Anon mentioned, when you move around the network you raise awareness and they get closer to tracking you and booting you." << std::endl;
    std::cout << "\nFailed logins will raise more awareness than moving around, so make sure you find the password and verification code before as fast as possible." << std::endl;
    std::cout << "\n**Each machine might have something useful to gain access to another, so keep your eyes out for anything that might clue you into what a password might be.\n" << std::endl;
}

Player* Network::getHacker(){
    return this->hacker;
}

void Network::pauseText(time_t sec){
	time_t start_time = time(NULL);
	time_t end_time = start_time + sec;
	while (time(NULL) != end_time);
}

void Network::start(){
	unsigned int skipIntro = 2;
	std::cout << "\t\t\tWelcome to HackerLand!" << std::endl;
	std::cout << "Would you like to skip the intro and instructions? (1 for Yes, 2 for No): ";
	std::cin.clear();
	std::fflush(stdin);
	std::cin >> skipIntro;
	if (skipIntro == 2){
		preGame();
		std::cout << "Enter Username: ";
		std::cin.clear();
		std::fflush(stdin);
		std::getline(std::cin, username);
		std::cout << "Enter Password: ";
		std::getline(std::cin, username);
		std::cout << "Connecting."; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1); std::cout << "." << std::flush; pauseText(1);
		greeting();
		instruct();
	}

	mainframe->setNodes(laptop, desktop, work, mobile);
	laptop->setNodes(mainframe, desktop, work, mobile);
	desktop->setNodes(mainframe, laptop, work, mobile);
	work->setNodes(mainframe, desktop, laptop, mobile);
	mobile->setNodes(mainframe, desktop, work, laptop);

	hacker->setCurrentMachine(laptop);
}

void Network::play(){
	while (!serverAccessed && (detectionLevel < 100)){
		unsigned int playerChoice = 0;
		Machine* currentMachine = hacker->getCurrentMachine();
		unsigned int messageLength = 0;
		do{
			messageLength = hacker->getCurrentMachine()->getGreeting().length();
			std::cout << "Current detection level: " << detectionLevel << std::endl;
			std::cout << "Remeber: If you go over 100 you'll be caught and disconnected!" << std::endl;
			std::cout << "\t" << std::string(messageLength+2,'*') << std::endl;
			std::cout << "\t*" << currentMachine->getGreeting() << "*" << std::endl;
			std::cout << "\t" << std::string(messageLength + 2, '*') << std::endl;
			currentMachine->displayMenu();
			std::cin.clear();
			std::fflush(stdin);
			std::cin >> playerChoice;
			currentMachine->playerSelect(playerChoice, hacker);
			detectionLevel++;
		} while (playerChoice != 4);

		unsigned nodeChoice = 0;
		std::cin.clear();
		std::fflush(stdin);
		std::cin >> nodeChoice;
		currentMachine = currentMachine->nodeSelect(nodeChoice);
		hacker->setCurrentMachine(currentMachine);

		if (currentMachine->getType() == "Server" && hacker->hasServerKeys()){
			do{
				currentMachine->displayMenu();
				std::cin >> playerChoice;
				currentMachine->playerSelect(playerChoice, hacker);
				if (playerChoice == 4){
					std::cout << "\n\n\t\tCongrats you hacked the server and won the game!\n" << std::endl;
				}
			} while (playerChoice !=4);
			break;
		}

		detectionLevel += 10;
	}
	if (detectionLevel >= 100){
		std::cout << "\n\n\t\tYou got caught and they severed your connection!\n" << std::endl;
	}
}