  int test() {
  // Creating our creatures since we need to permanently alter certain values
  Barbarian* pointBarb = new Barbarian;
  ReptilePeople* pointRep = new ReptilePeople;
  Goblin* pointGoblin = new Goblin;
  BlueMen* pointBlueMen = new BlueMen;
  Shadow* pointShadow = new Shadow;
  Goblin* goblinOnePoint = new Goblin;
  Goblin* goblinTwoPoint = new Goblin;
  Barbarian* barbVBluePoint = new Barbarian;

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



//

void Combat::battlePhase(Creature* first, Creature* second){
  while(first->getStrength() >= 0 && second->getStrength() >= 0){
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
    std::cout << first->getName() << " rolled " << firstAttack << " for attack" << std::endl;
    std::cout << second->getName() << " rolled " << secondDefense << " for defense" << std::endl;
    std::cout << second->getName() << " rolled " << secondAttack << " for attack" << std::endl;
    std::cout << first->getName() << " rolled " << firstDefense << " for defense" << std::endl;

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
          std::cout << second->getName() <<  " dodged the attack!" << std::endl;          
        }
        else{
          std::cout << second->getName() <<  "'s armor blocked the attack" << std::endl;
        }
      }
      // Here we are applying the damage and also reporting it back to the user.
      std::cout << second->getName()<< " took " << second->takeDamage(pTwoDamageTaken) << " damage." << std::endl;
      std::cout << second->getName() << " now has " << second->getStrength() << " strength" << std::endl;
    }

    // This is the same as everything for First player above, but for Second player
    if(secondAttack > firstDefense){
        if(first->getType() == "The Shadow"){
          std::cout << first->getName() <<  " dodged the attack!" << std::endl;          
        }
      std::cout << first->getName() << " took " << first->takeDamage(pOneDamageTaken) << " damage." << std::endl;
      std::cout << first->getName() << " now has " << first->getStrength() << " strength" << std::endl;
    }
  }
  return;
}