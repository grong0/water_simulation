#ifndef GUI_H
#define GUI_H

#include "../lib/raylib.h"
#include "body.h"
#include <vector>

class GUI {
private:
    const int windowWidth = 800;
    const int windowHeight = 600;

    std::vector<body_t> bodies;
    Camera2D camera;

public:
    GUI();

    // returns true if the user has provided input to create new bodies
    bool GetUserInput();
    std::vector<body_t> getBodiesFromInput();
    void NextFrame();
    bool WindowShouldClose();
};


#endif