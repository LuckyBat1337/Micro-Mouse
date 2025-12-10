/*
 API.h is strict the interface contract required by the Micromouse Simulator.
 This file declares the methods available to the maze-solving algorithm.
 */

#ifndef API_H
#define API_H

#include <Arduino.h> // used for string and bool (ZZ)
#include "Configuration.h"

class API {
public:
    // Navigation commands

    // Returns true if wall exists, false otherwise
    static bool wallFront();
    static bool wallRight();
    static bool wallLeft();
    
    // Movement commands
    static void moveForward(int distance = 1);
    static void moveForwardHalf(int distance = 1);
    
    // In-place turns
    static void turnRight();
    static void turnLeft();

    // Maze state information 
    static int mazeWidth();
    static int mazeHeight();

    // Visualization (simulator only) 
    static void setWall(int x, int y, char direction);
    static void clearWall(int x, int y, char direction);
    
    static void setColor(int x, int y, char color);
    static void clearColor(int x, int y);
    static void clearAllColor();

    static void setText(int x, int y, String text);
    static void clearText(int x, int y);
    static void clearAllText();

    // System control 
    static bool wasReset();
    static void ackReset();
};

#endif 
