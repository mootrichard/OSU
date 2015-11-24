#include "tournament.hpp"

int main(){
  // Need to seed our randomizer for fair rolls to take place.
  srand(time(NULL));

  Tournament battleBegin;
  battleBegin.displayRosterOne();
  battleBegin.displayRosterTwo();
  battleBegin.startTournament();
  battleBegin.determinePlaces();
}
