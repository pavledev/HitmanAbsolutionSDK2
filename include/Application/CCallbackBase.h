#pragma once

class CCallbackBase
{
public:
    unsigned __int8 m_nCallbackFlags;
    int m_iCallback;

    enum UnkEnum : __int32
    {
        k_ECallbackFlagsRegistered = 0x1,
        k_ECallbackFlagsGameServer = 0x2
    };

    virtual void Run(void*, bool, unsigned __int64);
    virtual void Run(void*);
    virtual int GetCallbackSizeBytes();
};
