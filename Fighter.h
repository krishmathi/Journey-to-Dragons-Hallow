#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"

//************************************************************************//
// Purpose: Derived class from Player.                                    //
//          Contains Fighter default constructor.                         //
//          Contains setPosition() function to set initial position of    //
//          Fighter.                                                      //
//          Contains updateX() and updateY() functions to update Fighter's//
//          x and y coordinates.                                          //
//          Contains collision() function to handle any collisions.       //
//************************************************************************//

class Fighter : public Player {
  public:
    Fighter(char, int);
    void setPosition();
    int updateX();
    int updateY();
    void collision(Player*);
};

#endif
