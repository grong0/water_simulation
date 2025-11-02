#ifndef GUI_H
#define GUI_H

#include "../lib/raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "TextBox.h"

#include "body.h"
#include "hole.h"
#include <vector>

class GUI {
private:
    const int windowWidth = 800;
    const int windowHeight = 600;

    std::vector<body_t> bodies;
    std::vector<hole_t> holes;
    
    // Camera2D camera;

    body_t* selectedBody = nullptr;
    TextBox* selectedInputBox = nullptr;
    hole_t* selectedHole = nullptr;

    Rectangle saveButton = { windowWidth - 120, windowHeight - 40, 100, 30 };
    Rectangle deleteButton = { windowWidth - 240, windowHeight - 40, 100, 30 };

    std::vector<TextBox> inputBoxes;

    // int zoomMode; // 0: wheel zoom, 1: mouse drag zoom

public:
    GUI();

    // returns true if the user has provided input to create new bodies
    bool GetUserInput();
    std::vector<body_t> getBodiesFromInput();
    void NextFrame();
    void closeWindow();
};


#endif