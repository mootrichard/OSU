#include "combat.hpp"

int main(){
  srand(time(NULL));

  Barbarian newBarb;
  ReptilePeople newReptile;
  Goblin newGoblin;
  BlueMen newBlueMen;
  Shadow newShadow;



  Barbarian* pointBarb = &newBarb;
  ReptilePeople* pointRep = &newReptile;
  Goblin* pointGoblin = &newGoblin;
  BlueMen* pointBlueMen = &newBlueMen;
  Shadow* pointShadow = &newShadow;

  Combat commence;
  commence.battlePhase(pointBarb, pointRep);
  commence.battlePhase(pointGoblin, pointBlueMen);
  commence.battlePhase(pointShadow, pointGoblin);
  commence.battlePhase(pointGoblin, pointGoblin);

}
