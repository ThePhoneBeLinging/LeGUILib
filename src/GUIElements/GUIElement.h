//
// Created by eal on 1/6/25.
//

#ifndef GUIELEMENT_H
#define GUIELEMENT_H
#include <functional>
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
    [[nodiscard]] virtual bool isPointInside(int x, int y) const;
    void onClick() const;
    void setOnClick(std::function<void()> onClick);
    void setElementUpdater(std::shared_ptr<ElementUpdaterController> elementUpdater);
    void setColor(int red, int green, int blue);
    void setColor(int red, int green, int blue, int alpha);
    void lock();
    void unlock();
protected:
    int id_;
    int x_;
    int y_;
    int z_;
    std::shared_ptr<Color> color_;
    std::shared_ptr<ElementUpdaterController> elementUpdater_;
    std::function<void()> onClick_;
    std::unique_lock<std::mutex> lock_;
    std::mutex mutex_;
};



#endif //GUIELEMENT_H
