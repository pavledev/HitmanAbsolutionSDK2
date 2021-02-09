#pragma once

#include "IComponentInterface.h"
#include "ZHM5Action.h"
#include "ZHM5BaseCharacter.h"

class IHM5ActionEntityListener : public IComponentInterface
{
public:
    virtual bool GetActionAABB(const ZHM5Action* pAction, float4* vMin, float4* vMax);
    virtual bool IsActionValid(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>* pOperator);
    virtual bool DisplayFarFeedback(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>* pOperator);
    virtual bool ActivateAction(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>* pOperator);

    IHM5ActionEntityListener();
    IHM5ActionEntityListener(IHM5ActionEntityListener const&);
    IHM5ActionEntityListener* operator=(IHM5ActionEntityListener const&);
    static void RegisterType();
};