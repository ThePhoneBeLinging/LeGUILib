//
// Created by Elias Aggergaard Larsen on 05/01/2025.
//

#ifndef ELEMENTUPDATERCONTROLLER_H
#define ELEMENTUPDATERCONTROLLER_H
#include <list>
#include <mutex>
#include <set>


class ElementUpdaterController
{
public:
    ElementUpdaterController() = default;
    void markElementAsDirty(int id);
    std::set<int> getDirtyElements();
private:
    std::mutex mutex_;
    std::set<int> dirtyElements_;
};



#endif //ELEMENTUPDATERCONTROLLER_H
