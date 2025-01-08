//
// Created by eal on 07/01/25.
//

#ifndef BUTTONELEMENT_H
#define BUTTONELEMENT_H
#include <functional>
#include <LeGUILib/GUIElements/RectangleElement.h>

#include "GUIElement.h"


class ButtonElement : RectangleElement
{
public:
    ButtonElement() = default;
    [[nodiscard]] ButtonElement* clone() const override;
    ~ButtonElement() override = default;
    void draw() override;
private:
};



#endif //BUTTONELEMENT_H
