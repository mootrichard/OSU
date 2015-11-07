#ifndef COMBAT_HPP
#define COMBAT_HPP
#include "creature.hpp"

class Combat{
  public:
    void battlePhase(Creature& first, Creature& second);
  private:
    unsigned int turn;
};

#endif // COMBAT_HPP
