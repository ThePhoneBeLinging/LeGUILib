//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#ifndef LEGUILIB_H
#define LEGUILIB_H
#include <memory>
#include <vector>

#include "../../GUIElements/GUIElement.h"


class LeGUILib
{
public:
    LeGUILib();
    ~LeGUILib() = default;
    template <typename T>
    std::shared_ptr<T> createElement()
    {
        auto element = std::make_shared<T>();
        std::shared_ptr<GUIElement> guiElement = std::static_pointer_cast<GUIElement>(element);
        guiElement->setID(weakElements_.size());
        guiElement->setElementUpdater(elementUpdater_);
        weakElements_.emplace_back(guiElement);

        return element;
    }
    void launchGUI();
private:
    std::shared_ptr<ElementUpdaterController> elementUpdater_;
    std::vector<std::shared_ptr<GUIElement>> elementsForDrawing_;
    std::vector<std::weak_ptr<GUIElement>> weakElements_;
};



#endif //LEGUILIB_H
