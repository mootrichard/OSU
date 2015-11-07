#include "creature.hpp"

Barbarian::Barbarian(){
  armor = 0;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 6;
  defenseDiceQty = 2;
  defenseDiceSides = 6;
}
unsigned int Barbarian::attackRoll(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = std::rand() % attackDiceSides + 1;
    std::cout << "Barbarian rolled D" << i+1 << " for " << attackDiceQty << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  return rollTotal;
}
unsigned int Barbarian::defenseRoll(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = std::rand() % defenseDiceSides + 1;
    std::cout << "Barbarian rolled D" << i+1 << " for " << defenseDiceQty << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For a defense of " << rollTotal << std::endl;
  return rollTotal;
}
int Barbarian::getArmor(){
  return armor;
}
int Barbarian::takeDamage(){

}


ReptilePeople::ReptilePeople(){
  armor = 7;
  strength = 18;
  attackDiceQty = 3;
  attackDiceSides = 6;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
}
unsigned int ReptilePeople::attackRoll(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = std::rand() % attackDiceSides + 1;
    std::cout << "Reptile People rolled D" << i+1 << " for " << attackDiceQty << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  return rollTotal;
}
unsigned int ReptilePeople::defenseRoll(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = std::rand() % defenseDiceSides + 1;
    std::cout << "Reptile People rolled D" << i+1 << " for " << defenseDiceQty << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For a defense of " << rollTotal << std::endl;
  return rollTotal;
}
int ReptilePeople::getArmor(){
  return armor;
}
int ReptilePeople::takeDamage(){

}

BlueMen::BlueMen(){
  armor = 3;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 10;
  defenseDiceQty = 3;
  defenseDiceSides = 6;
}
unsigned int BlueMen::attackRoll(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = std::rand() % attackDiceSides + 1;
    std::cout << "Blue Men rolled D" << i+1 << " for " << attackDiceQty << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  return rollTotal;
}
unsigned int BlueMen::defenseRoll(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = std::rand() % defenseDiceSides + 1;
    std::cout << "Blue Men rolled D" << i+1 << " for " << defenseDiceQty << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For a defense of " << rollTotal << std::endl;
  return rollTotal;
}
int BlueMen::getArmor(){
  return armor;
}
int BlueMen::takeDamage(){

}

Shadow::Shadow(){
  armor = 0;
  strength = 12;
  attackDiceQty = 2;
  attackDiceSides = 10;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
}
unsigned int Shadow::attackRoll(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = std::rand() % attackDiceSides + 1;
    std::cout << "Shadow rolled D" << i+1 << " for " << attackDiceQty << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  return rollTotal;
}
unsigned int Shadow::defenseRoll(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = std::rand() % defenseDiceSides + 1;
    std::cout << "Shadow rolled D" << i+1 << " for " << defenseDiceQty << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For a defense of " << rollTotal << std::endl;
  return rollTotal;
}
int Shadow::getArmor(){
  return armor;
}
int Shadow::takeDamage(){
  
}

Goblin::Goblin(){
  armor = 3;
  strength = 8;
  attackDiceQty = 2;
  attackDiceSides = 6;
  defenseDiceQty = 1;
  defenseDiceSides = 6;
}
unsigned int Goblin::attackRoll(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < attackDiceQty; i++){
    unsigned int tmp = std::rand() % attackDiceSides + 1;
    std::cout << "Goblin rolled D" << i+1 << " for " << attackDiceQty << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For an attack of " << rollTotal << std::endl;
  return rollTotal;
}
unsigned int Goblin::defenseRoll(){
  unsigned int rollTotal = 0;
  for(unsigned int i = 0; i < defenseDiceQty; i++){
    unsigned int tmp = std::rand() % defenseDiceSides + 1;
    std::cout << "Goblin rolled D" << i+1 << " for " << defenseDiceQty << std::endl;
    rollTotal += tmp;
  }
  std::cout << "For a defense of " << rollTotal << std::endl;
  return rollTotal;
}
int Goblin::getArmor(){
  return armor;
}
int Goblin::takeDamage(){

}