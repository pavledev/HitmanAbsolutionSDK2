#pragma once

#include "TArray.h"
#include "TRefCountPtr.h"
#include "IRenderPrimitive.h"

class ZRenderPrimitiveResource
{
public:
    TArray<TRefCountPtr<IRenderPrimitive>> m_Primitives;
    SVector3 m_vMin;
    SVector3 m_vMax;
    ZAnimationBoneData* m_pBoneData;
    bool m_bIsInitialized;
    TResourcePtr<ZAnimationBoneData> m_pBoneDataResourcePtr;

    virtual ~ZRenderPrimitiveResource();
};
