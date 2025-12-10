//  This file is "main.cpp", arduino looks for a file with file ending ".ino" which is why it has been renamed to Micromouse.ino (from my understanding)

#include <Arduino.h> //various things needing inclusion, arduino for string and boolean and such replacing iostream (im not sure about this? ZZ )
#include "Configuration.h"
#include "API.h"

#ifndef SIMULATOR_MODE
    #include "Motors.h"
    #include "Sensors.h"
#endif

void setup(){

}

void loop(){

}
