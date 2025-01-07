//
// Created by eal on 1/6/25.
//

#ifndef GUIELEMENT_H
#define GUIELEMENT_H
#include <memory>

#include "raylib.h"
#include "../ElementUpdaterController.h"


class GUIElement
{
public:
    GUIElement();
    explicit GUIElement(GUIElement* guiElement);
    virtual GUIElement* clone() const = 0;
    virtual ~GUIElement() = default;
    virtual void draw() = 0;
    void setID(int id);
    int getID() const;
    void setX(int x);
    int getX() const;
    void setY(int y);
    int getY() const;
    void setZ(int z);
    int getZ() const;
    void setElementUpdater(std::shared_ptr<ElementUpdaterController> elementUpdater);
    void setColor(int red, int green, int blue);
    void setColor(int red, int green, int blue, int alpha);
protected:
    int id_;
    int x_;
    int y_;
    int z_;
    std::shared_ptr<Color> color_;
    std::shared_ptr<ElementUpdaterController> elementUpdater_;
};



#endif //GUIELEMENT_H
