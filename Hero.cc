#include <iostream>
using namespace std;

#include "Hero.h"

int random(int);

Hero::Hero(char av, int s, int ar) : Player(av, s, ar, 15) {}

void Hero::setPosition() {
  int r = random(5) + 1;

  if (r == 1) {
    x = 1;
    y = 1;
  }
  else if (r == 2) {
    x = 2;
    y = 1;
  }
  else if (r == 3) {
    x = 3;
    y = 1;
  }
  else if (r == 4) {
    x = 4;
    y = 1;
  }
  else {
    x = 5;
    y = 1;
  }
}

int Hero::updateX() {
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

int Hero::updateY() {
  y += 1;

  if ((y == 26 && x == 1) || (y == 26 && x == 5)) {
    y -= 1;
  }
  return y;
}

void Hero::collision(Player* p) {
  if (p->getAvatar() == 'd' || p->getAvatar() == 'b' || p->getAvatar() == 'p') {
    int damage = p->getStrength() - armor;
    health -= damage;
  }

  if (p->getAvatar() == 'D') {
    health = 0;
  }

  if (health <= 0) {
    down =  true;
  }
}
