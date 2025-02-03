//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#ifndef LEGUILIB_H
#define LEGUILIB_H
#include <memory>
#include <vector>
#include <TouchScreenSupport/EventController.h>
#include <TouchScreenSupport/EventListener.h>

#include "LeGUILib/GUIElements/Slide.h"

class LeGUILib
{
public:
    LeGUILib();
    ~LeGUILib() = default;

    void launchGUI();
    void navigateTo(const std::shared_ptr<Slide>& slide);

private:
    std::shared_ptr<Slide> slide_;
    std::unique_ptr<EventListener> eventListener_;
    std::shared_ptr<EventController> eventController_;

};



#endif //LEGUILIB_H
