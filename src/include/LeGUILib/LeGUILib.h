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
    std::shared_ptr<Slide> getSlide();
private:
    void updateDirtyElements();
    std::vector<std::shared_ptr<Slide>> slides_;

};



#endif //LEGUILIB_H
