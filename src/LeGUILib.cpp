//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#include "LeGUILib/LeGUILib.h"

#include <memory>

#include "raylib.h"

LeGUILib::LeGUILib()
{
    InitWindow(1280, 720, "LeGUI");
}

void LeGUILib::launchGUI()
{
    int screenWidth = 1280;
    SetTargetFPS(60);
    //ToggleFullscreen();
    bool lmbPressed = false;
    bool lookForClicks = false;
    std::pair<int,int> lastMousePos = std::pair(0, 0);
    int xOffset = 0;
    int yOffset = 0;
    while (!WindowShouldClose())
    {
        std::pair<int,int> mousePos = std::pair(GetMouseX(),GetMouseY());


        slide_->updateDirtyElements();

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && not lmbPressed)
        {
            lmbPressed = true;
        }
        if (lmbPressed && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            lmbPressed = false;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        slide_->draw();

        EndDrawing();
    }
}

void LeGUILib::addSlide(const std::shared_ptr<Slide>& slide)
{
    slide_ = slide;
}
