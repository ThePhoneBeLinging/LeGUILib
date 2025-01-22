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
    void draw(int offsetX, int offsetY) override;
    void setText(const std::string& text);
    void setText(int text);
    const std::string& getText();
    void setFontSize(int fontSize);
    int getFontSize();
    /**
     * 
     * @param alignemnt 0 = Left, 1 = middle, 2 = right
     */
    void setAlignment(int alignemnt);
    void setWidth(int width);

private:
    std::string text_;
    int fontSize_;
    int alignment_;
    int width_;
};



#endif //TEXT_H
