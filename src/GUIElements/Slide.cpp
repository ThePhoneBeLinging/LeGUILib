//
// Created by eal on 10/01/25.
//

#include "LeGUILib/GUIElements/Slide.h"

#include <iostream>
#include <memory>

#include "LeGUILib/GUIElements/GUIElement.h"

Slide::Slide() : elementUpdater_(std::make_shared<ElementUpdaterController>())
{
}

void Slide::updateDirtyElements()
{
    std::lock_guard lock(weakElementsMutex_);
    for (const auto& elementIndices : elementUpdater_->getDirtyElements())
    {
        auto elementSharedPTR = weakElements_[elementIndices].lock();
        if (elementSharedPTR)
        {
            elementsForDrawing_[elementIndices] = elementSharedPTR->clone();
        }
        else
        {
            elementsForDrawing_[elementIndices] = nullptr;
        }
    }
    auto sortingLambda = [](const std::shared_ptr<GUIElement>& a, const std::shared_ptr<GUIElement>& b)
    {
        return a->getZ() < b->getZ();
    };
    std::sort(elementsForDrawing_.begin(),elementsForDrawing_.end(), sortingLambda);

    for (int i = 0; i < elementsForDrawing_.size(); i++)
    {
        auto sharedPTR = weakElements_[elementsForDrawing_[i]->getID()].lock();
        if (sharedPTR)
        {
            sharedPTR->setID(i);
        }
        elementsForDrawing_[i]->setID(i);
    }
}

void Slide::draw()
{
    for (const auto& element : elementsForDrawing_)
    {
        if (element != nullptr)
        {
            element->draw();
        }
    }
}

void Slide::handleClicks(int x, int y) const
{
    for (const auto& element : elementsForDrawing_)
    {
        if (element->isPointInside(x,y))
        {
            element->onClick();
        }
    }
}
