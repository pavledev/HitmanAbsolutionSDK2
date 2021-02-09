#pragma once

#include "KeyType.h"
#include "GFxResourceKey.h"

class KeyInterface
{
public:
    virtual ~KeyInterface();
    virtual void AddRef(void*);
    virtual void Release(void*);
    virtual KeyType GetKeyType(void*);
    virtual unsigned int GetHashCode(void*);
    virtual bool KeyEquals(void*, const GFxResourceKey*);
    virtual const char* GetFileURL(void*);
};
