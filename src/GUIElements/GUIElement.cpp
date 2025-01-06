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

void GUIElement::setColor(int red, int green, int blue)
{
    color_ = std::make_shared<Color>(red, green, blue,255);
}

void GUIElement::setColor(int red, int green, int blue, int alpha)
{
    color_ = std::make_shared<Color>(red, green, blue, alpha);
}
