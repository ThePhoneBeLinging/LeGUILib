//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#include "LeGUILib/GUIElements/Text.h"

#include <string>

#include "raylib.h"

Text* Text::clone() const
{
    std::lock_guard lockGuard(*mutex_);
    return new Text(*this);
}

void Text::draw(int offsetX, int offsetY)
{
    std::lock_guard lockGuard(*mutex_);
    if (color_ != nullptr)
    {
        DrawText(text_.c_str(),x_,y_,fontSize_,*color_);
    }
}

void Text::setText(const std::string& text)
{
    std::lock_guard lockGuard(*mutex_);
    text_ = text;
    elementUpdater_->markElementAsDirty(id_);
}

const std::string& Text::getText()
{
    std::lock_guard lockGuard(*mutex_);
    return text_;
}

void Text::setFontSize(int fontSize)
{
    std::lock_guard lockGuard(*mutex_);
    fontSize_ = fontSize;
    elementUpdater_->markElementAsDirty(id_);
}

int Text::getFontSize()
{
    std::lock_guard lockGuard(*mutex_);
    return fontSize_;
}
