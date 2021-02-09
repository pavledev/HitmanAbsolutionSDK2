#pragma once

#include "TEntityRef.h"
#include "TMaxArray.h"
#include "ZActorDialog.h"

class ZSituationBase;
class ZSituationMember;

class ZSituationGroup
{
public:
    int m_nRefCount;
    TEntityRef<ZSituationBase> m_rSituation;
    TMaxArray<TRefCountPtr<ZSituationMember>, 8> m_activeMembers;
    STypeID* m_classType;
    int m_nGroupID;

    virtual ~ZSituationGroup();
    virtual void OnMemberActivated(TRefCountPtrArg<ZSituationMember>);
    virtual void OnMemberDeactivated(TRefCountPtrArg<ZSituationMember>);
    virtual void OnOrderClear(TRefCountPtrArg<ZSituationMember>, ZActorDialog::EState);
};
