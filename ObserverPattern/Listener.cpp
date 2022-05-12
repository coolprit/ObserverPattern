#include "Listener.h"

void Listener::add(Observer& obs)
{
    observers_.push_back(&obs);
}
    
void Listener::remove(Observer& obs)
{
    observers_.erase(std::remove(observers_.begin(), observers_.end(), &obs));
}
    
void Listener::emit()
{
    for (auto* obs : observers_)
    {
        obs->intercept(*this);
    }
}