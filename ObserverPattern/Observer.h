#pragma once

struct Listener;

struct Observer
{
    virtual ~Observer() = default;
    
    virtual void intercept(Listener&) = 0;
};