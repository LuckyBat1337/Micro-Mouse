//  This file is "main.cpp", arduino looks for a file with file ending ".ino" which is why it has been renamed 
//  to Micromouse.ino (from my understanding)

//  Wrong again, need to rewrite file named Main.cpp, this file will be used for hardware builds while Main.cpp is 
//  used for simulations of code
#include <Arduino.h> //various things needing inclusion, arduino for string and boolean and such replacing iostream (im not sure about this? ZZ )
#include "Configuration.h"
#include "API.h"

#ifndef SIMULATOR_MODE
    #include "Motors.h"
    #include "Sensors.h"
#endif

void setup(){
/*   not 100% sure on 115200, according to google it is the max rate a ESP32 can read at, 
     "initializes the ESP32's default hardware serial port (UART0) for communication at a speed of 115,200 bits per second (baud)" 
     https://randomnerdtutorials.com/esp32-uart-communication-serial-arduino/#:~:text=When%20you%20use%20Serial.,UART%201%20and%20UART%202.
*/
/*
 Serial.begin(115200);
 #ifndef SIMULATOR_MODE
    Motors::init();
    Sensors::init();
 #else
    //simulator initalization, cant be bothered will do later ZZ
 #endif
 API::ackReset();
}

void loop(){
//algorithm section, runs same on real robot and simulator.
//simple simple algorithm to test later if anything will move in a simulation
    if(!API::wallLeft()){
        API::turnLeft();
        API::moveForward();
    }
    else if (!API::wallFront()){
        API::moveForward();
    }
    else {
        API::turnRight(); //added this bit incase it gets stuck in a dead end or corner
                          // |-------------
                          // | Ö                   Robot will turn right if this happens because there is a wall on the left and a wall in front forcing the right move (Ö is the mouse)
                          // |
    }
}
