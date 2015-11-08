#include "combat.hpp"

Combat::Combat(){
  turn = 0;
}

void Combat::battlePhase(Creature* first, Creature* second){
  turn++;
  std::cout << "\n -----Battle Commencing!----- " << std::endl; 
  unsigned int firstAttack = first->attack(second);
  unsigned int firstDefense = first->defense();
  unsigned int secondAttack = second->attack(first);
  unsigned int secondDefense = second->defense();
  unsigned int damageTaken;

  if(firstAttack <= secondDefense && secondAttack <= firstDefense){
    std::cout << "Draw! Neither player takes damage" << std::endl;
  }
  else if(firstAttack > secondDefense){
    damageTaken = second->takeDamage(firstAttack);
    std::cout << "Second Player's defense roll lost" << std::endl;
    if(damageTaken == 0){
      std::cout << "Second Player's armor blocked the attack" << std::endl;
    }
    std::cout << damageTaken << " damage was taken" << std::endl;
    std::cout << "Second player now has " << second->getStrength() << " strength" << std::endl;
  }
  else if(secondAttack > firstDefense){
    damageTaken = first->takeDamage(secondAttack);
    std::cout << "First Player's defense roll lost" << std::endl;
    if(damageTaken == 0){
      std::cout << "First Player's armor blocked the attack" << std::endl;
    }
    std::cout << damageTaken << " damage was taken" << std::endl;
    std::cout << "First player now has " << first->getStrength() << " strength" << std::endl;
  }
  else{
    return;
  }
}