//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#include "LeGUILib/GUIElements/Text.h"

#include <string>

void Text::draw()
{
    // TODO
}

void Text::setText(const std::string& text)
{
    text_ = text;
}

const std::string& Text::getText()
{
    return text_;
}

void Text::setFontSize(int fontSize)
{
    fontSize_ = fontSize;
}

int Text::getFontSize()
{
    return fontSize_;
}
