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

Creature* Combat::battlePhase(Creature* first, Creature* second){
  while((first->getStrength() > 0) && (second->getStrength() > 0)){
    turn++; // Turn tracked needs to go up
    // This is our combat phase actually taking place
    unsigned int firstAttack = first->attack(second);
    unsigned int firstDefense = first->defense();
    unsigned int secondAttack = second->attack(first);
    unsigned int secondDefense = second->defense();
    unsigned int pOneDamageTaken = secondAttack - firstDefense;
    unsigned int pTwoDamageTaken = firstAttack - secondDefense;

    // Handling the special case of Achilles to be alerted to the console
    if((first->getType() == "Goblin" && firstAttack == 12)||(second->getType() == "Goblin" && secondAttack == 12)){
      std::cout << "Achilles has been applied!" << std::endl;
    }

    // First player has done some damage beyond their defensive roll
    if(firstAttack > secondDefense){
      if(pTwoDamageTaken == 0 && second->getType() == "The Shadow"){ // Handling special case of Shadow getting 0 damange, he has mo armor to he must'ved dodged
          std::cout << second->getName() <<  " dodged an attack!" << std::endl;
      }
      // Here we are applying the damage.
      second->takeDamage(pTwoDamageTaken);
      if(second->getStrength() <= 0){
        break;
      }
    }

    // This is the same as everything for First player above, but for Second player
    if(secondAttack > firstDefense){
        if(pOneDamageTaken == 0 && first->getType() == "The Shadow"){
          std::cout << first->getName() <<  " dodged the attack!" << std::endl;          
        }
      first->takeDamage(pOneDamageTaken);
      if(first->getStrength() <= 0){
        break;
      }      
    }
  }
  if(first->getStrength() <= 0 && second->getStrength() <= 0){
    unsigned int coinToss = rand()% 100 + 1;
    if(coinToss >= 50){
      std::cout << first->getName() << " was defeated." << std::endl;
      return first;
    }
    else{
      std::cout << second->getName() << " was defeated." << std::endl;
      return second;
    }
  }
  else if(first->getStrength() <= 0){
    std::cout << first->getName() << " was defeated." << std::endl;
    return first;
  }
  else if(second->getStrength() <= 0){
    std::cout << second->getName() << " was defeated." << std::endl;
    return second;
  }
  else{
    return NULL;
  }
}