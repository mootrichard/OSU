#include "tournament.hpp"

Tournament::Tournament(){
  top = NULL;
  frontOne = NULL;
  backOne = NULL;
  frontTwo = NULL;
  backTwo = NULL;
  playerOneWins = 0;
  playerTwoWins = 0;
  setLineupSize();
  lineupSelector(1);
  lineupSelector(2);
}

Creature* Tournament::getFrontOne(){
  return this->frontOne->combatant;
}

Creature* Tournament::getFrontTwo(){
  return this->frontTwo->combatant;
}

void Tournament::setLineupSize(){
  std::cout << "Enter lineup size: ";
  std::cin >> this->lineupSize;
  std::cout << std::endl;
}

void Tournament::creatureSelector(unsigned int player, unsigned int nextCreature, std::string creatureName){
  if(nextCreature == 1){
    Barbarian* pointBarb = new Barbarian;
    pointBarb->setName(creatureName);
    if(player == 1){
      addCreatureOne(pointBarb);
    }
    else if(player == 2){
      addCreatureTwo(pointBarb);
    }
    else{
      return;
    }
  }
  else if(nextCreature == 2){
    ReptilePeople* pointRep = new ReptilePeople;
    pointRep->setName(creatureName);
    if(player == 1){
      addCreatureOne(pointRep);
    }
    else if(player == 2){
      addCreatureTwo(pointRep);
    }
    else{
      return;
    }
  }
  else if(nextCreature == 3){
    Goblin* pointGoblin = new Goblin;
    pointGoblin->setName(creatureName);
    if(player == 1){
      addCreatureOne(pointGoblin);
    }
    else if(player == 2){
      addCreatureTwo(pointGoblin);
    }
    else{
      return;
    }
  }
  else if(nextCreature == 4){
    BlueMen* pointBlueMen = new BlueMen;
    pointBlueMen->setName(creatureName);
    if(player == 1){
      addCreatureOne(pointBlueMen);
    }
    else if(player == 2){
      addCreatureTwo(pointBlueMen);
    }
    else{
      return;
    }
  }
  else if(nextCreature == 5){
    Shadow* pointShadow = new Shadow;
    pointShadow->setName(creatureName);
    if(player == 1){
      addCreatureOne(pointShadow);
    }
    else if(player == 2){
      addCreatureTwo(pointShadow);
    }
    else{
      return;
    }
  }
  else{
    return;
  }
}


void Tournament::lineupSelector(unsigned int player){

  std::cout << "Player " << player << " select a creature from the following list using the indicated numbers:" << std::endl;
  std::cout << "\t1. Barbarian" << std::endl;
  std::cout << "\t2. Reptile People" << std::endl;
  std::cout << "\t3. Goblin" << std::endl;
  std::cout << "\t4. Blue Men" << std::endl;
  std::cout << "\t5. The Shadow" << std::endl;
  if(player == 1){
    for(unsigned int i=0;i<lineupSize;i++){
      unsigned int playerChoice = 0;
      std::string creatureName;
      std::cout << "Creature " << i+1 << "'s name: ";
      std::cin.ignore();
      std::getline(std::cin, creatureName);
      std::cout << "Select creature " << i+1 << " of your lineup:";
      std::cin >> playerChoice;
      creatureSelector(player, playerChoice, creatureName);
      std::cout << std::endl;
    }
  }
  else if(player == 2){
    for(unsigned int i=0;i<lineupSize;i++){
      unsigned int playerChoice = 0;
      std::string creatureName;
      std::cout << "Creature " << i+1 << "'s name: ";
      std::cin.ignore();
      std::getline(std::cin, creatureName);
      std::cout << "Select creature " << i+1 << " of your lineup:";
      std::cin >> playerChoice;
      creatureSelector(player, playerChoice, creatureName);
      std::cout << std::endl;
    }
  }
  else{
    return;
  }
}

void Tournament::addLoser(Creature* loser){
  Losers* newLoser = new Losers(loser);
  newLoser->next = top;
  top = newLoser; // Pointing top to the new Losers we created
}

Creature* Tournament::removeLoser(){
  if(top == NULL){ // Stack is empty, just returning an error
    throw std::string("No more creatures found. Error ");
  }
  Losers* removeCreature = top; // We are caching the top node here
  Creature* returnCreature = top->loser; // Storing the number for returning later
  top = top->next; // Setting top to the next node
  delete removeCreature; // Removing the node that was top was previously pointing to
  return returnCreature; // Returning the number that was stored in the removed node
}

void Tournament::displayRosterOne(){
  if(frontOne == NULL){
    return;
  }
  std::cout << "Player 1's Roster" << std::endl;
  RosterOne* display = frontOne;
  unsigned int i = 1;
  while(display != NULL){
    std::cout << "\t" << i << ". " << display->combatant->getType() << " named " << display->combatant->getName() << std::endl;
    i++;
    display = display->next;
  }
}

void Tournament::addCreatureOne(Creature* inCreature){
  if(backOne == NULL){ // No items in the queue yet, need to set FrontOne and BackOne
    frontOne = backOne = new RosterOne(inCreature);
  }
  else{ // Looks like something is in the queue, we can set next and prev now
    RosterOne* newRoster = new RosterOne(inCreature);
    newRoster->prev = backOne;
    backOne->next = newRoster;
    backOne = newRoster;
    newRoster = NULL;
  }
}

