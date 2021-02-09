#pragma once

class IEnumeratorImpl
{
public:
    virtual void* GetNext(const void*);
    virtual void Release();
    virtual ~IEnumeratorImpl();
};
