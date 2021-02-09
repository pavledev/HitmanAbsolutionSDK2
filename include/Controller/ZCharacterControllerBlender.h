#pragma once

#include "ZCharacterControllerClip.h"
#include "ESyncEvent.h"

class alignas(4) ZCharacterControllerBlender
{
public:
    ZCharacterControllerClip m_clip0;
    ZCharacterControllerClip m_clip1;
    float m_fBlendWeight;
    ESyncEvent m_syncEventSemantic;
    MR::EventSeqPosition m_syncEventPosition;
    bool m_bBlend;
    bool m_bLoopedOnLastUpdate;
};
