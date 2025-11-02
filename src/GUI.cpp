#include "../include/GUI.h"

GUI::GUI()
{
    InitWindow(windowWidth, windowHeight, "Water Simulation");
    camera.zoom = 1.0f;

    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
}

// returns true if the user has provided input to create new bodies
bool GUI::GetUserInput()
{
    return false;
}
std::vector<body_t> GUI::getBodiesFromInput()
{
    return this->bodies;
}

void GUI::NextFrame()
{

}

bool GUI::WindowShouldClose()
{
    return false;   
}