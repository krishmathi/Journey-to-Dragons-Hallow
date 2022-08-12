#ifndef PLAYER_H
#define PLAYER_H

//************************************************************************//
// Purpose: Base class for all players in Dragon's Hollow.                //
//          Contains Player default constructor.                          //
//          Contains getter functions for avatar, health, strength,       //
//          armor, down and x and y coordinates.                          //
//          Contains setter function to set position.                     //
//          Contains updateX() and updateY() functions to update player's //
//          x and y coordinates.                                          //
//          Contains collision() function to handle all collisions.       //
//************************************************************************//

class Player {
  public:
    Player(char, int, int, int);
    char getAvatar();
    int getHealth();
    int getStrength();
    int getArmor();
    int getX();
    int getY();
    bool isDown();
    void setHealthLevel(int);

    void print();

    virtual void setPosition() = 0;
    virtual int updateX() = 0;
    virtual int updateY() = 0;
    virtual void collision(Player*) = 0;

  protected:
    char avatar;
    int health;
    int strength;
    int armor;
    bool down;
    int x;
    int y;
};

#endif
