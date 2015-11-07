#ifndef COMBAT_HPP
#define COMBAT_HPP
#include <iostream>
#include "creature.hpp"

class Combat{
  public:
    Combat();
    void battlePhase(Creature& first, Creature& second);
  private:
    unsigned int turn;
};

#endif // COMBAT_HPP
