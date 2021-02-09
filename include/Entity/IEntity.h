#pragma once

#include "IComponentInterface.h"
#include "THashSet.h"
#include "ZEntityRef.h"
#include "TDefaultHashSetPolicy.h"

class IEntity : public IComponentInterface
{
public:
    virtual ZEntityRef* GetID(ZEntityRef* result);
    virtual void Activate(ZString*);
    virtual void Deactivate(ZString*);
    virtual void StreamIn();
    virtual void StreamOut();
    virtual bool IsStreamedIn();
    virtual void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>*);
    virtual void OnEnterEditMode();
    virtual void OnExitEditMode();
};