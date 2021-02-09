#pragma once

class IListenerRegistrar
{
public:
    virtual ~IListenerRegistrar();
    virtual void AddPositionListener(void*);
    virtual void RemovePositionListener(void*);
};
