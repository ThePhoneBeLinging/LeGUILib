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
    bool dragActive = false;
    std::pair<int,int> lastMousePos = std::pair<int,int>(0, 0);
    int xOffset = 0;
    int yOffset = 0;
    while (!WindowShouldClose())
    {
        std::pair<int,int> mousePos = std::pair(GetMouseX(),GetMouseY());

        if (dragActive)
        {
            xOffset += mousePos.first - lastMousePos.first;
            yOffset += mousePos.second - lastMousePos.second;
        }

        getSlide()->updateDirtyElements();
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && not lmbPressed)
        {
            lookForClicks = true;
            lmbPressed = true;
        }
        else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            lmbPressed = false;
            dragActive = false;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (const auto& slide : slides_)
        {
            slide->draw(xOffset,yOffset);
        }

        EndDrawing();

        if (lookForClicks)
        {
            dragActive |= not slides_[0]->handleClicks(mousePos.first, mousePos.second);
        }

        lookForClicks = false;
        lastMousePos = mousePos;
    }
}

std::shared_ptr<Slide> LeGUILib::getSlide()
{
    return slides_[0];
}
