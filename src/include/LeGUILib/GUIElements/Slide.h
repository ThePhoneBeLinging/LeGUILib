//
// Created by eal on 10/01/25.
//

#ifndef SLIDE_H
#define SLIDE_H
#include "../GUIElements/GUIElement.h"


class Slide
{
public:
    Slide();
    template <typename T>
    std::shared_ptr<T> createElement()
    {
        std::lock_guard guardLock(weakElementsMutex_);
        auto element = std::make_shared<T>();
        std::shared_ptr<GUIElement> guiElement = std::static_pointer_cast<GUIElement>(element);
        guiElement->setElementUpdater(elementUpdater_);
        guiElement->setID(weakElements_.size());
        weakElements_.emplace_back(guiElement);
        elementsForDrawing_.emplace_back(guiElement->clone());

        return element;
    }
    void updateDirtyElements();
    void draw();
    /**
     *
     * @param x mouseX with offset
     * @param y mouseY with offset
     * @return returns true if an element was clicked, otherwise false.
     */
    void handleClicks(int x, int y) const;

private:

    std::shared_ptr<ElementUpdaterController> elementUpdater_;
    std::vector<std::shared_ptr<GUIElement>> elementsForDrawing_;
    std::vector<std::weak_ptr<GUIElement>> weakElements_;
    std::mutex weakElementsMutex_;
};



#endif //SLIDE_H
