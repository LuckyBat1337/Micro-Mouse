/*
DEPRECATED FILE!!! only here for if inspiration is needed for other files

This file is needed to see that it can move with the help of the primitive function to get the distance <-------- OLD! use open-loop to start with, if time fix closed loop as i talk about here
It should be done by looking at the RPM in a brushless DC motor. <----- PID encoder!!! primitive integral derivative encoder!!!
*/

#include <iostream>
#include <string>
#include "move.h"
#include "API.h" // required for  simulator interaction

// initialize global state
// mouse starts bottom left (0,0) facing north
int cur_x = 0;
int cur_y = 0;
int facing = NORTH;

//runtime
void initMove() {
 API::setText(0,0, "START");
  //if using hardware, init GPIO and timers here pls leo
}

void updateCoordinates(){
  switch(facing) {
  case NORTH: cur_y += 1;
    break;
  case EAST: cur_x += 1;
    break;
  case SOUTH: cur_y -= 1;
    break;
  case WEST: cur_x -= 1; 
    break;
  }
}

void moveForward(){
  //execute the physical movement, on hardware  enable PID loop until encoders = 180mm;
  API::moveForward()
  updateCoordinates();
}

void turnLeft(){
  API::turnLeft();
  //update facing: (0 to 3), (1 to 0), etcetc, modulus to change direction 3 times aka one to the left
  facing = (facing + 3) % 4;
}

void turnRight(){
  API::turnRight();
  //update facing: (0 to 1), (1 to 2), etcetc, same principle but modulus 4 to change direction to the right
  facing = (facing + 1) % 4;
}

void turn180(){
  API::turnRight();
  API::turnRight();
  //update direction backwards (180 degrees)
  facing = (facing + 2) % 4;
}
