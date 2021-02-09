#pragma once

#include "ZEntityImpl.h"
#include "IBoneAnimator.h"
#include "TResourcePtr.h"
#include "OC3Ent.h"
#include "TEntityRef.h"
#include "EFFXMode.h"
#include "ZGameTime.h"

class alignas(8) ZActorInstanceEntity : public ZEntityImpl, public IBoneAnimator
{
public:
    TResourcePtr<OC3Ent::Face::FxActor> m_ActorResource;
    TEntityRef<IBoneAnimator> m_BoneAnimator;
    ZString m_animationName;
    bool m_bLoop;
    TArray<ZEntityRef> m_AdditionalAnimSets;
    EFFXMode m_eBlendMode;
    OC3Ent::Face::FxActorInstance* m_pActorInstance;
    SBoneAnimatorInfo m_BoneAnimatorInfo;
    int m_nRootBoneIndex;
    int m_nMeshHeadBoneID;
    unsigned int m_nClientEventId;
    TArray<ZEntityRef> m_animSets;
    OC3Ent::Face::FxAnimSet* m_pMediaStreamedAnimSet;
    unsigned int m_nMediaStreamAnimSetID;
    float m_fHeadControlWeight;
    float m_fEyeControlWeight;
    bool m_bAllowHeadControl;
    bool m_bAllowEyeControl;
    bool m_bApplyAnimationAsDeltas;
    ZGameTime m_pauseTime;
    bool m_bPaused;
    TArray<int> m_aFaceFxIDToMeshID;
    unsigned int m_aFxChannelLoopEventInfo[2];
    int m_nCurrentLoopChannel;

    virtual void Initialize();
    virtual void Uninitialize();
};
