#ifndef DRAGON_H
#define DRAGON_H

#include "Player.h"

//************************************************************************//
// Purpose: Derived class from Player.                                    //
//          Contains Dragon default constructor.                          //
//          Contains setPosition() function to set initial position of    //
//          Dragon.                                                       //
//          Contains updateX() and updateY() functions to update Dragon's //
//          x and y coordinates.                                          //
//          Contains collision() function to handle any collisions.       //
//************************************************************************//

class Dragon : public Player {
  public:
    Dragon();
    void setPosition();
    int updateX();
    int updateY();
    void collision(Player*);
};

#endif
