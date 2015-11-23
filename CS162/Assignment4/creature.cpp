// Author: Richard Moot
// Date: 11/08/2015
// Description: The creature classes all inherit from the Creature abstract class
//  Classes with special abilities redefined their behavior on specific methods. 
//  Such as goblins applying Achilles on getting a 12 or Shadow being able to avoid
//  damage.

#include "creature.hpp"

// This is used to tell what type the creature is
std::string Creature::getType() const{
  return this->type;
}

// Used to report the creatures current strength
int Creature::getStrength() {
  return this->strength;
}

void Creature::setName(std::string creatureName){
  this->name = creatureName;
}

std::string Creature::getName(){
  return this->name;
}

void Creature::heal(){
  this->strength = this->strength + (this->strength/2);
}

Barbarian::Barbarian(){
  type = "Barbarian";
  armor = 0;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 6;
  defenseDiceQty = 2;
  defenseDiceSides = 6;
}

// Attack method for our Barbarian
unsigned int Barbarian::attack(Creature* enemy){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){ // Totaling rolls for all dice
    unsigned int tmp = rand() % attackDiceSides + 1;
    rollTotal += tmp;
  }
  return rollTotal;
}
// Defense method for our Barbarian, just calculating total roll for all dice
unsigned int Barbarian::defense(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = rand() % defenseDiceSides + 1;
    rollTotal += tmp;
  }
  return rollTotal;
}

int Barbarian::getArmor(){
  return armor;
}
// This is so we can evaluate the damage that should be done to strength
int Barbarian::takeDamage(int incDmg){
  if(incDmg <= this->getArmor()){
    return 0; // Our armor has protected us
  }
  else{
    this->strength -= (incDmg - this->getArmor()); // Damage has been done, need to adjust strength
  }
  return incDmg - this->getArmor(); // Returning the total damage that was done
}


ReptilePeople::ReptilePeople(){
  type = "Reptile People";
  armor = 7;
  strength = 18;
  attackDiceQty = 3;
  attackDiceSides = 6;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
}

// Attack method for our ReptilePeople
unsigned int ReptilePeople::attack(Creature* enemy){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){ // Totaling rolls for all dice
    unsigned int tmp = rand() % attackDiceSides + 1;
    rollTotal += tmp;
  }
  return rollTotal;
}

// Defense method for our ReptilePeople
unsigned int ReptilePeople::defense(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = rand() % defenseDiceSides + 1;
    rollTotal += tmp;
  }
  return rollTotal;
}

int ReptilePeople::getArmor(){
  return armor;
}
// This is so we can evaluate the damage that should be done to strength
int ReptilePeople::takeDamage(int incDmg){
  if(incDmg <= this->getArmor()){
    return 0; // Our armor has protected us
  }
  else{
    this->strength -= incDmg - this->getArmor();
  }
  return incDmg - this->getArmor(); // Returning the total damage that was done
}

BlueMen::BlueMen(){
  type = "Blue Men";
  armor = 3;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 10;
  defenseDiceQty = 3;
  defenseDiceSides = 6;
}
// Attack method for our BlueMen
unsigned int BlueMen::attack(Creature* enemy){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){ // Totaling rolls for all dice
    unsigned int tmp = rand() % attackDiceSides + 1;
    rollTotal += tmp;
  }
  return rollTotal;
}
// Defense method for our BlueMen
unsigned int BlueMen::defense(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = rand() % defenseDiceSides + 1;
    rollTotal += tmp;
  }
  return rollTotal;
}

int BlueMen::getArmor(){
  return armor;
}
// This is so we can evaluate the damage that should be done to strength
int BlueMen::takeDamage(int incDmg){
  if(incDmg <= this->getArmor()){
    return 0; // Our armor has protected us
  }
  else{
    this->strength -= (incDmg - this->getArmor());
  }
  return incDmg - this->getArmor(); // Returning the total damage that was done
}

Shadow::Shadow(){
  type = "The Shadow";
  armor = 0;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 10;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
}
// Attack method for our Shadow
unsigned int Shadow::attack(Creature* enemy){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){ // Totaling rolls for all dice
    unsigned int tmp = rand() % attackDiceSides + 1;
    rollTotal += tmp;
  }
  return rollTotal;
}
// Defense method for our Shadow
unsigned int Shadow::defense(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = rand() % defenseDiceSides + 1;
    rollTotal += tmp;
  }
  return rollTotal;
}

int Shadow::getArmor(){
  return armor;
}
// This is so we can evaluate the damage that should be done to strength
int Shadow::takeDamage(int incDmg){
  unsigned int dodge = rand() % 100 + 1;
  if(dodge >= 50){
    return 0; // We successfully evaded their attack! Hooray!
  }
  else{
    this->strength -= (incDmg - this->getArmor());
  }
  return incDmg - this->getArmor(); // Returning the total damage that was done
}

Goblin::Goblin(){
  type = "Goblin";
  armor = 3;
  strength = 8;
  attackDiceQty = 2;
  attackDiceSides = 6;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
  achilles = false;
}
// Attack method for our Goblin
unsigned int Goblin::attack(Creature* enemy){
  unsigned int gobRollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){ // Totaling rolls for all dice
    unsigned int tmp = rand() % attackDiceSides + 1;
    gobRollTotal += tmp;
  }
  if(gobRollTotal == 12 && (enemy->getType() != "goblin")){ // We rolled a 12, going to leave Achilles appliced until the end of combat
    achilles = true;
    return gobRollTotal;
  }
  else{
    return gobRollTotal;
  }
}
// Defense method for our Goblin
unsigned int Goblin::defense(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = rand() % defenseDiceSides + 1;
    rollTotal += tmp;
  }
  return rollTotal;
}

int Goblin::getArmor(){
  return armor;
}
// This is so we can evaluate the damage that should be done to strength
int Goblin::takeDamage(int incDmg){
  if(achilles == true){ // Achilles is applied, so we need to reduce their damage by half
    if((incDmg/2) < this->getArmor()){
      return 0;
    }
    this->strength -= (incDmg/2) - this->getArmor();
    return (incDmg/2) - this->getArmor();
  }
  else{
    this->strength -= incDmg - this->getArmor();
  }
  return incDmg - this->getArmor(); // Returning the total damage that was done
}
bool Goblin::getAchilles(){
  return this->achilles;
}