#pragma once

#include "IComponentInterface.h"
#include "SMatrix.h"
#include "ZCollisionLayerColorGetter.h"

class __declspec(novtable) ICollisionShape : public IComponentInterface
{
public:
	~ICollisionShape() override = default;
	virtual void ApplyLocalTransformation(const SMatrix& matrix) = 0;
	virtual void SetLocalTransformation(const SMatrix& matrix) = 0;
	virtual void GetLocalTransformation(SMatrix& matrix) = 0;
	virtual void DrawShape(const SMatrix& matrix, const ZCollisionLayerColorGetter& collisionLayerColorGetter, ZDebugRender* debugRender, const bool param4) const = 0;
	virtual void DrawSubShape(const unsigned int param1, const SMatrix& matrix, const ZCollisionLayerColorGetter& collisionLayerColorGetter, ZDebugRender* debugRender, const bool param5) const = 0;
	virtual void DrawCCDGeometry(const SMatrix& matrix, ECCDUsage usage, ZDebugRender* debugRender) const = 0;
	virtual bool IsCapsuleShape() const = 0;
	virtual bool CanBeStatic() const = 0;
	virtual bool CanBeDynamic() const = 0;
	virtual unsigned int GetNumSubShapes() const = 0;
	virtual unsigned short GetDefaultCollisionLayer() const = 0;

	ICollisionShape() = default;
};
