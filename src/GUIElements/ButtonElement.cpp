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