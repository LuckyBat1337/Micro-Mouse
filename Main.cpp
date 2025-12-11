// Main.cpp
#include <iostream>
#include <string>
#include <vector>
#include "API.h"

// Enums for clarity and type safety
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

// Global State (mimicking embedded persistent state)
int x = 0;
int y = 0;
int dir = NORTH;

// Helper: Logging to stderr (Debug Console)
void log(const std::string& message) {
    std::cerr << " " << message << std::endl;
}

// Helper: Update coordinates based on move
void updateCoordinates() {
    if (dir == NORTH) y += 1;
    else if (dir == EAST) x += 1;
    else if (dir == SOUTH) y -= 1;
    else if (dir == WEST) x -= 1;
}

int main() {
    log("System Initialized...");
    
    // Visualization: Mark the start
    API::setText(0, 0, "START");
    API::setColor(0, 0, 'G'); // Green

    while (true) {
        // 1. SENSE
        bool left = API::wallLeft();
        bool front = API::wallFront();
        bool right = API::wallRight();

        // 2. THINK (Left Wall Follower Logic)
        // Rule: Follow left wall. 
        // Priority: Turn Left -> Go Straight -> Turn Right -> Turn Around
        
        if (!left) {
            // Path opens to the left
            log("Turning Left");
            API::turnLeft();
            dir = (dir + 3) % 4; // -1 mod 4 equivalent
            
            API::moveForward();
            updateCoordinates();
        } 
        else if (!front) {
            // Path open ahead
            log("Moving Forward");
            API::moveForward();
            updateCoordinates();
        } 
        else {
            // Blocked Left and Front -> Turn Right
            log("Turning Right");
            API::turnRight();
            dir = (dir + 1) % 4;
            // Note: We do not move immediately after turning right in this logic
            // The next loop iteration will check if 'front' is now open.
        }

        // 3. VISUALIZE
        // Color the current cell blue to show the path taken
        API::setColor(x, y, 'B');
        
        // Example of textual debugging on the map
        std::string debugCoord = std::to_string(x) + "," + std::to_string(y);
        API::setText(x, y, debugCoord);
    }
}
