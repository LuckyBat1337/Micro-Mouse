#include <iostream>
#include <string>
#include "API.h"

void log(const std::string& text){
    std::cerr << text << std::endl;
}

int main(int argc, char* argv){
    log("Simulation starting");

    ackReset();

    API::setText(0,0, "start");
    API::setColor(0,0, 'G'); //green cell is start cell

     while (true) {
        // simple wall follower changed from arduino code to c++
        // if no wall on left, turn left and move forward.
        // else if no wall in front, move forward.
        // else (wall left and wall front), turn right.
        
        if (!API::wallLeft()) {
            log("left is open, turning left...");
            API::turnLeft();
            API::moveForward();
        }
        else if (!API::wallFront()) {
             log("front is open, moving forward...");
            API::moveForward();
        }
        else {
             log("blocked! turning right...");
            API::turnRight();
            // not true wall follower since i added this
            // The next iteration of the loop will decide if we can move.
        }
    }
    
    return 0; // Should never be reached in infinite loop
}
}


