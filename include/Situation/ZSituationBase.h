#pragma once

#include "ZEntityImpl.h"
#include "INodeRatingDebug.h"
#include "SSituationInstance.h"
#include "TRefCountPtr.h"
#include "ZGridJobRequest.h"
#include "ZGridFloatField.h"
#include "ESituationJoinReason.h"
#include "ZActorDialog.h"
#include "ZSituationMember.h"

class alignas(8) ZSituationBase : public ZEntityImpl, public INodeRatingDebug
{
public:
    SSituationInstance* m_pInstance;
    int m_nLOSPropagationMemberIndex;
    TRefCountPtr<ZSituationMember> m_pLOSPropagationMember;
    int m_nPropagationMemberIndex;
    TRefCountPtr<ZSituationMember> m_pPropagationMember;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField> > m_propagationRequest;
    ZGameTime m_tPropagationStartTime;
    int m_nNextGroupID;

    virtual bool CanJoin(const TEntityRef<ZActor>*, const ZSharedKnowledgeRef*);
    virtual void OnSituationStarted();
    virtual void OnSituationEnded();
    virtual TRefCountPtr<ZSituationMember>* OnActorJoin(TRefCountPtr<ZSituationMember> * result, const TEntityRef<ZActor>*, const TRefCountPtr<SKnownEntity>*, ESituationJoinReason);
    virtual void OnActorJoined(TRefCountPtrArg<ZSituationMember>, const TRefCountPtr<SKnownEntity>*, ESituationJoinReason);
    virtual void OnActorLeave(TRefCountPtrArg<ZSituationMember>);
    virtual void OnUpdate(const SGameUpdateEvent*);
    virtual void OnOrderClear(TRefCountPtrArg<ZSituationMember>, ZActorDialog::EState);
    virtual bool CanMemberSpeak(TRefCountPtrArg<ZSituationMember>, SActorSoundDefs::EDefinition);
};
