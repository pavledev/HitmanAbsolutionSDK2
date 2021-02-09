#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZHitman5.h"
#include "ZRuntimeResourceID.h"
#include "ZHM5MaterialDescriptorEntity.h"
#include "SCCEffect.h"

class alignas(4) ZHM5CCEffects : public ZEntityImpl
{
public:
    TEntityRef<ZHitman5> m_pHitman;
    ZRuntimeResourceID m_SlitThroatEmitter;
    ZRuntimeResourceID m_StabEmitter;
    ZRuntimeResourceID m_Blunt1HEmitter;
    ZRuntimeResourceID m_Blunt2HEmitter;
    ZRuntimeResourceID m_Slash1HEmitter;
    ZRuntimeResourceID m_ShatterEmitter;
    ZRuntimeResourceID m_AxeCleaveEmitter;
    ZRuntimeResourceID m_AxePullEmitter;
    ZRuntimeResourceID m_AxePullSlitThroatEmitter;
    ZRuntimeResourceID m_FacePunchEmitter;
    ZRuntimeResourceID m_BloodEmitter;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rSlitThroatDecal;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rStabDecal;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rBlunt1HDecal;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rBlunt2HDecal;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rSlash1HDecal;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rShatterDecal;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rAxeCleaveDecal;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rAxePullsDecal;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rAxePullsSlitThroat;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rFacePunchEmitterDecal;
    TEntityRef<ZHM5MaterialDescriptorEntity> m_rBruise;
    int m_NumSlitThroatEmitters;
    int m_NumStabEmitters;
    int m_NumBlunt1HEmitters;
    int m_NumBlunt2HEmitters;
    int m_NumSlash1HEmitters;
    int m_NumShatter1HEmitters;
    int m_NumAxeCleaveEmitters;
    int m_NumAxePullEmitters;
    int m_NumAxeSlitThroatEmitters;
    int m_NumFacePunchEmitters;
    int m_NumBloodEmitters;
    SCCEffect* m_pEmitters;
    int m_nNumEmitters;
    bool m_bEnabled;

    class Init
    {
    public:
        class __l4
        {
        public:
            class SEmitterNum
            {
            public:
                ZRuntimeResourceID m_rEmitter;
                ECCEmitterEffect m_eEffect;
                int m_nNum;
            };
        };
    };
};
