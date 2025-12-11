/*
  API.cpp is where we should have a implementation of the API interface. (maybe? ZZ)
  
  IMPORTANT NOTE!!!!!!!! OBS!!!!!
  This file contains two completely separate implementations.
  The preprocessor directives (#ifdef SIMULATOR_MODE, row 14 right now dont forget to change what row im refering to end of project ZZ ) 
  determine which block of code is compiled. This allows the same source files to run on the desktop simulator and the physical ESP32.
 */
// API.cpp
#include "API.h"
#include <iostream>
#include <string>
#include <cstdlib> // for exit()

// Helper to handle the request-response cycle
// Blocks until simulator responds.
// Uses std::cin >> response which skips whitespace automatically.

int API::mazeWidth() {
    std::cout << "mazeWidth" << std::endl;
    std::string response;
    std::cin >> response;
    return std::stoi(response);
}

int API::mazeHeight() {
    std::cout << "mazeHeight" << std::endl;
    std::string response;
    std::cin >> response;
    return std::stoi(response);
}

bool API::wallFront() {
    std::cout << "wallFront" << std::endl;
    std::string response;
    std::cin >> response;
    return (response == "true");
}

bool API::wallRight() {
    std::cout << "wallRight" << std::endl;
    std::string response;
    std::cin >> response;
    return (response == "true");
}

bool API::wallLeft() {
    std::cout << "wallLeft" << std::endl;
    std::string response;
    std::cin >> response;
    return (response == "true");
}

void API::moveForward(int distance) {
    std::cout << "moveForward " << distance << std::endl;
    std::string response;
    std::cin >> response;
    if (response == "crash") {
        std::cerr << "CRITICAL: mouse crashed!!!!!!" << std::endl;
        // logic to handle reset or stop?
    }
}

void API::turnRight() {
    std::cout << "turnRight" << std::endl;
    std::string response;
    std::cin >> response;
}

void API::turnLeft() {
    std::cout << "turnLeft" << std::endl;
    std::string response;
    std::cin >> response;
}

void API::setWall(int x, int y, char direction) {
    std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
}

void API::clearWall(int x, int y, char direction) {
    std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
}

void API::setColor(int x, int y, char color) {
    std::cout << "setColor " << x << " " << y << " " << color << std::endl;
}

void API::clearColor(int x, int y) {
    std::cout << "clearColor " << x << " " << y << std::endl;
}

void API::setText(int x, int y, const std::string& text) {
    std::cout << "setText " << x << " " << y << " " << text << std::endl;
}

void API::clearText(int x, int y) {
    std::cout << "clearText " << x << " " << y << std::endl;
}

bool API::wasReset() {
    std::cout << "wasReset" << std::endl;
    std::string response;
    std::cin >> response;
    return (response == "true");
}

void API::ackReset() {
    std::cout << "ackReset" << std::endl;
    std::string response;
    std::cin >> response;
}
