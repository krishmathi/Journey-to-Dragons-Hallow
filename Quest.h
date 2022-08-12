#ifndef QUEST_H
#define QUEST_H

#include <list>
#include "View.h"
#include "Player.h"
#include "Hero.h"
#include "Dragon.h"
#include "Fighter.h"

//************************************************************************//
// Purpose: Contains Quest default constructor and destructor.            //
//          Contains update member function that implements program       //
//          control flow.                                                 //
//          Contains initPlayers member function that initializes         //
//          players in playerCollection.                                  //
//          Contains generateFighter member function to generate new      //
//          Fighter if needed each round.                                 //
//************************************************************************//

class Quest {
  public:
    Quest();
    ~Quest();
    bool isOver();
    void update();
    void initPlayers();
    void generateFighter();

  private:
    View<char> view;
    list<Player*> playerCollection;
    bool over;
    bool start;
};

#endif
