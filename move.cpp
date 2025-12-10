/*
Det behövs för att se till att den ska förflytta sig med hjälp av primitiva funktionen för att få distansen
Det ska göras genom att undersöka varvtalet i en borstlös ( ZZ ) DC motor. 

#include <iostream>
#include <string>
#include "constantVariables.h"

string cardinalDirection[4] = {"NORTH", "EAST", "SOUTH", "WEST"};
string (&curDir)[4] = currentDirection;
string (&carDir)[4] = cardinalDirection;

int main(){

}
*/

//revidering 2
#include "move.h"
#include "API.h" // required for  simulator interaction
//initialize global state
// mouse start
int cur_x = 0;
int cur_y = 0;
int facing = NORTH;
//runtime

void initMove() {

  
