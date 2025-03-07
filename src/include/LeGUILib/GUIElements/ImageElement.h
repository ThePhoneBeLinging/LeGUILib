//
// Created by eal on 7/1/25.
//

#ifndef IMAGEELEMENT_H
#define IMAGEELEMENT_H
#include "../GUIElements/GUIElement.h"


class ImageElement : public GUIElement
{
public:
    ImageElement();
    [[nodiscard]] std::shared_ptr<GUIElement> clone() const override;
    void draw() override;
    void loadImage(const std::string& imagePath);
    void setWidth(int width);
    [[nodiscard]] int getWidth() const;
    void setHeight(int height);
    [[nodiscard]] int getHeight() const;
private:
    int width_;
    int height_;
    Texture2D texture_;
};



#endif //IMAGEELEMENT_H
