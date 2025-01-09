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
        std::lock_guard guardLock(weakElementsMutex_);
        auto element = std::make_shared<T>();
        std::shared_ptr<GUIElement> guiElement = std::static_pointer_cast<GUIElement>(element);
        guiElement->setID(weakElements_.size());
        guiElement->setElementUpdater(elementUpdater_);
        weakElements_.emplace_back(guiElement);
        elementsForDrawing_.emplace_back(guiElement->clone());

        return element;
    }
    void launchGUI();
private:
    void updateDirtyElements();
    std::shared_ptr<ElementUpdaterController> elementUpdater_;
    std::vector<GUIElement*> elementsForDrawing_;
    std::vector<std::weak_ptr<GUIElement>> weakElements_;
    std::mutex weakElementsMutex_;
};



#endif //LEGUILIB_H
