#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <iostream>
#include <cstdlib>

class Creature{
  public:
    unsigned virtual int attack() = 0;
    unsigned virtual int defense() = 0;
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
    unsigned int attack();
    unsigned int defense();
    int getArmor();
    int takeDamage();
};


class  ReptilePeople: public Creature{
  public:
    ReptilePeople();
    unsigned int attack();
    unsigned int defense();
    int getArmor();
    int takeDamage();
};

class  BlueMen: public Creature{
  public:
    BlueMen();
    unsigned int attack();
    unsigned int defense();
    int getArmor();
    int takeDamage();
};

class Shadow: public Creature{
  public:
    Shadow();
    unsigned int attack();
    unsigned int defense();
    int getArmor();
    int takeDamage();
};

class Goblin: public Creature {
  public:
    Goblin();
    unsigned int attack();
    unsigned int defense();
    int getArmor();
    int takeDamage();
};

#endif // CREATURE_HPP
