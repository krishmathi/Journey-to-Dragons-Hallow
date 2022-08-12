#ifndef HERO_H
#define HERO_H

#include "Player.h"

//************************************************************************//
// Purpose: Derived class from Player.                                    //
//          Contains Hero default constructor.                            //
//          Contains setPosition() function to set initial position of    //
//          Hero.                                                         //
//          Contains updateX() and updateY() functions to update Hero's   //
//          x and y coordinates.                                          //
//          Contains collision() function to handle any collisions.       //
//************************************************************************//

class Hero : public Player {
  public:
    Hero(char, int, int);
    void setPosition();
    int updateX();
    int updateY();
    void collision(Player*);
};

#endif
