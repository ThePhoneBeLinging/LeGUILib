//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#ifndef TEXT_H
#define TEXT_H
#include <string>

#include "../GUIElements/GUIElement.h"


class Text : public GUIElement
{
public:
    Text() = default;
    Text* clone() const override;
    ~Text() override = default;
    void draw() override;
    void setText(const std::string& text);
    const std::string& getText();
    void setFontSize(int fontSize);
    int getFontSize();


private:
    std::string text_;
    int fontSize_;
};



#endif //TEXT_H
