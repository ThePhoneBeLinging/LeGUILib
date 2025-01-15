//
// Created by eal on 1/6/25.
//

#include "LeGUILib/GUIElements/GUIElement.h"

#include <utility>

GUIElement::GUIElement() : id_(), x_(0), y_(0), z_(0), elementUpdater_(nullptr), mutex_(new std::mutex())
{
}

GUIElement::~GUIElement()
{
    delete mutex_;
}

void GUIElement::setID(int id)
{
    std::lock_guard lockGuard(*mutex_);
    id_ = id;
}

int GUIElement::getID() const
{
    std::lock_guard lockGuard(*mutex_);
    return id_;
}

void GUIElement::setX(int x)
{
    std::lock_guard lockGuard(*mutex_);
    x_ = x;
    elementUpdater_->markElementAsDirty(id_);
}

int GUIElement::getX() const
{
    std::lock_guard lockGuard(*mutex_);
    return x_;
}

void GUIElement::setY(int y)
{
    std::lock_guard lockGuard(*mutex_);
    y_ = y;
    elementUpdater_->markElementAsDirty(id_);
}

int GUIElement::getY() const
{
    std::lock_guard lockGuard(*mutex_);
    return y_;
}

void GUIElement::setZ(int z)
{
    std::lock_guard lockGuard(*mutex_);
    z_ = z;
}

int GUIElement::getZ() const
{
    std::lock_guard lockGuard(*mutex_);
    return z_;
}

bool GUIElement::isPointInside(int x, int y) const
{
    std::lock_guard lockGuard(*mutex_);
    return false;
}

void GUIElement::onClick() const
{
    std::lock_guard lockGuard(*mutex_);
    if (onClick_ != nullptr)
    {
        onClick_();
    }
}

void GUIElement::setOnClick(std::function<void()> onClick)
{
    std::lock_guard lockGuard(*mutex_);
    onClick_ = std::move(onClick);
}

void GUIElement::setElementUpdater(std::shared_ptr<ElementUpdaterController> elementUpdater)
{
    std::lock_guard lockGuard(*mutex_);
    elementUpdater_ = elementUpdater;
    elementUpdater_->markElementAsDirty(id_);
}

void GUIElement::setColor(int red, int green, int blue)
{
    std::lock_guard lockGuard(*mutex_);
    color_ = std::make_shared<Color>(red, green, blue,255);
    elementUpdater_->markElementAsDirty(id_);
}

void GUIElement::setColor(int red, int green, int blue, int alpha)
{
    std::lock_guard lockGuard(*mutex_);
    color_ = std::make_shared<Color>(red, green, blue, alpha);
    elementUpdater_->markElementAsDirty(id_);
}
