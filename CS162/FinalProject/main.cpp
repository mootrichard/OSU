#include "Network.hpp"

int main(){
	unsigned int playAgain = 1;
	do{
		Network* game = new Network();
		game->start();
		game->play();

		std::cout << "\n\n\t\tWould you like to play again? (1 for yes, 2 for no): ";
		std::cin >> playAgain;
		if (playAgain != 1){
			break;
		}
	} while (playAgain = 1);
	
	return 0;
}