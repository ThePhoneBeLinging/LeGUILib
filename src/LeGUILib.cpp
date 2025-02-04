//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//
#include <TouchCore-CPP/EventListener.h>
#include "raylibIncludeFile.h"
#include "LeGUILib/LeGUILib.h"
#include <memory>



LeGUILib::LeGUILib()
{
    InitWindow(1280, 720, "LeGUI");
    eventController_ = std::make_shared<EventController>();
    eventListener_ = std::make_unique<EventListener>("/dev/input/by-path/platform-1f00080000.i2c-event",eventController_);
}

void LeGUILib::launchGUI()
{
    int screenWidth = 1280;
    SetTargetFPS(10);
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
            slide_->handleClicks(mousePos.first,mousePos.second);
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

void LeGUILib::navigateTo(const std::shared_ptr<Slide>& slide)
{
    slide_ = slide;
}
