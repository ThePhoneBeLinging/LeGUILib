//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#include "LeGUILib/LeGUILib.h"

#include <memory>

#include "raylib.h"

LeGUILib::LeGUILib() : activeSlideIndex_(0)
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
    bool dragActive = false;
    std::pair<int,int> lastMousePos = std::pair(0, 0);
    int xOffset = 0;
    int yOffset = 0;
    while (!WindowShouldClose())
    {
        std::pair<int,int> mousePos = std::pair(GetMouseX(),GetMouseY());

        if (dragActive)
        {
            xOffset += mousePos.first - lastMousePos.first;
            //yOffset += mousePos.second - lastMousePos.second;
        }

        for (const auto& slide : slides_)
        {
            slide->updateDirtyElements();
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && not lmbPressed)
        {
            lookForClicks = true;
            lmbPressed = true;
        }
        else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            lmbPressed = false;
            dragActive = false;

            if (xOffset % screenWidth > screenWidth/2)
            {
                if (xOffset < 0)
                {
                    xOffset += screenWidth;
                }
            }
            else if (xOffset % screenWidth < (-1 * screenWidth/2))
            {
                if (xOffset > screenWidth * (slides_.size() - 1) * -1)
                {
                    xOffset -= screenWidth;
                }
            }
            xOffset -= xOffset % screenWidth;
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

void LeGUILib::addSlide(const std::shared_ptr<Slide>& slide)
{
    int screenWidth = 1280;
    slide->setOffset(screenWidth * slides_.size(),0);
    slides_.push_back(slide);
}

std::shared_ptr<Slide> LeGUILib::getSlide(int index)
{
    return slides_[index];
}
