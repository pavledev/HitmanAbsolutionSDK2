#pragma once

class ISharedPointerTarget
{
public:
    virtual ~ISharedPointerTarget();
    virtual void AddReference();
    virtual void RemoveReference();
    virtual unsigned int GetRefCount();
};
