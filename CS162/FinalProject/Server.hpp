#ifndef SERVER_HPP
#define SERVER_HPP
#include "Machine.hpp"

class Server : public Machine{
	private:
		bool dataDownloaded;
		bool virusInstalled;
	public:
		Server();
		void displayMenu();
		void special();
		void actionOne(Player* hacker);
		void actionTwo(Player* hacker);
};


#endif // SERVER_HPP
