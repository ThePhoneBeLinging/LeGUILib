//
// Created by Elias Aggergaard Larsen on 05/01/2025.
//

#include "ElementUpdaterController.h"

void ElementUpdaterController::markElementAsDirty(int id)
{
    std::lock_guard guard(mutex_);
    dirtyElements_.insert(id);
}

std::set<int> ElementUpdaterController::getDirtyElements()
{
    std::lock_guard guard(mutex_);
    auto dirtyElements = dirtyElements_;
    dirtyElements_.clear();
    return dirtyElements;
}
