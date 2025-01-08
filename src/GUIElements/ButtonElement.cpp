//
// Created by eal on 07/01/25.
//

#include "ButtonElement.h"

#include <utility>

ButtonElement* ButtonElement::clone() const
{
    return new ButtonElement(*this);
}

void ButtonElement::draw()
{
    RectangleElement::draw();
}

void ButtonElement::onClick()
{
    onClickFunction_();
}

void ButtonElement::setOnClick(std::function<void()> onClickFunction)
{
    onClickFunction_ = std::move(onClickFunction);
}
