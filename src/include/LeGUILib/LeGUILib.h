//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#ifndef LEGUILIB_H
#define LEGUILIB_H
#include <memory>
#include <vector>
#include "LeGUILib/GUIElements/Slide.h"

class LeGUILib
{
public:
    LeGUILib();
    ~LeGUILib() = default;

    void launchGUI();
    void addSlide(const std::shared_ptr<Slide>& slide);
    std::shared_ptr<Slide> getSlide(int index);

private:
    std::vector<std::shared_ptr<Slide>> slides_;
    int activeSlideIndex_;

};



#endif //LEGUILIB_H
