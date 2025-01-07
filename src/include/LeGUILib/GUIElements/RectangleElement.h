//
// Created by eal on 1/7/25.
//

#ifndef RECTANGLEELEMENT_H
#define RECTANGLEELEMENT_H
#include "../GUIElements/GUIElement.h"


class RectangleElement : public GUIElement
{
public:
    RectangleElement();
    [[nodiscard]] RectangleElement* clone() const override;
    ~RectangleElement() override = default;
    void draw() override;
    void setWidth(int width);
    [[nodiscard]] int getWidth() const;
    void setHeight(int height);
    [[nodiscard]] int getHeight() const;
private:
    int width_;
    int height_;
};



#endif //RECTANGLEELEMENT_H
