#pragma once

#include "IComponentInterface.h"
#include "TEntityRef.h"
#include "ZHitman5.h"

class __declspec(novtable) IHM5ForceMovementCallBack : public IComponentInterface
{
public:
	~IHM5ForceMovementCallBack() override = default;
	virtual void ForceMovement() = 0;
	virtual TEntityRef<ZHitman5> Hitman() const;

	static void RegisterType();
	IHM5ForceMovementCallBack() = default;
};
