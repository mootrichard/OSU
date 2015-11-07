#include "combat.hpp"

int main(){
  srand(time(NULL));

  Barbarian* newBarb = new Barbarian;
  ReptilePeople* newReptile = new ReptilePeople;
  Goblin* newGoblin = new Goblin;
  BlueMen* newBlueMen = new BlueMen;
  Shadow* newShadow = new Shadow;

  std::cout << "\n---------ATTACK ROUND-------\n" << std::endl;
  newBarb->attack();
  newReptile->attack();
  newGoblin->attack();
  newBlueMen->attack();
  newShadow->attack();
  
  std::cout << "\n---------Defense ROUND-------\n" << std::endl;
  newBarb->defense();
  newReptile->defense();
  newGoblin->defense();
  newBlueMen->defense();
  newShadow->defense();

}