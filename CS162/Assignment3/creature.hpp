#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <iostream>
#include <cstdlib>

class Creature{
  public:
    unsigned virtual int attack() = 0;
    unsigned virtual int defense() = 0;
    virtual int getArmor() = 0;
    virtual unsigned int takeDamage(unsigned int incDmg) = 0;
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
    unsigned int takeDamage(unsigned int incDmg);
};


class  ReptilePeople: public Creature{
  public:
    ReptilePeople();
    unsigned int attack();
    unsigned int defense();
    int getArmor();
    unsigned int takeDamage(unsigned int incDmg);
};

class  BlueMen: public Creature{
  public:
    BlueMen();
    unsigned int attack();
    unsigned int defense();
    int getArmor();
    unsigned int takeDamage(unsigned int incDmg);
};

class Shadow: public Creature{
  public:
    Shadow();
    unsigned int attack();
    unsigned int defense();
    int getArmor();
    unsigned int takeDamage(unsigned int incDmg);
};

class Goblin: public Creature {
  public:
    Goblin();
    unsigned int attack();
    unsigned int defense();
    int getArmor();
    unsigned int takeDamage(unsigned int incDmg);
  private:
    bool achilles;
};

#endif // CREATURE_HPP
