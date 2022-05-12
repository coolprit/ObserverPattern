#pragma once

#include <vector>
#include "Observer.h"

struct Listener
{
    virtual ~Listener() = default;
    
    void add(Observer& obs);
    
    void remove(Observer& obs);
    
    void emit();

private:
    std::vector<Observer*> observers_;
};