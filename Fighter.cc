#include <iostream>
using namespace std;

#include "Fighter.h"

int random(int);

Fighter::Fighter(char av, int s) : Player(av, s, 0, 5) {}

void Fighter::setPosition() {
  int r = random(5) + 1;

  if (r == 1) {
    x = 1;
    y = 25;
  }
  else if (r == 2) {
    x = 2;
    y = 25;
  }
  else if (r == 3) {
    x = 3;
    y = 25;
  }
  else if (r == 4) {
    x = 4;
    y = 25;
  }
  else {
    x = 5;
    y = 25;
  }
}

int Fighter::updateX() {
  int r = random(2) + 1;

  if (r == 1) {
    x += 1;
    if (x == 6) {
      x -= 1;
    }
    return x;
  }
  else {
    x -= 1;
    if (x == 0) {
      x += 1;
    }
    return x;
  }
}

int Fighter::updateY() {
  y -= 1;
  if (y == 0) {
    y += 1;
    down = true;
    return y;
  }
  return y;
}

void Fighter::collision(Player* p) {
  if (p->getAvatar() == 'H' || p->getAvatar() == 'T') {
    int damage = p->getStrength();
    health -= damage;

    if (health <= 0) {
      down = true;
    }
  }
}
