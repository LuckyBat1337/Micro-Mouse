#idndef MOVE_H
#define MOVE_H

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

extern int cur_x;
extern int cur_y;
extern int facing;

void initMove();
void moveForward();
void turnLeft();
void turnRight();
void turn180();

#endif
