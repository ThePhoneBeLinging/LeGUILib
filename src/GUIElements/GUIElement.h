//
// Created by eal on 1/6/25.
//

#ifndef GUIELEMENT_H
#define GUIELEMENT_H
#include <memory>

#include "../ElementUpdaterController.h"


class GUIElement
{
public:
    GUIElement();
    virtual ~GUIElement() = default;
    virtual void draw() = 0;
    void setID(int id);
    int getID() const;
    void setX(int x);
    int getX() const;
    void setY(int y);
    int getY() const;
    void setElementUpdater(std::shared_ptr<ElementUpdaterController> elementUpdater);
protected:
    int id_;
    int x_;
    int y_;
    int z_;
    std::shared_ptr<ElementUpdaterController> elementUpdater_;
};



#endif //GUIELEMENT_H
