#ifndef SERVER_HPP
#define SERVER_HPP
#include "Machine.hpp"

class Server : public Machine{
	private:
		bool hasPassword;
		bool hasTwoFactor;
	public:
		Server();
		void loginAttempt();
		void displayMenu();
		void playerSelect(unsigned int choice);
};


#endif // SERVER_HPP
