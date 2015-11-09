#include "combat.hpp"

int main(){
  // Need to seed our randomizer for fair rolls to take place.
  srand(time(NULL));

  // Initializing all of the creatures that we will be using
  Barbarian newBarb;
  ReptilePeople newReptile;
  Goblin newGoblin;
  BlueMen newBlueMen;
  Shadow newShadow;
  Goblin goblinOne;
  Goblin goblinTwo;
  Barbarian barbVBlue;

  // Creating pointers to our creatures since we need to permanently alter certain values
  Barbarian* pointBarb = &newBarb;
  ReptilePeople* pointRep = &newReptile;
  Goblin* pointGoblin = &newGoblin;
  BlueMen* pointBlueMen = &newBlueMen;
  Shadow* pointShadow = &newShadow;
  Goblin* goblinOnePoint = &goblinOne;
  Goblin* goblinTwoPoint = &goblinTwo;
  Barbarian* barbVBluePoint = &barbVBlue;

  // Initializing our Combat arena with a pointer that allows us to reset the rounds
  Combat commence;
  Combat* turnResetter = &commence;

  // Testing for standard operation between two normal classes
  std::cout << "\nHere the Barbarian and Reptile People will fight until one goes at or below 0 strength" << std::endl;
  std::cout << "Press enter to proceed..." << std::endl;
  std::cin.get();

  while(pointBarb->getStrength() > 0 && pointRep->getStrength() > 0){
    commence.battlePhase(pointBarb, pointRep);
  }

  turnResetter->resetTurn();

  // Testing for achilles trigger along with dodge from Shadow
  std::cout << "\nHere we are will simulate combat until an Achilles is triggered. \n\t(be warned strength limits will be ignored)" << std::endl;
  std::cout << "You should also see several dodges from The Shadow in there as well" << std::endl;
  std::cout << "Press enter to proceed..." << std::endl;
  std::cin.get();

  while(pointGoblin->getAchilles() != true){
    commence.battlePhase(pointGoblin, pointShadow);
  }

  turnResetter->resetTurn();

  // Testing for achilles non-trigger between two goblins
  std::cout << "\nHere we are will simulate combat two Goblins to show achilles won't happen (12 rounds should do)" << std::endl;
  std::cout << "Press enter to proceed..." << std::endl;
  std::cin.get();
  for(unsigned int i = 0; i < 12; i++){
    commence.battlePhase(goblinOnePoint, goblinTwoPoint);
  }

  turnResetter->resetTurn();

  // Demonstrating that the Blue Men are also working
  std::cout << "\nHere the Barbarian and Blue Men will fight until one goes at or below 0 strength" << std::endl;
  std::cout << "Press enter to proceed..." << std::endl;
  std::cin.get();

  while(barbVBluePoint->getStrength() > 0 && pointBlueMen->getStrength() > 0){
    commence.battlePhase(barbVBluePoint, pointBlueMen);
  }

  std::cout << "\nThanks for testing out my application! \n";

}
