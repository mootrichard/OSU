#ifndef COMBAT_HPP
#define COMBAT_HPP
#include <iostream>
#include "creature.hpp"

class Combat{
  public:
    Combat();
    void battlePhase(Creature* first, Creature* second);
    void playerChoices();
  private:
    unsigned int turn;
    unsigned int playerOne;
    unsigned int playerTwo;
};

#endif // COMBAT_HPP
