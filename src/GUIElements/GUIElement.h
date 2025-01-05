//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#ifndef GUIELEMENT_H
#define GUIELEMENT_H
#include "../ElementUpdaterController.h"


class GUIElement
{
public:
    GUIElement() = default;
    virtual ~GUIElement() = 0;
    virtual void draw() = 0;

    [[nodiscard]] int getID() const
    {
        return id_;
    }
    void setID(const int id)
    {
        id_ = id;
    }

    void setElementUpdater(std::shared_ptr<ElementUpdaterController> elementUpdateController)
    {
        elementUpdateController_ = elementUpdateController;
    }

protected:
    int id_{};
    std::shared_ptr<ElementUpdaterController> elementUpdateController_;
};



#endif //GUIELEMENT_H
