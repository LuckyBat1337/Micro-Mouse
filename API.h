// API.h
#pragma once
#include <string>

class API {
public:
    // Sensing Methods
    static int mazeWidth();
    static int mazeHeight();
    static bool wallFront();
    static bool wallRight();
    static bool wallLeft();
    
    // Movement Methods
    static void moveForward(int distance = 1);
    static void turnRight();
    static void turnLeft();
    
    // Visualization/Debug Methods
    static void setWall(int x, int y, char direction);
    static void clearWall(int x, int y, char direction);
    static void setColor(int x, int y, char color);
    static void clearColor(int x, int y);
    static void setText(int x, int y, const std::string& text);
    static void clearText(int x, int y);
    
    // State Management
    static bool wasReset();
    static void ackReset();
};
