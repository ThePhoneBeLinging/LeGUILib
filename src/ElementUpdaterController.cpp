//
// Created by Elias Aggergaard Larsen on 05/01/2025.
//

#include "ElementUpdaterController.h"

void ElementUpdaterController::markElementAsDirty(int id)
{
    std::lock_guard guard(mutex_);
    dirtyElements_.emplace_back(id);
}

std::list<int> ElementUpdaterController::getDirtyElements()
{
    std::lock_guard guard(mutex_);
    return dirtyElements_;
}
