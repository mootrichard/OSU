#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <iostream>

class Creature{
  public:
    Creature();
    virtual int attackRoll() = 0;
    virtual int defenseRoll() = 0;
    virtual int getArmor() = 0;
    virtual int takeDamage() = 0;
  protected:
    int armor;
    int strength;
    unsigned int diceQty;
    unsigned int diceSides;
};

class Barbarian: public Creature{
  public:
    Barbarian();
    int attackRoll();
    int defenseRoll();
    int getArmor();
    int takeDamage();
  protected:

  private:

};

class Goblin: public Creature {
  public:
    Goblin();
    int attackRoll();
    int defenseRoll();
    int getArmor();
    int takeDamage();
  protected:

  private:

};

class  ReptilePeople: public Creature{
  public:
    ReptilePeople();
    int attackRoll();
    int defenseRoll();
    int getArmor();
    int takeDamage();
  protected:

  private:

};

class  BlueMen: public Creature{
  public:
    BlueMen();
    int attackRoll();
    int defenseRoll();
    int getArmor();
    int takeDamage();
  protected:

  private:

};

class Shadow: public Creature{
  public:
    Shadow();
    int attackRoll();
    int defenseRoll();
    int getArmor();
    int takeDamage();
  protected:

  private:

};

#endif // CREATURE_HPP
