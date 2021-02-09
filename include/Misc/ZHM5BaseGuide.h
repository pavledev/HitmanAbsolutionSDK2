#pragma once

#include "ZBoundedEntity.h"
#include "eGuideType.h"
#include "SMatrix.h"
#include "SLimits.h"
#include "TArrayRef.h"
#include "ZRayQueryOutput.h"

class alignas(16) ZHM5BaseGuide : public ZBoundedEntity
{
public:
    eGuideType m_eGuideType;
    float4 m_vAABBCen;
    float4 m_vAABBHalfSize;
    __int8 m_bGuideValid : 1;
    __int8 m_bIgnoreTransformCallback : 1;
    __int8 m_bEnabled : 1;

    virtual eGuideType GetGuideType();
    virtual void GeomTransformChangeCallback(const ZEntityRef*, const SMatrix43*);
    virtual bool IsGuideValid();
    virtual bool IsPointOnGuide(const SMatrix*);
    virtual bool IsPointConnectedToGuide(const SMatrix*);
    virtual void RemoveConnection(ZHM5BaseGuide*);
    virtual bool IsMountableFromTop();
    virtual float4* Calc3dPromptPos(float4* result, const float4*);
    virtual SLimits* GetLimits(SLimits* result);
    virtual void Activate_InitSafeZones(const TArrayRef<ZRayQueryOutput>*);
};
