#include <iostream>
using namespace std;

#include "Dragon.h"

int random(int);

Dragon::Dragon() : Player('D', 0, 0, 100) {}

void Dragon::setPosition() {
  x = 3;
  y = 25;
}

int Dragon::updateX() {
  if (x == 2) {
    x += 1;
  }
  else if (x == 4) {
    x -= 1;
  }
  else {
    int r = random(2) + 1;

    if (r == 1) {
      x += 1;
    }
    else {
      x -= 1;
    }
  }
  return x;
}

int Dragon::updateY() {
  return y;
}

void Dragon::collision(Player* p) {
  if (p->getAvatar() == 'T' || p->getAvatar() == 'H') {
    p->setHealthLevel(0);
  }
}
