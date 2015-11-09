// Author: Richard Moot
// Date: 11/08/2015
// Description: The combat class is used for handling combat for the Creatures classes
//   It will manage the battle phases by calling combat rolls and passing values between
//   creatures.

#ifndef COMBAT_HPP
#define COMBAT_HPP
#include <iostream>
#include "creature.hpp"

class Combat{
  public:
    Combat();
    void battlePhase(Creature* first, Creature* second);
    void resetTurn();
  private:
    unsigned int turn;
};

#endif // COMBAT_HPP
