#ifndef CONNECTEDDIFFTEST_H
#define CONNECTEDDIFFTEST_H

#include "../include/body.h"

#define TEST_BODY_COUNT 3

void createTestBodies(Body* bodies){
// Create test bodies      isCapped, maxHeight, waterHeight, width, pos_x, pos_y
    bodies[0] = Body{false   , 8.0f     , 3.0f       , 1.0f , 0.0f , 0.0f}; // Body 1
    bodies[1] = Body{true    , 1.0f     , 1.0f       , 1.0f , 1.0f , 2.0f}; // Body 2
    bodies[2] = Body{false   , 3.0f     , 2.5f       , 1.0f , 2.0f , 1.0f}; // Body 3
}



#endif