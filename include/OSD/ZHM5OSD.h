#pragma once

#include "ZEntityImpl.h"
#include "IHM5OSD.h"
#include "TEntityRef.h"
#include "IHM5OSDDisplay.h"
#include "ZResourcePtr.h"
#include "TRefCountPtr.h"
#include "IRenderPrimitiveMesh.h"
#include "ZPrimitiveContainerEntity.h"
#include "SSpriteInfo.h"
#include "SSpriteBuffer.h"
#include "SGameUpdateEvent.h"

class ZHM5OSD : public ZEntityImpl, public IHM5OSD
{
public:
    TArray<TEntityRef<IHM5OSDDisplay>> m_Displays;
    ZEntityRef m_OSDCam;
    ZEntityRef m_PrimitiveContainerEntity;
    ZResourcePtr m_SBMaterial;
    TRefCountPtr<IRenderPrimitiveMesh> m_pSBMesh;
    TEntityRef<ZPrimitiveContainerEntity> m_rPrimCon;
    float m_fScaleX;
    float m_fScaleY;
    float m_fRotation;
    unsigned int m_nColor;
    SSpriteInfo m_aSpriteInfo[12];
    SSpriteBuffer m_SpriteBuffer[2];
    unsigned int m_nBufferIndex;
    bool m_bPrimAdded;
    float m_fAspect;
    unsigned int m_nViewPortWidth;
    unsigned int m_nViewPortHeight;

    virtual void FrameUpdate(const SGameUpdateEvent*);
};
