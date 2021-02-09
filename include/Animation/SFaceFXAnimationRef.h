#pragma once

#include "TResourcePtr.h"
#include "OC3Ent.h"
#include "ZString.h"

class SFaceFXAnimationRef
{
public:
    TResourcePtr<OC3Ent::Face::FxAnimSet> m_AnimationSetResource;
    ZString m_sAnimationName;
};
