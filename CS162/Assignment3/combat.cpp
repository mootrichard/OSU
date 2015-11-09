// Author: Richard Moot
// Date: 11/08/2015
// Description: The combat class is used for handling combat for the Creatures classes
//   It will manage the battle phases by calling combat rolls and passing values between
//   creatures.

#include "combat.hpp"

// Combat Constructor, only need to initialize our turns
Combat::Combat(){
  turn = 0;
}

// Used to reset the turns between testing runs
void Combat::resetTurn(){
  this->turn = 0;
}

void Combat::battlePhase(Creature* first, Creature* second){
    turn++; // Turn tracked needs to go up
    std::cout << "\n -----Round " << turn << " Commencing!----- " << std::endl;
    // This is our combat phase actually taking place
    unsigned int firstAttack = first->attack(second);
    unsigned int firstDefense = first->defense();
    unsigned int secondAttack = second->attack(first);
    unsigned int secondDefense = second->defense();
    unsigned int pOneDamageTaken = secondAttack - firstDefense;
    unsigned int pTwoDamageTaken = firstAttack - secondDefense;

    // Reading out the results of combat to the console
    std::cout << first->getType() << " rolled " << firstAttack << " for attack" << std::endl;
    std::cout << second->getType() << " rolled " << secondDefense << " for defense" << std::endl;
    std::cout << second->getType() << " rolled " << secondAttack << " for attack" << std::endl;
    std::cout << first->getType() << " rolled " << firstDefense << " for defense" << std::endl;

    // Handling the special case of Achilles to be alerted to the console
    if((first->getType() == "Goblin" && firstAttack == 12)||(second->getType() == "Goblin" && secondAttack == 12)){
      std::cout << "Achilles has been applied!" << std::endl;
    }

    // Nobody did any damage, we can skip this round
    if(pOneDamageTaken == 0 && pTwoDamageTaken == 0){
      std::cout << "No damage taken for either player this round" << std::endl;
      return;
    }

    // First player has done some damage beyond their defensive roll
    if(firstAttack > secondDefense){
      if(pTwoDamageTaken == 0){ // Handling special case of Shadow getting 0 damange, he has mo armor to he must'ved dodged
        if(second->getType() == "The Shadow"){
          std::cout << second->getType() <<  " dodged the attack!" << std::endl;          
        }
        else{
          std::cout << second->getType() <<  "'s armor blocked the attack" << std::endl;
        }
      }
      // Here we are applying the damage and also reporting it back to the user.
      std::cout << second->getType()<< " took " << second->takeDamage(pTwoDamageTaken) << " damage." << std::endl;
      std::cout << second->getType() << " now has " << second->getStrength() << " strength" << std::endl;
    }

    // This is the same as everything for First player above, but for Second player
    if(secondAttack > firstDefense){
        if(first->getType() == "The Shadow"){
          std::cout << first->getType() <<  " dodged the attack!" << std::endl;          
        }
      std::cout << first->getType() << " took " << first->takeDamage(pOneDamageTaken) << " damage." << std::endl;
      std::cout << first->getType() << " now has " << first->getStrength() << " strength" << std::endl;
    }

}