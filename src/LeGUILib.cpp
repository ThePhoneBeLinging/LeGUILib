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
        for (const auto& elementIndices : elementUpdater_->getDirtyElements())
        {
            elementsForDrawing_[elementIndices] = weakElements_[elementIndices].lock()->clone();
        }

        lock.unlock();
    }
}

void LeGUILib::updateDirtyElements()
{

}

/*
template <typename T>
std::shared_ptr<T> LeGUILib::createElement()
{
    auto element = std::make_shared<T>();
    static_cast<GUIElement>(element).setElementUpdater(elementUpdater_);
    static_cast<GUIElement>(element).setID(static_cast<int>(weakElements_.size()));
    weakElements_.emplace_back(element);

    return element;
}

*/
