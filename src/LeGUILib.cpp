//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#include "LeGUILib/LeGUILib.h"

#include "raylib.h"

LeGUILib::LeGUILib() : elementUpdater_(std::make_shared<ElementUpdaterController>())
{
}

void LeGUILib::launchGUI()
{
    InitWindow(1280, 720, "LeGUI");
    SetTargetFPS(60);
    std::unique_lock lock(weakElementsMutex_);
    lock.unlock();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (const auto& element : elementsForDrawing_)
        {
            element->draw();
        }
        EndDrawing();

        lock.lock();
        updateDirtyElements();
        lock.unlock();
    }
}

void LeGUILib::updateDirtyElements()
{
    for (const auto& elementIndices : elementUpdater_->getDirtyElements())
    {
        elementsForDrawing_[elementIndices] = weakElements_[elementIndices].lock()->clone();
    }
}
