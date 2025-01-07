//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#include "LeGUILib/GUIElements/Text.h"

#include <string>

#include "raylib.h"

Text* Text::clone() const
{
    return new Text(*this);
}

void Text::draw()
{
    if (color_ != nullptr)
    {
        DrawText(text_.c_str(),x_,y_,fontSize_,*color_);
    }
}

void Text::setText(const std::string& text)
{
    text_ = text;
    elementUpdater_->markElementAsDirty(id_);
}

const std::string& Text::getText()
{
    return text_;
}

void Text::setFontSize(int fontSize)
{
    fontSize_ = fontSize;
    elementUpdater_->markElementAsDirty(id_);
}

int Text::getFontSize()
{
    return fontSize_;
}
