//
// Created by eal on 1/6/25.
//

#include "GUIElement.h"

#include <utility>

GUIElement::GUIElement() : id_(),x_(0),y_(0),z_(0), elementUpdater_(nullptr)
{
}

GUIElement::GUIElement(GUIElement* guiElement)
{
    id_ = guiElement->getID();
    x_ = guiElement->getX();
    y_ = guiElement->getY();
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
    elementUpdater_->markElementAsDirty(id_);
}

int GUIElement::getX() const
{
    return x_;
}

void GUIElement::setY(int y)
{
    y_ = y;
    elementUpdater_->markElementAsDirty(id_);
}

int GUIElement::getY() const
{
    return y_;
}

void GUIElement::setZ(int z)
{
    z_ = z;
}

int GUIElement::getZ() const
{
    return z_;
}

bool GUIElement::isPointInside(int x, int y) const
{
    return false;
}

void GUIElement::onClick() const
{
    onClick_();
}

void GUIElement::setOnClick(std::function<void()> onClick)
{
    onClick_ = onClick;
}

void GUIElement::setOnClick(std::function<void()> onClick)
{
    onClick_ = std::move(onClick);
}

void GUIElement::setElementUpdater(std::shared_ptr<ElementUpdaterController> elementUpdater)
{
    elementUpdater_ = elementUpdater;
    elementUpdater_->markElementAsDirty(id_);
}

void GUIElement::setColor(int red, int green, int blue)
{
    color_ = std::make_shared<Color>(red, green, blue,255);
    elementUpdater_->markElementAsDirty(id_);
}

void GUIElement::setColor(int red, int green, int blue, int alpha)
{
    color_ = std::make_shared<Color>(red, green, blue, alpha);
    elementUpdater_->markElementAsDirty(id_);
}
