//
// Created by eal on 10/01/25.
//

#include "LeGUILib/GUIElements/Slide.h"

#include <iostream>
#include <memory>
#include "LeGUILib/GUIElements/GUIElement.h"

Slide::Slide() : elementUpdater_(std::make_shared<ElementUpdaterController>()), offsetXOfSlide_(0), offsetYOfSlide_(0)
{
}

void Slide::updateDirtyElements()
{
    std::lock_guard lock(weakElementsMutex_);
    for (const auto& elementIndices : elementUpdater_->getDirtyElements())
    {
        auto elementSharedPTR = weakElements_[elementIndices].lock();
        elementsForDrawing_[elementIndices] = elementSharedPTR->clone();
    }
    auto sortingLambda = [](const GUIElement* a, const GUIElement* b)
    {
        return a->getZ() < b->getZ();
    };
    std::ranges::sort(elementsForDrawing_, sortingLambda);

    for (int i = 0; i < elementsForDrawing_.size(); i++)
    {
        auto element = weakElements_[elementsForDrawing_[i]->getID()].lock();
        element->setID(i);
        elementsForDrawing_[i]->setID(i);
    }
}

void Slide::draw(int offsetX, int offsetY)
{
    offsetX += offsetXOfSlide_;
    offsetY += offsetYOfSlide_;
    for (const auto& element : elementsForDrawing_)
    {
        element->draw(offsetX, offsetY);
    }
}

bool Slide::handleClicks(int x, int y)
{
    x += offsetXOfSlide_;
    y += offsetYOfSlide_;
    for (const auto& element : elementsForDrawing_)
    {
        if (element->isPointInside(x,y))
        {
            element->onClick();
            return true;
        }
    }
    return false;
}

void Slide::setOffset(int offsetX, int offsetY)
{
    offsetXOfSlide_ = offsetX;
    offsetYOfSlide_ = offsetY;
}
