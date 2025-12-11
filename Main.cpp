#include <iostream>
#include <string>
#include "API.h"

// alg logic

// Global variables (simulating arduino globals)
int x = 0;
int y = 0;
int facing = 0; // 0=North, 1=East, 2=South, 3=West

void log(const std::string& text) {
    std::cerr << text << std::endl; // use cerr for logging, cout is for commands!
}

void setup() {
    log("Running...");
    API::setText(0, 0, "abc");
    API::setColor(0, 0, 'G');
}

void loop() {
    // left-wall-followerlLogic
    if (!API::wallLeft()) {
        API::turnLeft();
    }
    
    while (API::wallFront()) {
        API::turnRight();
    }
    
    API::moveForward();
    
    // check for reset (simulator specific)
    if (API::wasReset()) {
        API::ackReset();
        setup(); // re-run setup on reset
    }
}

// algo logic end above

// standard c++ entry point
int main(int argc, char* argv) {
    setup();
    while (true) {
        loop();
    }
    return 0;
}
