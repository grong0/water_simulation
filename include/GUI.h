#ifndef GUI_H
#define GUI_H

#include "../lib/raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "TextBox.h"

#include "body.h"
#include <vector>

class GUI {
private:
    const int windowWidth = 800;
    const int windowHeight = 600;

    bool isUserInput = false;

    // Camera2D camera;

    Body* selectedBody = nullptr;
    TextBox* selectedInputBox = nullptr;
    Hole* selectedHole = nullptr;

    Rectangle saveButton = { windowWidth - 120, windowHeight - 40, 100, 30 };
    Rectangle deleteButton = { windowWidth - 240, windowHeight - 40, 100, 30 };

    std::vector<TextBox> inputBoxes;

    Rectangle playButton = { 650,  50, 50, 50 };

    // int zoomMode; // 0: wheel zoom, 1: mouse drag zoom

public:
    GUI();

    std::vector<Body> *bodies;
    std::vector<Hole> *holes;

    // returns true if the user has provided input to create new bodies
    bool GetUserInput();
    std::vector<Body> getBodiesFromInput();
    void NextFrame();
    void closeWindow();
};


#endif