#pragma once

#include "ZEntityImpl.h"
#include "IParticleRenderEntity.h"
#include "IParticleControllerEntity.h"
#include "SESEntry.h"

class ZParticleRenderEntityBase : ZEntityImpl, IParticleRenderEntity
{
    TArray<IParticleControllerEntity*> m_ParticleControllers;
    TArray<unsigned int> m_nControllerOffsets;
    ParticleRenderListEntry m_JobEntry;
    unsigned int m_nNumParticles;
    char* m_pBuffer;
    unsigned int m_nBufferSize;
    unsigned int m_nSize;
    unsigned int m_nShaderMask;
    unsigned int m_nMaxEmitters;
    unsigned int m_nAllEmitters;
    __int8 m_bSizeDirty : 1;
    __int8 m_bIsStreamedIn : 1;
    TArray<SESEntry> m_ESEntries;
    unsigned int m_nFreeESEntries;

    virtual void OnESEntriesChanged();
};
