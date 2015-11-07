#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <iostream>
#include <cstdlib>

class Creature{
  public:
    unsigned virtual int attackRoll() = 0;
    unsigned virtual int defenseRoll() = 0;
    virtual int getArmor() = 0;
    virtual int takeDamage() = 0;
  protected:
    int armor;
    int strength;
    unsigned int attackDiceQty;
    unsigned int attackDiceSides;
    unsigned int defenseDiceQty;
    unsigned int defenseDiceSides;
};

class Barbarian: public Creature{
  public:
    Barbarian();
    unsigned int attackRoll();
    unsigned int defenseRoll();
    int getArmor();
    int takeDamage();
};


class  ReptilePeople: public Creature{
  public:
    ReptilePeople();
    unsigned int attackRoll();
    unsigned int defenseRoll();
    int getArmor();
    int takeDamage();
};

class  BlueMen: public Creature{
  public:
    BlueMen();
    unsigned int attackRoll();
    unsigned int defenseRoll();
    int getArmor();
    int takeDamage();
};

class Shadow: public Creature{
  public:
    Shadow();
    unsigned int attackRoll();
    unsigned int defenseRoll();
    int getArmor();
    int takeDamage();
};

class Goblin: public Creature {
  public:
    Goblin();
    unsigned int attackRoll();
    unsigned int defenseRoll();
    int getArmor();
    int takeDamage();
};

#endif // CREATURE_HPP
