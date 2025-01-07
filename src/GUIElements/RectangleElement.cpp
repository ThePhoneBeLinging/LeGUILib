//
// Created by eal on 7/1/25.
//

#include "LeGUILib/GUIElements/RectangleElement.h"

RectangleElement::RectangleElement() : width_(0), height_(0), roundness_(0)
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
        auto rect = Rectangle(x_,y_,width_,height_);
        DrawRectangleRounded(rect,roundness_,4,*color_);
    }
}

void RectangleElement::setWidth(const int width)
{
    width_ = width;
}

int RectangleElement::getWidth() const
{
    return width_;
}

void RectangleElement::setHeight(const int height)
{
    height_ = height;
}

int RectangleElement::getHeight() const
{
    return height_;
}

void RectangleElement::setRoundedEdge(const double roundedEdge)
{
    roundness_ = roundedEdge;
}

double RectangleElement::getRoundedEdge() const
{
    return roundness_;
}
