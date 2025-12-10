/*
  API.cpp is where we should have a implementation of the API interface. (maybe? ZZ)
  
  IMPORTANT NOTE!!!!!!!! OBS!!!!!
  This file contains two completely separate implementations.
  The preprocessor directives (#ifdef SIMULATOR_MODE, row 14 right now dont forget to change what row im refering to end of project ZZ ) 
  determine which block of code is compiled. This allows the same source files to run on the desktop simulator and the physical ESP32.
 */
#include "API.h"

// if we are compiling for hardware, we need access to the motor drivers
#ifndef SIMULATOR_MODE
    #include "Motors.h"
    #include "Sensors.h" // Assuming this will be created I don't have time right now, will get to it hopefully before christmas? ZZ 

    // map cell units to millimeters
    const float MM_PER_CELL = 180.0;
#endif





// implementation 1, simulator mode
#ifdef SIMULATOR_MODE

int API::mazeWidth() {
    Serial.println("mazeWidth"); // Send command to stdout
    String response = Serial.readStringUntil('\n'); // Read response from stdin (process repeats for other parts too just lazy to write it out everywhere)
    return response.toInt();
}

int API::mazeHeight() {
    Serial.println("mazeHeight");
    String response = Serial.readStringUntil('\n');
    return response.toInt();
}

bool API::wallFront() {
    Serial.println("wallFront");
    String response = Serial.readStringUntil('\n');
    return (response == "true");
}

bool API::wallRight() {
    Serial.println("wallRight");
    String response = Serial.readStringUntil('\n');
    return (response == "true");
}

bool API::wallLeft() {
    Serial.println("wallLeft");
    String response = Serial.readStringUntil('\n');
    return (response == "true");
}

void API::moveForward(int distance) {
    Serial.print("moveForward ");
    Serial.println(distance);
    // This is a BLOCKING call in simulation.
    // waits for "ack" (success) or "crash" (failure).
    String response = Serial.readStringUntil('endl'); //???????????????????? why cant i use endl ???????????? ZZ IMPORTANT ZZ CODE WILL MAYBE CRASH ZZ
    if (response.indexOf("crash")!= -1) {
        // In a real scenario, we should handle error logic here.
        // For now, we allow the simulator to handle the crash state. Change later if time/needed
        while(1); // stop runtime/execution
    }
}

void API::moveForwardHalf(int distance) {
    Serial.print("moveForwardHalf ");
    Serial.println(distance);
    String response = Serial.readStringUntil('\n');
    if (response.indexOf("crash")!= -1) while(1);
}

void API::turnRight() {
    Serial.println("turnRight");
    String response = Serial.readStringUntil('\n');
}

void API::turnLeft() {
    Serial.println("turnLeft");
    String response = Serial.readStringUntil('\n');
}

void API::setWall(int x, int y, char direction) {
    Serial.print("setWall "); Serial.print(x); Serial.print(" ");
    Serial.print(y); Serial.print(" "); Serial.println(direction);
}

void API::clearWall(int x, int y, char direction) {
    Serial.print("clearWall "); Serial.print(x); Serial.print(" ");
    Serial.print(y); Serial.print(" "); Serial.println(direction);
}

void API::setColor(int x, int y, char color) {
    Serial.print("setColor "); Serial.print(x); Serial.print(" ");
    Serial.print(y); Serial.print(" "); Serial.println(color);
}

void API::clearColor(int x, int y) {
    Serial.print("clearColor "); Serial.print(x); Serial.print(" ");
    Serial.println(y);
}

void API::clearAllColor() {
    Serial.println("clearAllColor");
}

void API::setText(int x, int y, String text) {
    Serial.print("setText "); Serial.print(x); Serial.print(" ");
    Serial.print(y); Serial.print(" "); Serial.println(text);
}

void API::clearText(int x, int y) {
    Serial.print("clearText "); Serial.print(x); Serial.print(" ");
    Serial.println(y);
}

void API::clearAllText() {
    Serial.println("clearAllText");
}

bool API::wasReset() {
    Serial.println("wasReset");
    String response = Serial.readStringUntil('\n');
    return (response == "true");
}

void API::ackReset() {
    Serial.println("ackReset");
    String response = Serial.readStringUntil('\n');
}




// implementation 2!!! hardware mode (ESP32 mode)
#else 

// in hardware mode, we must map abstract commands to physical driver calls.

int API::mazeWidth() {
    // the robot doesn't know the maze size implicitly unless configured.
    // standard Micromouse mazes are 16x16 therefor mazeWidth and mazeHeight will be 16
    return 16; 
}

int API::mazeHeight() {
    return 16; // height in form of matrix, not physically wall height
}

bool API::wallFront() {
    // read the front sensor
    // in the "Sensors" module (to be added ZZ ), we will read ADC values.
    // here we define a thershold for wall detection (e.g. 100mm).
    return Sensors::readFrontDistanceMM() < 100;
}

bool API::wallRight() {
    return Sensors::readRightDistanceMM() < 100;
}

bool API::wallLeft() {
    return Sensors::readLeftDistanceMM() < 100;
}

void API::moveForward(int distance) {
    // calculate the total millimeters to travel
    float targetMM = distance * MM_PER_CELL;
    
    // call the motor driver to execute movement
    // this function MUST BLOCK until the move is complete to match API behavior.
    Motors::driveDistance(targetMM); 
}

void API::moveForwardHalf(int distance) {
    float targetMM = distance * (MM_PER_CELL / 2.0);
    Motors::driveDistance(targetMM);
}

void API::turnRight() {
    // execute a 90 degree turn (zero radius turn)
    Motors::turn(90);
}

void API::turnLeft() {
    // execute a 90 degree turn (zero radius turn)
    Motors::turn(-90);
}

// visualization commands, no effect on the physical robot 
void API::setWall(int x, int y, char direction) {}
void API::clearWall(int x, int y, char direction) {}
void API::setColor(int x, int y, char color) {}
void API::clearColor(int x, int y) {}
void API::clearAllColor() {}
void API::setText(int x, int y, String text) {}
void API::clearText(int x, int y) {}
void API::clearAllText() {}

bool API::wasReset() {
    // on hardware, a reset usually happens via the EN button rebooting the CPU.
    // so "wasReset" in software context is rarely true unless persistent storage is used.
    return false; 
}

void API::ackReset() {
    // optionally blink an LED or beep a buzzer to acknowledge readiness? 
    // not hard to program but don't know how many I/O pins we have to work with and dont entirely understand ESP32 yet. (ZZ)
}

#endif
