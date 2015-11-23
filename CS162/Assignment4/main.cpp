#include "tournament.hpp"

int main(){
  // Need to seed our randomizer for fair rolls to take place.
  srand(time(NULL));

  Tournament battleBegin;
  Combat* commence = new Combat;
  battleBegin.displayRosterOne();
  battleBegin.displayRosterTwo();
  battleBegin.startTournament();
  battleBegin.determinePlaces();
  return 1;

}
