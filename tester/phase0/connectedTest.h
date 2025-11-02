#ifndef CONNECTEDTEST_H
#define CONNECTEDTEST_H

#include "../include/body.h"

#define TEST_BODY_COUNT 3

void createTestBodies(body_t* bodies){
// Create test bodies      isCapped, maxHeight, waterHeight, width, pos_x, pos_y
    bodies[0] = body_t{false   , 3.0f     , 3.0f       , 1.0f , 0.0f , 0.0f}; // Body 1
    bodies[1] = body_t{true    , 1.0f     , 1.0f       , 1.0f , 1.0f , 1.0f}; // Body 2
    bodies[2] = body_t{false   , 3.0f     , 2.0f       , 1.0f , 2.0f , 1.0f}; // Body 3
}



#endif