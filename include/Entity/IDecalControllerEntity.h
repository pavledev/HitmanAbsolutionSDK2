#pragma once

#include "IComponentInterface.h"
#include "SMatrix.h"

class ZSpatialEntity;
struct SDecalCreationContext;
struct SDecalIntersectionInfo;
template <class T> class TEntityRef;

class __declspec(novtable) IDecalControllerEntity : public IComponentInterface
{
public:
	~IDecalControllerEntity() override = default;
	virtual bool GenerateDecal(const SDecalIntersectionInfo& decalIntersectionInfo, SDecalCreationContext& decalCreationContext, TEntityRef<ZSpatialEntity> entityRef, const SMatrix& matrix) = 0;
	virtual SMatrix GetMatrixFromRotation(const SDecalIntersectionInfo& decalIntersectionInfo, SDecalCreationContext& decalCreationContext) const = 0;

	IDecalControllerEntity() = default;
};
