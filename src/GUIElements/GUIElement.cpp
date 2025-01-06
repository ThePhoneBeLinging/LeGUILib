//
// Created by eal on 1/6/25.
//

#include "GUIElement.h"

GUIElement::GUIElement() : id_(),x_(0),y_(0),z_(0), elementUpdater_(nullptr)
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

void GUIElement::setX(int x)
{
    x_ = x;
}

int GUIElement::getX() const
{
    return x_;
}

void GUIElement::setY(int y)
{
    y_ = y;
}

int GUIElement::getY() const
{
    return y_;
}

void GUIElement::setElementUpdater(std::shared_ptr<ElementUpdaterController> elementUpdater)
{
    elementUpdater_ = elementUpdater;
}
