/**
 * Author: Richard Moot
 * Date: November 23, 2015
 * Description: This tournament class is intended to allow two players to select creature to put in their
 *   rosters that will fight each other until a winner is determined. It will give 1st, 2nd, and 3rd place to the
 *   fighters as well as determine which player's team had won.
 */
#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP
#include "combat.hpp"

class Tournament {
  public:
    Tournament();
    Creature* getFrontOne();
    Creature* getFrontTwo();
    void setLineupSize();
    void creatureSelector(unsigned int player, unsigned int nextCreature, std::string creatureName);
    void lineupSelector(unsigned int player);

    void addLoser(Creature* loser);
    Creature* removeLoser();

    void displayRosterOne();
    void addCreatureOne(Creature* inCreature);
    Creature* removeCreatureOne();

    void displayRosterTwo();
    void addCreatureTwo(Creature* inCreature);
    Creature* removeCreatureTwo();

    void startTournament();
    void determinePlaces();
  protected:
    struct Losers {
      Losers(Creature* inLoser, Losers* n = NULL){
        loser = inLoser;
        next = n;
      };
      Creature* loser;
      Losers* next;
    };
    struct RosterOne {
      Creature* combatant;
      RosterOne* next;
      RosterOne* prev;
      RosterOne(Creature* inCombatant, RosterOne* n = NULL, RosterOne* p = NULL){
        combatant = inCombatant;
        next = n;
        prev = p;
      }
    };
    struct RosterTwo {
      Creature* combatant;
      RosterTwo* next;
      RosterTwo* prev;
      RosterTwo(Creature* inCombatant, RosterTwo* n = NULL, RosterTwo* p = NULL){
        combatant = inCombatant;
        next = n;
        prev = p;
      }
    };
  private:
    unsigned int playerOneWins;
    unsigned int playerTwoWins;
    Combat combatControl;
    unsigned int lineupSize;
    Losers* top;
    RosterOne* frontOne;
    RosterOne* backOne;
    RosterTwo* frontTwo;
    RosterTwo* backTwo;
};

#endif // TOURNAMENT_HPP
