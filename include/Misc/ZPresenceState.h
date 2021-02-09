#pragma once

class alignas(4) ZPresenceState
{
public:
    unsigned __int8 m_nEntityState;

    enum EntityStateFlags : __int32
    {
        ESF_STREAMED = 0x1,
        ESF_ACTIVATED = 0x2,
        ESF_EDITMODE = 0x4,
    };

    virtual ~ZPresenceState();
    virtual void OnStreamActivateStateChanged();
};
