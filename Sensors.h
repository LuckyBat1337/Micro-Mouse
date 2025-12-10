/*dont know what needs to be added in this document, someone else can take a look ZZ
  right now its a very simple code that needs to be expanded upon, will be done later. 
*/

#ifndef SENSORS_H
#define SENSORS_H
#include <Arduino.h>
#include "Configuration.h"

class Sensors {
public:
    static void init();
    static float readFrontDistanceMM();
    static float readLeftDistanceMM();
    static float readRightDistanceMM();
};

#endif
