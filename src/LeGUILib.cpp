//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#include "LeGUILib.h"

void LeGUILib::registerElement(const std::shared_ptr<GUIElement>& element)
{
    weakElements_.emplace_back(element);
}

void LeGUILib::registerUpdate(int id)
{

}

void LeGUILib::launchGUI()
{

}
