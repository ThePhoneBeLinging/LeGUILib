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
    void navigateTo(const std::shared_ptr<Slide>& slide);

private:
    std::mutex mutex_;
    std::shared_ptr<Slide> slide_;

};



#endif //LEGUILIB_H
