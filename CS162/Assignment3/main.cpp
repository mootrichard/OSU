#include "combat.hpp"

int main(){
  srand(time(NULL));

  Barbarian* newBarb = new Barbarian;
  ReptilePeople* newReptile = new ReptilePeople;
  Goblin* newGoblin = new Goblin;
  BlueMen* newBlueMen = new BlueMen;
  Shadow* newShadow = new Shadow;

  std::cout << "\n---------ATTACK ROUND-------\n" << std::endl;
  newBarb->attackRoll();
  newReptile->attackRoll();
  newGoblin->attackRoll();
  newBlueMen->attackRoll();
  newShadow->attackRoll();
  
  std::cout << "\n---------Defense ROUND-------\n" << std::endl;
  newBarb->defenseRoll();
  newReptile->defenseRoll();
  newGoblin->defenseRoll();
  newBlueMen->defenseRoll();
  newShadow->defenseRoll();

}