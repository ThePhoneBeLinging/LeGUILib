//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#ifndef TEXT_H
#define TEXT_H
#include <string>

#include "GUIElement.h"


class Text : public GUIElement
{
public:
    Text() = default;
    ~Text() = default;
    void draw() override;
    void setText(const std::string& text);
    const std::string& getText();



private:
    std::string text_;
};



#endif //TEXT_H
