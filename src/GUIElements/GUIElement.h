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
    void setElementUpdater(std::shared_ptr<ElementUpdaterController> elementUpdater);
protected:
    int id_;
    std::shared_ptr<ElementUpdaterController> elementUpdater_;
};



#endif //GUIELEMENT_H
