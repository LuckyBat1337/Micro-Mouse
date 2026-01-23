#include <stdio.h>
#include <string>
#include "solver.h"
#include "API.h"


// You do not need to edit this file.
// This program just runs your solver and passes the choices
// to the simulator.
int main(int argc, char* argv[]) {
    char log[] = "Running...";
    debug_log(log);
    while (1) {
        Action nextMove = solver();
        switch (nextMove) {
        case FORWARD:
            API_moveForward();
            break;
        case LEFT:
            API_turnLeft();
            break;
        case RIGHT:
            API_turnRight();
            break;
        case IDLE:
            break;
        }
    }
}