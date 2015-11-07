#include "creature.hpp"

Barbarian::Barbarian(){
  armor = 0;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 6;
  defenseDiceQty = 2;
  defenseDiceSides = 6;
}
unsigned int Barbarian::attack(){
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
  strength = incDmg - this->getArmor();
  return strength;
}


ReptilePeople::ReptilePeople(){
  armor = 7;
  strength = 18;
  attackDiceQty = 3;
  attackDiceSides = 6;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
}
unsigned int ReptilePeople::attack(){
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
  strength = incDmg - this->getArmor();
  return strength;
}

BlueMen::BlueMen(){
  armor = 3;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 10;
  defenseDiceQty = 3;
  defenseDiceSides = 6;
}
unsigned int BlueMen::attack(){
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
  strength = incDmg - this->getArmor();
  return strength;
}

Shadow::Shadow(){
  armor = 0;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 10;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
}
unsigned int Shadow::attack(){
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
    return strength;;
  }
  else{
    strength = incDmg - this->getArmor();
  }
  return strength;
}

Goblin::Goblin(){
  armor = 3;
  strength = 8;
  attackDiceQty = 2;
  attackDiceSides = 6;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
  achilles = false;
}
unsigned int Goblin::attack(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = rand() % attackDiceSides + 1;
    std::cout << "Goblin rolled D" << i+1 << " for " << tmp << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  if(rollTotal == 12){
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
    strength = (incDmg/2) - this->getArmor();
  }
  else{
    strength = incDmg - this->getArmor();
  }
  return strength;
}