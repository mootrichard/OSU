#include "creature.hpp"

std::string Creature::getType() const{
  return this->type;
}

int Creature::getStrength() const{
  return this->strength;
}

Barbarian::Barbarian(){
  type = "barbarian";
  armor = 0;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 6;
  defenseDiceQty = 2;
  defenseDiceSides = 6;
}
unsigned int Barbarian::attack(Creature* enemy){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = rand() % attackDiceSides + 1;
    std::cout << "Barbarian rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  return rollTotal;
}
unsigned int Barbarian::defense(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = rand() % defenseDiceSides + 1;
    std::cout << "Barbarian rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For a defense of " << rollTotal << std::endl;
  return rollTotal;
}
int Barbarian::getArmor(){
  return armor;
}
unsigned int Barbarian::takeDamage(unsigned int incDmg){
  if(incDmg <= this->getArmor()){
    return 0;
  }
  else{
    this->strength -= (incDmg - this->getArmor());
  }
  return incDmg - this->getArmor();
}


ReptilePeople::ReptilePeople(){
  type = "reptile";
  armor = 7;
  strength = 18;
  attackDiceQty = 3;
  attackDiceSides = 6;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
}
unsigned int ReptilePeople::attack(Creature* enemy){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = rand() % attackDiceSides + 1;
    std::cout << "Reptile People rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  return rollTotal;
}
unsigned int ReptilePeople::defense(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = rand() % defenseDiceSides + 1;
    std::cout << "Reptile People rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For a defense of " << rollTotal << std::endl;
  return rollTotal;
}
int ReptilePeople::getArmor(){
  return armor;
}
unsigned int ReptilePeople::takeDamage(unsigned int incDmg){
  if(incDmg <= this->getArmor()){
    return 0;
  }
  else{
    this->strength -= incDmg - this->getArmor();
  }
  return incDmg - this->getArmor();
}

BlueMen::BlueMen(){
  type = "blueMen";
  armor = 3;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 10;
  defenseDiceQty = 3;
  defenseDiceSides = 6;
}
unsigned int BlueMen::attack(Creature* enemy){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = rand() % attackDiceSides + 1;
    std::cout << "Blue Men rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  return rollTotal;
}
unsigned int BlueMen::defense(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = rand() % defenseDiceSides + 1;
    std::cout << "Blue Men rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For a defense of " << rollTotal << std::endl;
  return rollTotal;
}
int BlueMen::getArmor(){
  return armor;
}
unsigned int BlueMen::takeDamage(unsigned int incDmg){
  if(incDmg <= this->getArmor()){
    return 0;
  }
  else{
    this->strength -= (incDmg - this->getArmor());
  }
  return incDmg - this->getArmor();
}

Shadow::Shadow(){
  type = "shadow";
  armor = 0;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 10;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
}
unsigned int Shadow::attack(Creature* enemy){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = rand() % attackDiceSides + 1;
    std::cout << "Shadow rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  return rollTotal;
}
unsigned int Shadow::defense(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = rand() % defenseDiceSides + 1;
    std::cout << "Shadow rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For a defense of " << rollTotal << std::endl;
  return rollTotal;
}
int Shadow::getArmor(){
  return armor;
}
unsigned int Shadow::takeDamage(unsigned int incDmg){
  unsigned int dodge = rand() % 100 + 1;
  if(dodge >= 50){
    std::cout << "Dodged the attack!" << std::endl; 
    return strength;;
  }
  else{
    this->strength -= (incDmg - this->getArmor());
  }
  return incDmg - this->getArmor();
}

Goblin::Goblin(){
  type = "goblin";
  armor = 3;
  strength = 8;
  attackDiceQty = 2;
  attackDiceSides = 6;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
  achilles = false;
}
unsigned int Goblin::attack(Creature* enemy){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = rand() % attackDiceSides + 1;
    std::cout << "Goblin rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  if((rollTotal == 12) && (enemy->getType() != "goblin")){
    std::cout << "\tAchilles has been applied!" << std::endl;
    achilles = true;
  }
  return rollTotal;
}
unsigned int Goblin::defense(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = rand() % defenseDiceSides + 1;
    std::cout << "Goblin rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For a defense of " << rollTotal << std::endl;
  return rollTotal;
}
int Goblin::getArmor(){
  return armor;
}
unsigned int Goblin::takeDamage(unsigned int incDmg){
  if(achilles){
    if((incDmg/2) < this->getArmor()){
      return strength;
    }
    this->strength -= (incDmg/2) - this->getArmor();
    return (incDmg/2) - this->getArmor();
  }
  else{
    this->strength -= incDmg - this->getArmor();
  }
  return incDmg - this->getArmor();
}