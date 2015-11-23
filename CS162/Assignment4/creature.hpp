// Author: Richard Moot
// Date: 11/08/2015
// Description: The creature classes all inherit from the Creature abstract class
//  Classes with special abilities redefined their behavior on specific methods. 
//  Such as goblins applying Achilles on getting a 12 or Shadow being able to avoid
//  damage.

#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <iostream>
#include <cstdlib>
#include <string>

class Creature{
  public:
    unsigned virtual int attack(Creature* enemy) = 0;
    unsigned virtual int defense() = 0;
    virtual int getArmor() = 0;
    virtual int takeDamage(int incDmg) = 0;
    std::string getType() const;
    int getStrength() ;
    void setName(std::string creatureName);
    std::string getName();
    void heal();
  protected:
    std::string type;
    std::string name;
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
    unsigned int attack(Creature* enemy);
    unsigned int defense();
    int getArmor();
    int takeDamage(int incDmg);
};


class  ReptilePeople: public Creature{
  public:
    ReptilePeople();
    unsigned int attack(Creature* enemy);
    unsigned int defense();
    int getArmor();
    int takeDamage(int incDmg);
};

class  BlueMen: public Creature{
  public:
    BlueMen();
    unsigned int attack(Creature* enemy);
    unsigned int defense();
    int getArmor();
    int takeDamage(int incDmg);
};

class Shadow: public Creature{
  public:
    Shadow();
    unsigned int attack(Creature* enemy);
    unsigned int defense();
    int getArmor();
    int takeDamage(int incDmg);
};

class Goblin: public Creature {
  public:
    Goblin();
    unsigned int attack(Creature* enemy);
    unsigned int defense();
    int getArmor();
    int takeDamage(int incDmg);
    bool getAchilles();
  protected:
    bool achilles;
};

#endif // CREATURE_HPP
