#pragma once

#include "IComponentInterface.h"

class ZHM5Action;
class ZHM5BaseCharacter;
struct float4;
template <class T> class TEntityRef;

class __declspec(novtable) IHM5ActionEntityListener : public IComponentInterface
{
public:
	~IHM5ActionEntityListener() override = default;
	virtual bool GetActionAABB(const ZHM5Action* pAction, float4& vMin, float4& vMax) const;
	virtual bool IsActionValid(ZHM5Action* action, const TEntityRef<ZHM5BaseCharacter>& entityRef) = 0;
	virtual bool DisplayFarFeedback(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator);
	virtual bool ActivateAction(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator);

	static void RegisterType();
	IHM5ActionEntityListener(const IHM5ActionEntityListener& __that);
	IHM5ActionEntityListener() = default;
	IHM5ActionEntityListener& operator=(const IHM5ActionEntityListener& __that);
};
