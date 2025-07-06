//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//
#include <TouchCore-CPP/EventListener.h>
#include "raylibIncludeFile.h"
#include "LeGUILib/LeGUILib.h"
#include <memory>



LeGUILib::LeGUILib() : keepRunning_(true)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "LeGUI");
    //ToggleFullscreen();
    //HideCursor();
    SetTargetFPS(10);
    //eventController_ = std::make_shared<EventController>();
    //eventListener_ = std::make_unique<EventListener>("/dev/input/by-path/platform-1f00080000.i2c-event",eventController_);
}

void LeGUILib::launchGUI()
{
    int screenWidth = 1280;

    bool lmbPressed = false;
    bool lookForClicks = false;
    std::pair<int,int> lastMousePos = std::pair(0, 0);
    int xOffset = 0;
    int yOffset = 0;
    while (!WindowShouldClose() && keepRunning_)
    {
        //auto activeFingers = eventController_->getFingerPositions();
        std::vector<std::pair<int,int>> activeFingers = {};

        if ((GetMouseX() != 0 || GetMouseY() != 0) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            activeFingers.emplace_back(GetMouseX(),GetMouseY());
        }

        slide_->updateDirtyElements();
        if (activeFingers.size() == 1 && not lmbPressed)
        {
            lmbPressed = true;
            slide_->handleClicks(activeFingers.front().first,activeFingers.front().second);
        }
        if (lmbPressed && activeFingers.empty())
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

void LeGUILib::closeGUI()
{
    keepRunning_ = false;
}
