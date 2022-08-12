#include <iostream>
using namespace std;

#include "Quest.h"

Quest::Quest() : over(false), start(true)  {}

Quest::~Quest() {
  list<Player*>::iterator itr;

  for (itr = playerCollection.begin(); itr != playerCollection.end(); ++itr) {
    delete (*itr);
  }

}

bool Quest::isOver() { return over; }

void Quest::initPlayers() {
  Player* harold = new Hero('H', 5, 1);
  Player* timmy = new Hero('T', 3, 3);
  Player* dragon = new Dragon();

  harold->setPosition();
  timmy->setPosition();
  dragon->setPosition();

  playerCollection.push_back(harold);
  playerCollection.push_back(timmy);
  playerCollection.push_back(dragon);
}

void Quest::update() {
  list<Player*>::iterator itr, itr1, itr2, itr3, itr4;

  Player* timmy;  //Variable to hold Timmy.
  Player* harold; //Variable to hold Harold.
  Player* dragon; //Variable to hold Dragon.

  for (itr = playerCollection.begin(); itr != playerCollection.end(); ++itr) {
    //Start of Game - Leave Heros at left most edge and Dragon at right most edge.
    if (start) {
      for (itr1 = playerCollection.begin(); itr1 != playerCollection.end(); ++itr1) {
        view.setCharacter((*itr1)->getAvatar(), (*itr1)->getX(), (*itr1)->getY());
      }
      start = false;
      break;
    }

    int oldPosX, oldPosY, newPosX, newPosY;

    oldPosX = (*itr)->getX();
    oldPosY = (*itr)->getY();

    if (!(*itr)->isDown()) {
      for (itr2 = playerCollection.begin(); itr2 != playerCollection.end(); ++itr2) {
        if (oldPosX == (*itr2)->getX() && oldPosY == (*itr2)->getY()) {
          (*itr)->collision((*itr2));
          (*itr2)->collision((*itr));
        }
      }
      if ((*itr)->isDown()) {
        view.removeCharacter((*itr)->getAvatar(), oldPosX, oldPosY);
      }
      else {
        newPosX = (*itr)->updateX();
        newPosY = (*itr)->updateY();
        view.moveCharacter((*itr)->getAvatar(), oldPosX, oldPosY, newPosX, newPosY);
      }
    }
    else {
      view.removeCharacter((*itr)->getAvatar(), oldPosX, oldPosY);
    }
  }

  //Finding Main Characters from Player Collection.
  for (itr3 = playerCollection.begin(); itr3 != playerCollection.end(); ++itr3) {
    if ((*itr3)->getAvatar() == 'H') {
      harold = (*itr3);
    }
    else if ((*itr3)->getAvatar() == 'T') {
      timmy = (*itr3);
    }
    else if ((*itr3)->getAvatar() == 'D') {
      dragon = (*itr3);
    }
  }

  //Re-placing Main Characters so they are not covered by Fighters.
  if (timmy->isDown()) {
    view.removeCharacter(timmy->getAvatar(), timmy->getX(), timmy->getY());
  }
  else {
    view.setCharacter(timmy->getAvatar(), timmy->getX(), timmy->getY());
  }
  if (harold->isDown()) {
    view.removeCharacter(harold->getAvatar(), harold->getX(), harold->getY());
  }
  else {
    view.setCharacter(harold->getAvatar(), harold->getX(), harold->getY());
  }
  view.setCharacter(dragon->getAvatar(), dragon->getX(), dragon->getY());

  view.print();
  generateFighter();

  cout << endl;

  //Checking for Winner.
  if (harold->getY() == 26 && !harold->isDown()) {
    over = true;
    cout << "HAROLD WINS!" << endl;
  }
  else if (timmy->getY() == 26 && !timmy->isDown()) {
    over = true;
    cout << "TIMMY WINS!" << endl;
  }
  else if (harold->isDown() && timmy->isDown()) {
    over = true;
    cout << "BOTH HEROES ARE DEAD!" << endl;
  }
}

void Quest::generateFighter() {
  int r1 = random(10) + 1;
  int r2 = random(3) + 1;
  int strength;

  if (r1 <= 6 && r2 == 1) {
    int r3 = random(3) + 1;

    if (r3 == 1) {
      strength = 6;
    }
    else if (r3 == 2) {
      strength = 7;
    }
    else {
      strength = 8;
    }

    Player* dorc = new Fighter('d', strength);
    dorc->setPosition();
    playerCollection.push_back(dorc);
  }
  else if (r1 <= 6 && r2 == 2) {
    int r3 = random(4) + 1;

    if (r3 == 1) {
      strength = 8;
    }
    else if (r3 == 2) {
      strength = 9;
    }
    else if (r3 == 4) {
      strength = 10;
    }
    else {
      strength = 11;
    }

    Player* borc = new Fighter('b', strength);
    borc->setPosition();
    playerCollection.push_back(borc);
  }
  else if (r1 <= 6 && r2 == 3) {
    int r3 = random(2) + 1;

    if (r3 == 1) {
      strength = 4;
    }
    else {
      strength = 5;
    }

    Player* porc = new Fighter('p', strength);
    porc->setPosition();
    playerCollection.push_back(porc);
  }
}
