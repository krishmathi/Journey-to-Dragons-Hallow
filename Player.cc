#include "Player.h"
#include "View.h"

Player::Player(char av, int s, int ar, int h) : avatar(av), strength(s), armor(ar),
                                         health(h), x(0), y(0), down(false) {}

char Player::getAvatar() { return avatar; }
int Player::getHealth() { return health; }
int Player::getStrength() { return strength; }
int Player::getArmor() { return armor; }
bool Player::isDown() { return down; }
int Player::getX() { return x; }
int Player::getY() { return y; }

void Player::setHealthLevel(int level) {
  if (level < 0) {
    health = 0;
  }
  else {
    health = level;
  }

  if (health == 0) {
    down = true;
  }
}

void Player::print() {
  cout << "Avatar: " << avatar << " | Health: " << health << " | Strength: " << strength << " | Armor: " << armor << " | X: " << x << " | Y: " << y << endl;
}