Creature* Tournament::removeCreatureOne(){
  Creature* rmvCombatant = NULL;
  if(frontOne == NULL && backOne == NULL){ // Uh oh queue is emtpy, need to warn the user
    std::cout << "No more creatures found.";
    return NULL;
  } else if(frontOne == backOne && frontOne != NULL){ // Looks like we are at the last node
    rmvCombatant = frontOne->combatant; // Caching the last number
    delete frontOne; // Deleting the last node
    frontOne = backOne =  NULL; // Setting both frontOne and backOne to NULL to be cautious
    return rmvCombatant;
  } else {
    RosterOne* newRoster = frontOne->next;
    rmvCombatant = frontOne->combatant;
    delete frontOne;
    frontOne = newRoster;
    newRoster = NULL;
    return rmvCombatant;
  }
}

void Tournament::displayRosterTwo(){
  if(frontTwo == NULL){
    return;
  }
  std::cout << "Player 2's Roster" << std::endl;
  RosterTwo* display = frontTwo;
  unsigned int i = 1;
  while(display != NULL){
    std::cout << "\t" << i << ". " << display->combatant->getType() << " named " << display->combatant->getName() << std::endl;
    i++;
    display = display->next;
  }
}

void Tournament::addCreatureTwo(Creature* inCreature){
  if(backTwo == NULL){ // No items in the queue yet, need to set FrontTwo and BackTwo
    frontTwo = backTwo = new RosterTwo(inCreature);
  }
  else{ // Looks like something is in the queue, we can set next and prev now
    RosterTwo* newRoster = new RosterTwo(inCreature);
    newRoster->prev = backTwo;
    backTwo->next = newRoster;
    backTwo = newRoster;
    newRoster = NULL;
  }
}


Creature* Tournament::removeCreatureTwo(){
  Creature* rmvCombatant = NULL;
  if(frontTwo == NULL && backTwo == NULL){ // Uh oh queue is emtpy, need to warn the user
    std::cout << "No more creatures found.";
    return NULL;
  } else if(frontTwo == backTwo && frontTwo != NULL){ // Looks like we are at the last node
    rmvCombatant = frontTwo->combatant; // Caching the last number
    delete frontTwo; // Deleting the last node
    frontTwo = backTwo =  NULL; // Setting both frontTwo and backTwo to NULL to be cautious
    return rmvCombatant;
  } else {
    RosterTwo* newRoster = frontTwo->next;
    rmvCombatant = frontTwo->combatant;
    delete frontTwo;
    frontTwo = newRoster;
    newRoster = NULL;
    return rmvCombatant;
  }
}

void Tournament::startTournament(){
  while(frontOne != NULL && frontTwo != NULL){
    Creature* fighterOne = removeCreatureOne();
    Creature* fighterTwo = removeCreatureTwo();
    Creature* nextLoser = combatControl.battlePhase(fighterOne, fighterTwo);
    addLoser(nextLoser);
    if(top->loser == fighterOne){
      playerTwoWins++;
      std::cout << fighterTwo->getName() << " healed after winning and now has " << fighterTwo->getStrength() << " strength." << std::endl;
      fighterTwo->heal();
      addCreatureTwo(fighterTwo);
    }
    else if(top->loser == fighterTwo){
      playerOneWins++;
      fighterOne->heal();
      std::cout << fighterOne->getName() << " healed after winning and now has " << fighterOne->getStrength() << " strength." << std::endl;
      addCreatureOne(fighterOne);
    }
  }
}

void Tournament::determinePlaces(){
  if(backOne == NULL && backTwo == NULL){
    throw std::string("Something went horribly wrong");
  }
  if(playerOneWins > playerTwoWins){
    unsigned int lineupCounter = playerOneWins - playerTwoWins;
    std::cout << "Player One has won by " << lineupCounter << " point(s)!" << std::endl;    
    RosterOne* displayer = frontOne;
    if(lineupCounter == 3){
      std::cout << "\t1st place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;
      displayer = displayer->next;
      std::cout << "\t2nd place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;    
      displayer = displayer->next;
      std::cout << "\t3rd place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;    
    }
    else if(lineupCounter == 2){
      Creature* third = removeLoser();
      std::cout << "\t1st place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;
      displayer = displayer->next;
      std::cout << "\t2nd place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;    
      std::cout << "\t3rd place goes to " << third->getType() << " named " << third->getName() << std::endl;
    }
    else if(lineupCounter == 1){
      Creature* second = removeLoser();
      Creature* third = removeLoser();
      std::cout << "\t1st place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;
      std::cout << "\t2nd place goes to " << second->getType() << " named " << second->getName() << std::endl;
      std::cout << "\t3rd place goes to " << third->getType() << " named " << third->getName() << std::endl;
    }else{
      return;
    }
  }
  else if(playerTwoWins > playerOneWins){
    unsigned int lineupCounter = playerTwoWins - playerOneWins;
    std::cout << "Player Two has won by " << lineupCounter << " point(s)!" << std::endl;
    RosterTwo* displayer = frontTwo;
    if(lineupCounter == 3){
      std::cout << "\t1st place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;
      displayer = displayer->next;
      std::cout << "\t2nd place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;    
      displayer = displayer->next;
      std::cout << "\t3rd place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;    
    }
    else if(lineupCounter == 2){
      Creature* third = removeLoser();
      std::cout << "\t1st place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;
      displayer = displayer->next;
      std::cout << "\t2nd place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;    
      std::cout << "\t3rd place goes to " << third->getType() << " named " << third->getName() << std::endl;
    }
    else if(lineupCounter == 1){
      Creature* second = removeLoser();
      Creature* third = removeLoser();
      std::cout << "\t1st place goes to " << displayer->combatant->getType() << " named " << displayer->combatant->getName() << std::endl;
      std::cout << "\t2nd place goes to " << second->getType() << " named " << second->getName() << std::endl;
      std::cout << "\t3rd place goes to " << third->getType() << " named " << third->getName() << std::endl;
    }else{
      return;
    }
  }
}