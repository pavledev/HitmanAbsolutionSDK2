#pragma once

class GSysAllocBase
{
public:
    virtual ~GSysAllocBase();
    virtual bool initHeapEngine(const void*);
    virtual void shutdownHeapEngine();
};
