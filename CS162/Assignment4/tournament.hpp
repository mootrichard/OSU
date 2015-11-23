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
