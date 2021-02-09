#pragma once

class IRenderRefCount
{
public:
    virtual ~IRenderRefCount();
    virtual void AddRef();
    virtual unsigned int Release();
};
