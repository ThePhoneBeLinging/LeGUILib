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

void Text::draw()
{
    std::lock_guard lockGuard(*mutex_);
    int offsetX = 0;
    int offsetY = 0;
    // Handle middle alignment
    if (alignment_ == 1)
    {
        int widthOfText = MeasureText(text_.c_str(),fontSize_);
        offsetX += width_ / 2 - widthOfText / 2;
    }
    if (alignment_ == 2)
    {
        int widthOfText = MeasureText(text_.c_str(),fontSize_);
        offsetX += width_ - widthOfText;
    }

    if (color_ != nullptr)
    {
        DrawText(text_.c_str(),x_ + offsetX,y_ + offsetY,fontSize_,*color_);
    }
}

void Text::setText(const std::string& text)
{
    std::lock_guard lockGuard(*mutex_);
    if (text_ != text)
    {
        text_ = text;
        elementUpdater_->markElementAsDirty(id_);
    }
}

void Text::setText(int text)
{
    auto stringText = std::to_string(text);
    setText(stringText);
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

void Text::setAlignment(const int alignemnt)
{
    alignment_ = alignemnt;
}

void Text::setWidth(int width)
{
    width_ = width;
}
