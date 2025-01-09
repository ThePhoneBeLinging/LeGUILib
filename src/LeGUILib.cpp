//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#include "LeGUILib/LeGUILib.h"

#include "raylib.h"

LeGUILib::LeGUILib() : elementUpdater_(std::make_shared<ElementUpdaterController>())
{
    InitWindow(1280, 720, "LeGUI");
}

void LeGUILib::launchGUI()
{
    SetTargetFPS(60);
    bool lmbPressed = false;
    bool lookForClicks = false;
    while (!WindowShouldClose())
    {
        updateDirtyElements();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && not lmbPressed)
        {
            lookForClicks = true;
            lmbPressed = true;
        }
        else if (lmbPressed && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            lmbPressed = false;
        }

        for (const auto& element : elementsForDrawing_)
        {
            if (lookForClicks)
            {
                if (element->isPointInside(GetMouseX(),GetMouseY()))
                {
                    element->onClick();
                }
            }


            element->draw();
        }
        lookForClicks = false;
        EndDrawing();
    }
}

void LeGUILib::updateDirtyElements()
{
    std::lock_guard lock(weakElementsMutex_);
    for (const auto& elementIndices : elementUpdater_->getDirtyElements())
    {
        auto elementSharedPTR = weakElements_[elementIndices].lock();
        elementsForDrawing_[elementIndices] = elementSharedPTR->clone();
    }
}
