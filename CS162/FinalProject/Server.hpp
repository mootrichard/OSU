/**
*  Author: Richard Moot
*  Date: Decemeber 8, 2015
*  Description: Server is our class that is the goal to get into for our game. It is linked to the other rooms
 *    but ultimately is where you want to end up.
*/

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
