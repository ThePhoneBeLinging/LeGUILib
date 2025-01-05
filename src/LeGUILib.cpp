//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#include "LeGUILib.h"

template <typename T>
std::shared_ptr<T> LeGUILib::createElement()
{
    auto element = std::make_shared<T>();
    static_cast<GUIElement>(element).setElementUpdater(elementUpdater_);
    static_cast<GUIElement>(element).setID(static_cast<int>(weakElements_.size()));
    weakElements_.emplace_back(element);

    return element;
}
