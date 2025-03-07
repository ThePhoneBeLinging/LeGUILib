//
// Created by eal on 7/1/25.
//

#include <string>
#include <LeGUILib/GUIElements/ImageElement.h>

#include "raylib.h"

ImageElement::ImageElement() : width_(0), height_(0), texture_(LoadTexture(""))
{
}

std::shared_ptr<GUIElement> ImageElement::clone() const
{
    std::lock_guard lockGuard(*mutex_);
    return std::make_shared<ImageElement>(*this);
}

void ImageElement::draw()
{
    std::lock_guard lockGuard(*mutex_);
    DrawTexture(texture_,x_,y_,WHITE);
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
