//
// Created by Elias Aggergaard Larsen on 05/01/2025.
//

#ifndef ELEMENTUPDATERCONTROLLER_H
#define ELEMENTUPDATERCONTROLLER_H
#include <list>
#include <mutex>


class ElementUpdaterController
{
public:
    ElementUpdaterController() = default;
    void markElementAsDirty(int id);
    std::list<int> getDirtyElements();
private:
    std::mutex mutex_;
    std::list<int> dirtyElements_;
};



#endif //ELEMENTUPDATERCONTROLLER_H
