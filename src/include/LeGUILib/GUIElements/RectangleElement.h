//
// Created by eal on 7/1/25.
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
    void draw(int offsetX, int offsetY) override;
    void setWidth(int width);
    [[nodiscard]] int getWidth() const;
    void setHeight(int height);
    [[nodiscard]] int getHeight() const;
    void setRoundedEdge(double roundness);
    [[nodiscard]] double getRoundedEdge() const;
    bool isPointInside(int x, int y) const override;

private:
    int width_;
    int height_;
    double roundness_;
};



#endif //RECTANGLEELEMENT_H
