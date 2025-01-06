//
// Created by eal on 1/6/25.
//

#include "GUIElement.h"

GUIElement::GUIElement() : id_(), elementUpdater_(nullptr)
{
}

void GUIElement::setID(int id)
{
    id_ = id;
}

int GUIElement::getID() const
{
    return id_;
}

void GUIElement::setElementUpdater(std::shared_ptr<ElementUpdaterController> elementUpdater)
{
    elementUpdater_ = elementUpdater;
}
