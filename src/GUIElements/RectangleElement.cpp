//
// Created by eal on 1/7/25.
//

#include "LeGUILib/GUIElements/RectangleElement.h"

RectangleElement::RectangleElement() : width_(0), height_(0)
{

}

RectangleElement* RectangleElement::clone() const
{
    return new RectangleElement(*this);
}

void RectangleElement::draw()
{
    if (color_ != nullptr)
    {
        DrawRectangle(x_,y_,width_,height_,*color_);
    }
}

void RectangleElement::setWidth(int width)
{
    width_ = width;
}

int RectangleElement::getWidth() const
{
    return width_;
}

void RectangleElement::setHeight(int height)
{
    height_ = height;
}

int RectangleElement::getHeight() const
{
    return height_;
}
