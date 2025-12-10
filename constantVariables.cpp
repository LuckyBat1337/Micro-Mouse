#include <iostream>
#include <string>

const int PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
// 100 digits of Pi used as an approximation. Used for calculation of millimeters per tick (row 13 of current file).
const int WHEEL_DIAMATER = ZZ; // Diameter of the wheel
const int WHEEL_RADIUS = ZZ; // Radius of the wheel
const int GEAR_RATIO = ZZ; // Gear ratio, example 10:1, used for encoder resolution
const int ENCODER_CPR = ZZ; // Stands for Encoder Counts Per Revolution
const int TRACK_WIDTH = ZZ; // Likely 16cm width because of 18cm max possible size - (1 * 2)cm for walls
const int MAZE_SIZE = 288; // Maze size in centimeters
const int TOTAL_CELLS = 256; // Total amount of cells in the cell labyrint (16x16)
const int MM_PER_TICK = (PI * WHEEL_DIAMETER)/(ENCODER_CPR * GEAR_RATIO); /* This conversion factor allows
the high-level code to request movement in metric units, (e.g. "move 180mm"). */
