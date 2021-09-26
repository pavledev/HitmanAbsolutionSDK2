#pragma once

#include "IComponentInterface.h"

class ZLinkedEntity;
template <class T> class TEntityRef;

class __declspec(novtable) IBoneWeightManagerEntity : public IComponentInterface
{
public:
	~IBoneWeightManagerEntity() override = default;
	virtual void UpdateBoneWeights(TEntityRef<ZLinkedEntity> entityRef) const = 0;
	virtual void SetBindPoseBonePositions(TEntityRef<ZLinkedEntity> entityRef) const = 0;

	static void RegisterType();
	IBoneWeightManagerEntity() = default;
};
