//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#include "LeGUILib/LeGUILib.h"

#include <memory>

#include "raylib.h"

LeGUILib::LeGUILib()
{
    InitWindow(1280, 720, "LeGUI");
    slides_.emplace_back(std::make_shared<Slide>());
}

void LeGUILib::launchGUI()
{
    SetTargetFPS(60);
    bool lmbPressed = false;
    bool lookForClicks = false;
    while (!WindowShouldClose())
    {
        getSlide()->updateDirtyElements();
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && not lmbPressed)
        {
            lookForClicks = true;
            lmbPressed = true;
        }
        else if (lmbPressed && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            lmbPressed = false;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (const auto& slide : slides_)
        {
            slide->draw(0,0);
        }

        EndDrawing();

        if (lookForClicks)
        {
            slides_[0]->handleClicks(GetMouseX(), GetMouseY());
        }

        lookForClicks = false;
    }
}

std::shared_ptr<Slide> LeGUILib::getSlide()
{
    return slides_[0];
}
