#include "combat.hpp"

void Combat::battlePhase(Creature* first, Creature* second){
  unsigned int firstAttack = first->attack();
  unsigned int secondAttack = second->attack();

  if(firstAttack > secondAttack){
    second->takeDamage(firstAttack);
  }
  else if(secondAttack > firstAttack){
    first->takeDamage(secondAttack);
  }
}