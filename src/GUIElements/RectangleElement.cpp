//
// Created by eal on 7/1/25.
//

#include "LeGUILib/GUIElements/RectangleElement.h"

RectangleElement::RectangleElement() : width_(0), height_(0), roundness_(0)
{

}

RectangleElement* RectangleElement::clone() const
{
    std::lock_guard lockGuard(*mutex_);
    return new RectangleElement(*this);
}

void RectangleElement::draw(int offsetX, int offsetY)
{
    std::lock_guard lockGuard(*mutex_);
    if (color_ != nullptr)
    {
        auto rect = Rectangle(x_,y_,width_,height_);
        DrawRectangleRounded(rect,roundness_,4,*color_);
    }
}

void RectangleElement::setWidth(const int width)
{
    std::lock_guard lockGuard(*mutex_);
    width_ = width;
}

int RectangleElement::getWidth() const
{
    std::lock_guard lockGuard(*mutex_);
    return width_;
}

void RectangleElement::setHeight(const int height)
{
    std::lock_guard lockGuard(*mutex_);
    height_ = height;
}

int RectangleElement::getHeight() const
{
    std::lock_guard lockGuard(*mutex_);
    return height_;
}

void RectangleElement::setRoundedEdge(const double roundedEdge)
{
    std::lock_guard lockGuard(*mutex_);
    roundness_ = roundedEdge;
}

double RectangleElement::getRoundedEdge() const
{
    std::lock_guard lockGuard(*mutex_);
    return roundness_;
}

bool RectangleElement::isPointInside(int x, int y) const
{
    std::lock_guard lockGuard(*mutex_);
    if (x < x_ || y < y_)
    {
        return false;
    }
    if (x_ + width_ < x || y_ + height_ < y)
    {
        return false;
    }
    return true;
}
