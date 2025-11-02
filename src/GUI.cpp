#include "../include/GUI.h"

GUI::GUI()
{
    InitWindow(windowWidth, windowHeight, "Water Simulation");
    // camera = { 0 };
    // camera.zoom = 1.0f;

    // zoomMode = 0;   // 0-Mouse Wheel, 1-Mouse Move
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second

    std::vector<TextBox> inputBoxes = std::vector<TextBox>();
    inputBoxes.push_back(TextBox(50,  windowHeight - 150, 100, 30, 20, 10)); // pos x
    inputBoxes.push_back(TextBox(50, windowHeight - 120, 100, 30, 20, 10)); // pos y
    inputBoxes.push_back(TextBox(80, windowHeight - 90, 100, 30, 20, 10)); // width
    inputBoxes.push_back(TextBox(140, windowHeight - 60, 100, 30, 20, 10)); // max height
    inputBoxes.push_back(TextBox(240, windowHeight - 30, 100, 30, 20, 10)); // current water height

    this->inputBoxes = inputBoxes;
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
    // Update
    //----------------------------------------------------------------------------------

    // Create a new water container at mouse position
    if (IsKeyPressed(KEY_Q))
    {
        // check that there is no object with conflicting position?
        bool isConflict = false;
        Vector2 mouseWorldPos = GetMousePosition();
        for (size_t i = 0; i < this->bodies.size(); i++)
        {
            body_t body = this->bodies.at(i);

            isConflict |= ((mouseWorldPos.x >= body.pos_x &&
                           mouseWorldPos.x <= (body.pos_x + body.width) &&
                           mouseWorldPos.y >= body.pos_y &&
                           mouseWorldPos.y <= (body.pos_y + body.maxHeight)) || 
                          ((mouseWorldPos.x + 50) >= body.pos_x &&
                           (mouseWorldPos.x + 50) <= (body.pos_x + body.width) &&
                           mouseWorldPos.y >= body.pos_y &&
                           mouseWorldPos.y <= (body.pos_y + body.maxHeight )) ||
                          (mouseWorldPos.x >= body.pos_x &&
                           mouseWorldPos.x <= (body.pos_x + body.width) &&
                           (mouseWorldPos.y + 50) >= body.pos_y &&
                           (mouseWorldPos.y + 50) <= (body.pos_y + body.maxHeight)) ||
                          ((mouseWorldPos.x + 50) >= body.pos_x &&
                           (mouseWorldPos.x + 50) <= (body.pos_x + body.width) &&
                           (mouseWorldPos.y + 50) >= body.pos_y &&
                           (mouseWorldPos.y + 50) <= (body.pos_y + body.maxHeight)));
        }

        if (!isConflict)
        {
            body_t newBody;
            newBody.pos_x = (int)mouseWorldPos.x;
            newBody.pos_y = (int)mouseWorldPos.y;
            newBody.width = 50;
            newBody.maxHeight = 50;
            newBody.waterHeight = 0;
            this->bodies.push_back(newBody);
        }
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        // check that there is no object with conflicting position?
        Vector2 mouseWorldPos = GetMousePosition();
        bool foundSelectedCell = false;
        for (size_t i = 0; i < this->holes.size(); i++)
        {
            hole_t hole = this->holes.at(i);

            bool isSelectedHole;

            if(hole.direction == VERTICAL)
            {
                isSelectedHole = ((mouseWorldPos.x >= hole.pos_x - 5 &&
                           mouseWorldPos.x <= (hole.pos_x + 5) &&
                           mouseWorldPos.y >= hole.pos_y &&
                           mouseWorldPos.y <= (hole.pos_y + hole.width)));
            }
            else
            {
                isSelectedHole = ((mouseWorldPos.x >= hole.pos_x &&
                           mouseWorldPos.x <= (hole.pos_x + hole.width) &&
                           mouseWorldPos.y >= hole.pos_y-5 &&
                           mouseWorldPos.y <= (hole.pos_y + 5)));
            }

            if (isSelectedHole)
            {
                this->selectedHole = &this->holes.at(i);
                // Update input boxes with selected body properties
                this->inputBoxes.at(0).SetText(TextFormat("%.2f", this->selectedHole->pos_x));
                this->inputBoxes.at(1).SetText(TextFormat("%.2f", this->selectedHole->pos_y));
                this->inputBoxes.at(2).SetText(TextFormat("%.2f", this->selectedHole->width));
                foundSelectedCell = true;
            }

        }
        
        for (size_t i = 0; i < this->bodies.size(); i++)
        {
            body_t body = this->bodies.at(i);

            bool isSelectedBody = ((mouseWorldPos.x >= body.pos_x &&
                           mouseWorldPos.x <= (body.pos_x + body.width) &&
                           mouseWorldPos.y >= body.pos_y &&
                           mouseWorldPos.y <= (body.pos_y + body.maxHeight)));

            if (isSelectedBody)
            {
                this->selectedBody = &this->bodies.at(i);
                // Update input boxes with selected body properties
                this->inputBoxes.at(0).SetText(TextFormat("%.2f", this->selectedBody->pos_x));
                this->inputBoxes.at(1).SetText(TextFormat("%.2f", this->selectedBody->pos_y));
                this->inputBoxes.at(2).SetText(TextFormat("%.2f", this->selectedBody->width));
                this->inputBoxes.at(3).SetText(TextFormat("%.2f", this->selectedBody->maxHeight));
                this->inputBoxes.at(4).SetText(TextFormat("%.2f", this->selectedBody->waterHeight));
                foundSelectedCell = true;
            }
        }
        if(!foundSelectedCell && this->selectedBody != nullptr)
        {
            // Check if an input box is selected
            for (size_t i = 0; i < this->inputBoxes.size(); i++)
            {
                Rectangle inputBox = this->inputBoxes.at(i).GetBox();

                bool isSelectedBody = ((mouseWorldPos.x >= inputBox.x &&
                           mouseWorldPos.x <= (inputBox.x + inputBox.width) &&
                           mouseWorldPos.y >= inputBox.y &&
                           mouseWorldPos.y <= (inputBox.y + inputBox.height)));

                if (isSelectedBody){
                    foundSelectedCell = true;
                    if(this->selectedInputBox != nullptr)
                        this->selectedInputBox->SetActive(false);
                    this->selectedInputBox = &this->inputBoxes.at(i);
                    this->selectedInputBox->SetActive(true);
                    break;
                }
            }
            // check if save button is clicked
            if (CheckCollisionPointRec(mouseWorldPos, saveButton))
            {
                if(this->selectedBody != nullptr){
                    // Update selected body properties from input boxes
                    this->selectedBody->pos_x = atof(this->inputBoxes.at(0).GetText());
                    this->selectedBody->pos_y = atof(this->inputBoxes.at(1).GetText());
                    this->selectedBody->width = atof(this->inputBoxes.at(2).GetText());
                    this->selectedBody->maxHeight = atof(this->inputBoxes.at(3).GetText());
                    this->selectedBody->waterHeight = atof(this->inputBoxes.at(4).GetText());
                    foundSelectedCell = true;

                    // Deselect input box after saving
                    if(this->selectedInputBox != nullptr)
                        this->selectedInputBox->SetActive(false);
                    this->selectedInputBox = nullptr;
                    this->selectedBody = nullptr;
                }
                else if(this->selectedHole != nullptr){
                    // Update selected hole properties from input boxes
                    this->selectedHole->pos_x = atof(this->inputBoxes.at(0).GetText());
                    this->selectedHole->pos_y = atof(this->inputBoxes.at(1).GetText());
                    this->selectedHole->width = atof(this->inputBoxes.at(2).GetText());
                    foundSelectedCell = true;

                    // Deselect input box after saving
                    if(this->selectedInputBox != nullptr)
                        this->selectedInputBox->SetActive(false);
                    this->selectedInputBox = nullptr;
                    this->selectedHole = nullptr;
                }
            }

            // check if delete button is clicked
            if (CheckCollisionPointRec(mouseWorldPos, deleteButton))
            {
                if(this->selectedHole != nullptr)
                {
                    // Delete selected hole
                    for (size_t i = 0; i < this->holes.size(); i++)
                    {
                        if (&this->holes.at(i) == this->selectedHole)
                        {
                            this->holes.erase(this->holes.begin() + i);
                            break;
                        }
                    }
                    this->selectedHole = nullptr;
                    if(this->selectedInputBox != nullptr)
                        this->selectedInputBox->SetActive(false);
                    this->selectedInputBox = nullptr;
                    foundSelectedCell = true;
                }
                else if(this->selectedBody != nullptr)
                {
                // Delete selected body
                    for (size_t i = 0; i < this->bodies.size(); i++)
                    {
                        if (&this->bodies.at(i) == this->selectedBody)
                        {
                            this->bodies.erase(this->bodies.begin() + i);
                            break;
                        }
                    }
                    this->selectedBody = nullptr;
                    if(this->selectedInputBox != nullptr)
                        this->selectedInputBox->SetActive(false);
                    this->selectedInputBox = nullptr;
                    foundSelectedCell = true;
                }
            }

        }
        else if (!foundSelectedCell)
        {
            this->selectedBody = nullptr;
            if(this->selectedInputBox != nullptr)
                this->selectedInputBox->SetActive(false);
            this->selectedInputBox = nullptr;
        }
        
    }
    
    if (this->selectedInputBox != nullptr)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            this->selectedInputBox->Update((char)key);
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            this->selectedInputBox->Update('\b');
        }
    }
    
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        Vector2 mouseWorldPos = GetMousePosition();

        // check to see that we click on a body
        for (size_t i = 0; i < this->bodies.size(); i++)
        {
            body_t body = this->bodies.at(i);

            bool isOnBody = ((mouseWorldPos.x >= body.pos_x &&
                           mouseWorldPos.x <= (body.pos_x + body.width) &&
                           mouseWorldPos.y >= body.pos_y &&
                           mouseWorldPos.y <= (body.pos_y + body.maxHeight)));


            if (isOnBody){
                hole_t newHole = hole_t();
                if(mouseWorldPos.x - body.pos_x < body.width / 2)
                {
                    if(mouseWorldPos.y - body.pos_y < body.maxHeight/2)
                    {
                        if (mouseWorldPos.y - body.pos_y < mouseWorldPos.x - body.pos_x)
                        {
                            newHole.pos_x = mouseWorldPos.x;
                            newHole.pos_y = body.pos_y;
                            newHole.direction = HORIZONTAL; 
                            newHole.width = 20; 

                        }
                        else
                        {
                            newHole.pos_x = body.pos_x;
                            newHole.pos_y = mouseWorldPos.y;
                            newHole.direction = VERTICAL;
                            newHole.width = 20; 
                        }
                    }
                    else
                    {
                        if ((body.pos_y + body.maxHeight) - mouseWorldPos.y < mouseWorldPos.x - body.pos_x)
                        {
                            newHole.pos_x = body.pos_x;
                            newHole.pos_y = (int)mouseWorldPos.y;
                            newHole.direction = VERTICAL; 
                            newHole.width = 20; 
                        }
                        else
                        {
                            newHole.pos_x = (int)mouseWorldPos.x;
                            newHole.pos_y = body.pos_y + body.maxHeight - 0;
                            newHole.direction = HORIZONTAL;
                            newHole.width = 20; 
                        }
                    }                        
                }
                else 
                {
                    if(mouseWorldPos.y - body.pos_y < body.maxHeight/2)
                    {
                        if (mouseWorldPos.y - body.pos_y < (body.pos_x + body.width) - mouseWorldPos.x)
                        {
                            newHole.pos_x = (int)mouseWorldPos.x;
                            newHole.pos_y = body.pos_y;
                            newHole.direction = HORIZONTAL;
                            newHole.width = 20; 
                        }
                        else
                        {
                            newHole.pos_x = body.pos_x + body.width - 0;
                            newHole.pos_y = (int)mouseWorldPos.y;
                            newHole.direction = VERTICAL; 
                            newHole.width = 20; 
                        }
                    }
                    else
                    {
                        if ((body.pos_y + body.maxHeight) - mouseWorldPos.y < (body.pos_x + body.width) - mouseWorldPos.x)
                        {
                            newHole.pos_x = (int)mouseWorldPos.x;
                            newHole.pos_y = body.pos_y + body.maxHeight - 0;
                            newHole.direction = HORIZONTAL;
                            newHole.width = 20; 
                        }
                        else
                        {
                            newHole.pos_x = body.pos_x + body.width - 0;
                            newHole.pos_y = (int)mouseWorldPos.y;
                            newHole.direction = VERTICAL; 
                            newHole.width = 20; 
                        }
                    }  
                }

                this->selectedHole = &newHole;
                this->holes.push_back(newHole);
            }
        }
    }

    // Translate based on mouse right click
    // if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    // {
    //     Vector2 delta = GetMouseDelta();
    //     delta = Vector2Scale(delta, -1.0f/camera.zoom);
    //     camera.target = Vector2Add(camera.target, delta);
    // }

    // Zoom based on mouse wheel
    // float wheel = GetMouseWheelMove();
    // if (wheel != 0)
    // {
    //     // Get the world point that is under the mouse
    //     Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

    //     // Set the offset to where the mouse is
    //     camera.offset = GetMousePosition();

    //     // Set the target to match, so that the camera maps the world space point
    //     // under the cursor to the screen space point under the cursor at any zoom
    //     camera.target = mouseWorldPos;

    //     // Zoom increment
    //     // Uses log scaling to provide consistent zoom speed
    //     float scale = 0.2f*wheel;
    //     camera.zoom = Clamp(expf(logf(camera.zoom)+scale), 0.125f, 64.0f);
    // }
    //----------------------------------------------------------------------------------

    

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
        ClearBackground(RAYWHITE);

        // BeginMode2D(camera);

            // Draw the 3d grid, rotated 90 degrees and centered around 0,0
            // just so we have something in the XY plane
            rlPushMatrix();
                rlTranslatef(0, 25*50, 0);
                rlRotatef(90, 1, 0, 0);
                DrawGrid(50, 50);
            rlPopMatrix();

            // Rectangle shapes and lines
            for (size_t i = 0; i < this->bodies.size(); i++)
            {
                body_t body = this->bodies.at(i);

                // Draw the container rectangle
                DrawRectangleLines(body.pos_x, body.pos_y, body.width, body.maxHeight, BROWN);

                // Draw the water rectangle
                DrawRectangle(body.pos_x+1, body.pos_y+1 + (body.maxHeight - body.waterHeight-1), body.width-2, body.waterHeight-1, BLUE);
            }
            for (size_t i = 0; i < this->holes.size(); i++)
            {
                hole_t hole = this->holes.at(i);

                // Draw the hole
                if(hole.direction == VERTICAL)
                {
                    DrawRectangle(hole.pos_x, hole.pos_y-5, 10, hole.width, RED);
                }
                else
                {
                    DrawRectangle(hole.pos_x-5, hole.pos_y, hole.width, 10, RED);
                }
                /* code */
            }
            
        // EndMode2D();
        
        DrawTextEx(GetFontDefault(), TextFormat("[%i, %i]", GetMouseX(), GetMouseY()),
            Vector2Add(GetMousePosition(), (Vector2){ -44, -24 }), 20, 2, BLACK);

        DrawText("[q] Create A new water container at mouse", 20, 20, 20, DARKGRAY);
        DrawText("[right] Create A new hole container at mouse", 20, 40, 20, DARKGRAY);
        DrawText("[left] modify body or holes", 20, 60, 20, DARKGRAY);

        DrawText("Mouse right button drag to move, mouse wheel to zoom", 20, 80, 20, DARKGRAY);
        DrawRectangle(0, windowHeight-200, windowWidth, 200, GRAY);
        if(this->selectedBody != nullptr)
        {
            DrawText("Selected Body Properties:", 20, windowHeight-180, 20, BLACK);
            DrawText("X:                    ", 20, windowHeight-150, 20, BLACK);
            DrawText("Y:                    ", 20, windowHeight-120, 20, BLACK);
            DrawText("Width:                ", 20, windowHeight-90, 20, BLACK);
            DrawText("Max Height:           ", 20, windowHeight-60, 20, BLACK);
            DrawText("Current Water Height: ", 20, windowHeight-30, 20, BLACK);
            for (size_t i = 0; i < this->inputBoxes.size(); i++)
            {
                this->inputBoxes.at(i).Draw();
            }
            DrawRectangleRec(saveButton, GREEN);
            DrawText("Save", saveButton.x + 25, saveButton.y + 5, 20, BLACK);
            DrawRectangleRec(deleteButton, RED);
            DrawText("Delete", deleteButton.x + 15, deleteButton.y + 5, 20, BLACK);
        }
        else if(this->selectedHole != nullptr)
        {
            DrawText("Selected Hole Properties:", 20, windowHeight-180, 20, BLACK);
            DrawText("X:      ", 20, windowHeight-150, 20, BLACK);
            DrawText("Y:      ", 20, windowHeight-120, 20, BLACK);
            DrawText("Width:  ", 20, windowHeight-90, 20, BLACK);
            for (size_t i = 0; i < 3; i++)
            {
                this->inputBoxes.at(i).Draw();
            }
            DrawRectangleRec(saveButton, GREEN);
            DrawText("Save", saveButton.x + 25, saveButton.y + 5, 20, BLACK);
            DrawRectangleRec(deleteButton, RED);
            DrawText("Delete", deleteButton.x + 15, deleteButton.y + 5, 20, BLACK);
        }
        else
        {
            DrawText("No Body Selected. Left click on a body to select it.", 20, windowHeight-100, 20, DARKGRAY);
        }

    EndDrawing();
    
    
    }

void GUI::closeWindow()
{
    CloseWindow();
}