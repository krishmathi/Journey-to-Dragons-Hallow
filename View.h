#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Player.h"

using namespace std;

#define ROW_COUNT 7
#define COL_COUNT 28

int random(int);

template <class T>
class View {
  public:
    View();
    ~View();
    void print();
    void moveCharacter(char, int, int, int, int);
    void setCharacter(char, int, int);
    void removeCharacter(char, int, int);
  private:
    T** map;
};

template <class T>
View<T>::View() {
  map = new T*[ROW_COUNT];
  for (int i = 0; i < ROW_COUNT; ++i) {
    map[i] = new T[COL_COUNT];
  }

  for (int x = 0; x < ROW_COUNT; ++x) {
    map[x][0] = '|';
  }

  for (int i = 1; i < ROW_COUNT-1; ++i) {
    for (int x = 1; x < COL_COUNT-1; ++x) {
      map[i][x] = ' ';
    }
  }

  map[1][26] = '|';
  map[2][26] = '=';
  map[3][26] = '=';
  map[4][26] = '=';
  map[5][26] = '|';
  map[3][27] = '*';

  for (int y = 0; y < COL_COUNT; ++y) {
    map[0][y] = '-';
    map[6][y] = '-';
  }

  map[0][26] = '|';
  map[6][26] = '|';
  map[0][0] = '|';
  map[6][0] = '|';

}

template <class T>
View<T>::~View() {
  for (int i = 0; i < ROW_COUNT; ++i) {
    delete [] map[i];
  }
  delete [] map;
}

template <class T>
void View<T>::print() {
  for (int x = 0; x < ROW_COUNT; ++x) {
    for (int y = 0; y < COL_COUNT; ++y) {
      cout << map[x][y];
    }
    cout << endl;
  }
}

template <class T>
void View<T>::moveCharacter(char a, int oldX, int oldY, int newX, int newY) {
  if (map[newX][newY] == '+') {
    map[newX][newY] = '+';
    map[oldX][oldY] = ' ';
  }
  else if (map[newX][newY] != '+') {
    map[newX][newY] = a;
    map[oldX][oldY] = ' ';
  }
}

template <class T>
void View<T>::setCharacter(char a, int x, int y) {
  if (map[x][y] != '+') {
    map[x][y] = a;
  }
}

template <class T>
void View<T>::removeCharacter(char a, int x, int y) {
  if (a == 'H' || a == 'T') {
    map[x][y] = '+';
  }
  else {
    map[x][y] = ' ';
  }
}

#endif
