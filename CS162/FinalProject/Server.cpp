#include "Server.hpp"

Server::Server(){
	this->greeting = "You have gained access to the server!";
	this->dataDownloaded = false;
	this->virusInstalled = false;
	this->type = "Server";
}

void Server::displayMenu(){
	std::cout << "Menu Options:" << std::endl;
	std::cout << "\t1. Download database" << std::endl;
	std::cout << "\t2. Wipe database" << std::endl;
	std::cout << "\t3. Open Internet Explorer...really?" << std::endl;
	std::cout << "\t4. Leave" << std::endl;
	std::cout << "Enter number of your selection: " << std::flush;
}

void Server::actionOne(Player* hacker){
	if (!dataDownloaded){
		std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
		std::cout << "Data downloaded! Get out of there!\n" << std::endl;
		std::cout << "==============================================================================\n" << std::endl;
		dataDownloaded = true;
		return;
	}
	else{
		std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
		std::cout << "You already downloaded the data, what are you doing?\n" << std::endl;
		std::cout << "==============================================================================\n" << std::endl;
		return;
	}
}

void Server::actionTwo(Player* hacker){
	if (dataDownloaded){
		std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
		std::cout << "Server has now been wiped!\n" << std::endl;
		std::cout << "==============================================================================\n" << std::endl;
		return;
	}
	else{
		std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
		std::cout << "You need to download the data first!\n" << std::endl;
		std::cout << "==============================================================================\n" << std::endl;
		return;
	}
}

void Server::special(){
	if (!virusInstalled && dataDownloaded){
		std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
		std::cout << "You just downloaded a virus onto the server using Internet Explorer! Who knew that IE could be useful?\n" << std::endl;
		std::cout << "==============================================================================\n" << std::endl;
		virusInstalled = true;
		return;
	}
	else if (!dataDownloaded && !virusInstalled){
		std::cout << "==============================================================================\n\t\t\tMessage" << std::endl;
		std::cout << "You can mess with Internet Explorer after you download the data!\n" << std::endl;
		std::cout << "==============================================================================\n" << std::endl;
		return;
	}
	else{
		return;
	}
}
