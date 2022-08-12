#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
#include "Quest.h"

//************************************************************************//
// Purpose: Declare Quest (Control) object and initialize starting        //
//          players using initPlayers().                                  //
//          Calling Quest object's update function until quest is over.   //
// Author:  Krishna Mathiyaparanam (101101802)                            //
// Last Revised: April 23, 2020                                           //
//************************************************************************//

int random(int);

int main() {

  Quest quest;
  quest.initPlayers();

  srand( (unsigned)time( NULL ) );

  while (!quest.isOver()) {
    quest.update();
  }

  return 0;
}
