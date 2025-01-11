//
// Created by eal on 7/1/25.
//

#include <string>
#include <LeGUILib/GUIElements/ImageElement.h>

#include "raylib.h"

ImageElement::ImageElement() : width_(0), height_(0), texture_(LoadTexture(""))
{
}

ImageElement* ImageElement::clone() const
{
    std::lock_guard lockGuard(*mutex_);
    return new ImageElement(*this);
}

void ImageElement::draw(int offsetX, int offsetY)
{
    std::lock_guard lockGuard(*mutex_);
    DrawTexture(texture_,x_ + offsetX,y_ + offsetY,WHITE);
}

void ImageElement::loadImage(const std::string& imagePath)
{
    std::lock_guard lockGuard(*mutex_);
    texture_ = LoadTexture(imagePath.c_str());
    texture_.height = height_;
    texture_.width = width_;
    elementUpdater_->markElementAsDirty(id_);
}

void ImageElement::setWidth(const int width)
{
    std::lock_guard lockGuard(*mutex_);
    width_ = width;
    texture_.width = width;
    elementUpdater_->markElementAsDirty(id_);
}

int ImageElement::getWidth() const
{
    std::lock_guard lockGuard(*mutex_);
    return width_;
}

void ImageElement::setHeight(const int height)
{
    std::lock_guard lockGuard(*mutex_);
    height_ = height;
    texture_.height = height;
    elementUpdater_->markElementAsDirty(id_);
}

int ImageElement::getHeight() const
{
    std::lock_guard lockGuard(*mutex_);
    return height_;
}
